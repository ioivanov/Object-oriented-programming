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
};

int main()
{
	Hero h;
	h.init("Anonymous", 10, 1, 0, 3, 2, 1);
	h.print();
    return 0;
}
