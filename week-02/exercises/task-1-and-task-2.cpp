#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//Task 1
class Hero
{
	char name[101];
	int health;
	unsigned level; // unsigned int
	unsigned experience;	//unsigned int
	int strength;
	int speed;
	int intellect;

public:

	//Конструктор по подразбиране
	Hero()
	{
		strcpy(name, "");
		health = 10;
		level = 1;
		experience = 0;
		strength = 0;
		speed = 0;
		intellect = 0;
	}

	//Конструктор с аргументи
	Hero(char* _name, int _health, unsigned _level, unsigned _experience,
		int _strength, int _speed, int _intellect)
	{
		strcpy(name, _name);
		health = _health;
		level = _level;
		experience = _experience;
		strength = _strength;
		speed = _speed;
		intellect = _intellect;
	}

	//Конструктор за копиране
	Hero(Hero const& h)
	{
		strcpy(name, h.name);
		health = h.health;
		level = h.level;
		experience = h.experience;
		strength = h.strength;
		speed = h.speed;
		intellect = h.intellect;
	}
 };
 
void testHero()
{
	Hero h; //Default constructor
	h.print();

/*	h.level=10;
 *	cout<<h.name;
 */

	Hero hero("Gandalf", 990, 99, 9899, 10, 1, 256); //Constructor with parameters
	hero.print();

	Hero hero1(hero); // Copy constructor
	hero1.setName("Saruman");
	hero1.print();

	hero1.setLevel(98);
}
 
 //Task 2
void testDynamic1()
{
	int size;
	cout << "Enter size: ";
	cin >> size;

	double *arr = new double[size];
	double avg = 0;

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
		avg += arr[i];
	}
	
	cout << avg / size << endl;
	delete[] arr;
}

void testDynamic2()
{
	int size;
	cout << "Enter size: ";
	cin >> size;

	//Заделяме памет и въвеждаме стойностите
	double **matrix = new double*[size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new double[size];
		for (int j = 0; j < size; j++)
		{
			cin >> matrix[i][j];
		}
	}

	//Транспонираме матрицата
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			double tmp = matrix[j][i];
			matrix[j][i] = matrix[i][j];
			matrix[i][j] = tmp;
		}
	}
	
	//Извеждаме транспонираната матрица
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	
	//Освобождаваме заделената памет
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main()
{
	//testHero();
	//testDynamic1();
	//testDynamic2();
    return 0;
}
