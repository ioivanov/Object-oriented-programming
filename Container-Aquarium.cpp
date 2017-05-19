#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename M, typename N, typename P> //пишем пред всеки клас и/или функция където се използват шаблони
class Container
{
	M first;
	N second;
	P third;

public:
	Container(M, N, P);

	template <typename M, typename N, typename P> //задължително само за оператор<<
	friend ostream& operator<<(ostream&, Container<M,N,P> const&);
	P getThird(M, N);
};

template <typename M, typename N, typename P>
Container<M, N, P>::Container(M first, N second, P third) // клас Container няма. има само клас Container<M, N, P>
{
	this->first = first;
	this->second = second;
	this->third = third;
}

template <typename M, typename N, typename P>
ostream& operator<<(ostream& os, Container<M,N,P> const& c)
{
	os << c.first << c.second << c.third;
	return os;
}

template <typename M, typename N, typename P>
P Container<M, N, P>::getThird(M first, N second)
{
	if(this->first==first && this->second==second)
	{
		return this->third;
	}
	return P(); // връщане на празен обект от неизвестен тип
}

void testContainer()
{
	Container<int, double, char> c(5, 0.14, '\b');
	cout << c;
}

#include "random" // трябва ни за random функцията
#include <ctime> // също ни трябва за random функцията

class Fish // този клас е интерфейс
{
public:
	virtual bool doFishStuff(int&, int&) = 0; //пример за функция, която въща много неща
	virtual bool isPredator() = 0; // тази функция ще ни казва към какво сочи конкретен указател от тип Fish*
};

class Predator :public Fish
{
	int maxHoursWithoutFood;
	int currentHoursWithoutFood;
public:
	Predator() :currentHoursWithoutFood(0), maxHoursWithoutFood(100) {}

	bool doFishStuff(int& x, int& y) //от върнатия резултат разбираме дали рибата е жива
									//от аргументите, които ще променим, ще разберем на къде иска да ходи рибата
	{
		if (currentHoursWithoutFood == maxHoursWithoutFood) //
			return false;
		currentHoursWithoutFood++;
		x += rand() % 2 - 1; //rand() % 2 генерира цели числа в интервала [0,2] като извадим 1 интервала става [-1,1]
		y += rand() % 2 - 1;
		return true;
	}
	bool isPredator()
	{
		return true;
	}
};

class Prey :public Fish
{
	int maxAge;
	int currentAge;
public:
	Prey() :currentAge(0), maxAge(1000) {}
	bool doFishStuff(int& x, int& y)
	{
		if (currentAge == maxAge)
			return false;
		currentAge++;
		return true;
	}
	bool isPredator()
	{
		return false;
	}
};

class Aquarium
{
	Fish *fishes[100][100]; //статичен двумерен масив от указатели

	void fillWithPredators()
	{
		int numberOfPredators = rand() % 100; // случаен брой хищници по-малък от 100
		cout << numberOfPredators << "Predators" << endl;
		int i = 0;
		while(i<numberOfPredators)
		{
			int x = rand() % 99;
			int y = rand() % 99; //поставяме хищника на случайна позиция
			delete fishes[x][y]; //като премахваме плячката, която е била на тази позиция
			fishes[x][y] = new Predator(); // тук целият хищник е заделен динамично 
										// за повече информация погледни конструктора на аквариум
			i++;
		}
	}

	bool empty() //проверяваме дали аквариума е празен
	{
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (fishes[i][j] != NULL) // ако случайни намерим риба вътре
					return false; //значи не е празен
			}
		}
		return true;
	}

public:
	Aquarium() //запълваме аквариума с плячка
	{
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				fishes[i][j] = new Prey();
				// ако имахме само fishes[i][j] = Prey() т.е. статична плячка то след завършването на цикъла
				// тя ще се изтрие тъй като статичните обекти живеят до края на блока
				// в този случай този конструктор няма да направи нищо
				// fishes[i][j] = new Prey(); на позиция i, j поставяме динамично заделен обект
				// виж деструктора за повече информация по изтриването
			}
		}
		fillWithPredators();
	}

	void simulate() // тази функция е просто логиката на симулирането няма нищо общо с наследяване и полиморфизъм
					// може да не и обръщате внимание за не се объркате
	{
		while (!empty())
		{
			int x, y;
			for (int i = 0; i < 100; i++)
			{
				for (int j = 0; j < 100; j++)
				{
					x = i; y = j;
					if (fishes[i][j] != NULL)
					{
						if (!fishes[i][j]->doFishStuff(x, y))
						{
							cout << fishes[i][j]->isPredator();
							fishes[i][j] = NULL;
						}
						else
						{
							if (x >= 0 && x < 100 && y <= 0 && y < 100 && fishes[x][y] == NULL)
							{
								fishes[x][y] = fishes[i][j];
								fishes[i][j] = NULL;
							}
						}
					}
				}
			}
		}
	}

	~Aquarium()
	{
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				delete fishes[i][j];
			}
		}
		// всяка клетка на аквариума сочи към някаква риба, която е била динамично заделена
		// затова трябва да я изтрием
		// самият аквариум си е статичен затова нямаме delete fishes[i] и delete fishes
	}
};

void testAquarium()
{
	Aquarium fishLand;
	fishLand.simulate();
	// разбира се симулацията не е завършена  до край за да не стане прекалено тромав кода
}

int main()
{
	srand(time(0)); // това нещо ни трябва за да генерира функцията random различни стойности
					// пише се само веднъж в програмата
					// аргумента time идва от библиотеката ctime

	//testContainer();
	//testAquarium();

    return 0;
}
