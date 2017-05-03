class Hero
{
	char name[101];
	int health;
	unsigned level; // unsigned int
	unsigned experience; //unsigned int
	int strength;
	int speed;
	int intellect;

public:
	
	Hero() //дефолтен конструктор
	{
		strcpy(name, "");
		health = 10;
		level = 1;
		experience = 0;
		strength = 0;
		speed = 0;
		intellect = 0;
	}

	Hero(char* _name, int _health, unsigned _level, unsigned _experience,
		int _strength, int _speed, int _intellect) //конструктор с параметри
	{
		strcpy(name, _name);
		health = _health;
		level = _level;
		experience = _experience;
		strength = _strength;
		speed = _speed;
		intellect = _intellect;
	}

	Hero(Hero const& h) // копи-конструктор
	{
		strcpy(name, h.name);
		health = h.health;
		level = h.level;
		experience = h.experience;
		strength = h.strength;
		speed = h.speed;
		intellect = h.intellect;
}
	
	void init(char* _name, int _health, unsigned _level, unsigned _experience,
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

	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Health: " << health << '/' << level * 10 << endl;
		cout << "Level: " << level << endl;
		cout << "Experience: " << experience << '/' << level * 100 << endl;
		cout << "Strength: " << strength << " Speed: " << speed << " Intellect: " << intellect << endl;
	}

	//сетъри
	void setName(char* _name)
	{
		strcpy(name, _name);
	}

	void setHealth(int _health)
	{
		if (_health >= 0)
			health = _health;
		else
			cout << "Wrong value!" << endl;
	}

	void setLevel(unsigned _level)
	{
		if (_level > level)
			level = _level;
		else
			cout << "Wrong value!" << endl;
	}

	void setExperience(unsigned _experience)
	{
		if (_experience > 0)
			experience = _experience;
		else
			cout << "Wrong value!" << endl;
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

	//гетъри
	const char* getName() const
	{
		return name;
	}

	int getHealth() const
	{
		return health;
	}

	unsigned getLevel() const
	{
		return level;
	}

	unsigned getExperience() const
	{
		return experience;
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

	Hero& operator=(const Hero& other)
	{
		if (this != &other)  // self-assignment проверка
		{
			strcpy(name, other.name);
			health =  other.health;
			level =  other.level;
			experience =  other.experience;
			strength =  other.strength;
			speed =  other.speed;
			intellect =  other.intellect;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Hero& hero) //оператор за изход
	{
		os << "Name: " << hero.name << endl;
		os << "Health: " << hero.health << '/' << hero.level * 10 << endl;
		os << "Level: " << hero.level << endl;
		os << "Experience: " << hero.experience << '/' << hero.level * 100 << endl;
		os << "Strength: " << hero.strength << " Speed: " << hero.speed << " Intellect: " << hero.intellect << endl;
		
		return os;
	}

	friend istream& operator>>(istream& is, Hero& hero)//оператор за вход
	{
   		cout << "Name: ";
   		is.getline (hero.name,100);
		hero.health = 10;
		hero.level = 1;
		hero.experience = 0;
		hero.strength = 0;
		hero.speed = 0;
		hero.intellect = 0;
   
		return is;
	}

};
