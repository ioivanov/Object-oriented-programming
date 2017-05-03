class Rune
{
	int strength;
	int speed;
	int intellect;

public:
	Rune()//дефолтен конструктор
	{
		strength = 10;
		speed = 10;
		intellect = 5;
	}

	Rune(int newStrength, int newSpeed, int newIntellect)//конструктор с параметри
	{
		strength = newStrength;
		speed = newSpeed;
		intellect = newIntellect;
	}

	Rune(Rune const& rubbie)копи-конструктор
	{
		strength = rubbie.strength;
		speed = rubbie.speed;
		intellect = rubbie.intellect;
	}
	
	//сетъри
	void setStrength(int _strength)
	{
		strength = _strength;
	}

	void setSpeed(int _speed)
	{
		speed = _speed;
	}

	void setIntellect(int _intellect)
	{
		intellect = _intellect;
	}
	
	//гетъри
	int getStrength() const
	{
		return strength;
	}

	int getSpeed() const
	{
		return speed;
	}

	int getIntellect() const
	{
		return intellect;
	}
	
	Rune& operator=(const Rune& other) 
	{
		if (this != &other) // self-assignment проверка
		{ 
			speed=other.speed;
			strength=other.strength;
			intellect=other.intellect;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Rune& rune)//оператор за изход
	{
		os << "Strength: " << rune.strength << " Speed: " << rune.speed << " Intellect: " << rune.intellect << endl;
		return os;
	}

	friend istream& operator>>(istream& is, Rune& rune) // оператор за вход
	{
		cout<<"Strength: ";
   		is>>rune.strength;
   		cout<<"Speed: ";
   		is>>rune.speed;
   		cout<<"Intellect: ";
   		is>>rune.intellect;
		return is;
	}
	
};


class Inventory
{
	Rune* runes;
	int current; //колко точно руни има в момента
	int capacity; //колко е големината на масива runes

	void copy(Inventory const& other)
	{
		current = other.current;
		capacity = other.capacity;

		runes = new Rune[capacity];
		for (int i = 0; i <= current; i++)
			runes[i] = other.runes[i];
	}

	void remove()
	{
		delete[] runes;
	}
  
	void resize()//увеличаваме капацитета на масива от руни, като го правим двойно по-голям
	{
		capacity *= 2;
		Rune *runes2 = new Rune[capacity];
		for (int i = 0; i < capacity; i++)
		{
			runes2[i] = runes[i];
		}
		delete[] runes;
		runes = runes2;
	}

public:
	Inventory()//дефолтен конструктор
	{
		current = -1;
		capacity = 10;
		runes = new Rune[capacity];
	}

	void add(Rune const& rune) // функция за добавяне на руна
	{
		if(current==capacity-1)
		{
			resize();
		}

		current++;
		runes[current] = rune;
	}

	Inventory(Inventory const& other)//копи-конструктор
	{
		copy(other);
	}

	Inventory& operator=(Inventory const& other)
	{

		if (this != &other)
		{
			remove();
			copy(other);
		}

		return *this;
	}

	~Inventory()//деструктор
	{
		remove();
	}
	
	friend ostream& operator<<(ostream& os, const Inventory& inv)// оператор за изход (този път без такъв за вход, защото е безмислено :)
	{
		for(int i=0; i<inv.current; i++) os<<inv.runes[i];
		return os;
	}
};
