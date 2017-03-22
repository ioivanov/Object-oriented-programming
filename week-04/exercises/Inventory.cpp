class Rune
{
	int strength;
	int speed;
	int intellect;

public:
	Rune()
	{
		strength = 10;
		speed = 10;
		intellect = 5;
	}

	Rune(int newStrength, int newSpeed, int newIntellect)
	{
		strength = newStrength;
		speed = newSpeed;
		intellect = newIntellect;
	}

	Rune(Rune const& rubbie)
	{
		strength = rubbie.strength;
		speed = rubbie.speed;
		intellect = rubbie.intellect;
	}

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
};

class Inventory
{
	Rune* runes;

public:
	Inventory()
	{
		runes = new Rune[10];
	}

	Inventory(Inventory const& other)
	{
		runes = new Rune[10];
		for (int i = 0; i < 10; i++)
			runes[i] = other.runes[i];
	}

	Inventory& operator=(Inventory const& other)
	{

		if(this!=&other)
			delete runes;

		runes = new Rune[10];
		for (int i = 0; i < 10; i++)
			runes[i] = other.runes[i];

		return *this;
	}

	~Inventory()
	{
		delete[] runes;
	}
};
