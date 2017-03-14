#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//Task 1
/*
struct Hero
{
	char name[101];
	int currentHealth;
	int maxHealth;
	unsigned level; // unsigned int
	unsigned exp;	//unsigned int
	int strength;
	int speed;
	int intellect;
};
*/

//Task 2
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
	
// Сетъри
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

//Гетъри
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
};

int main()
{
	Hero h;
	h.init("Anonymous", 10, 1, 0, 3, 2, 1);
	h.print();
    return 0;
}
