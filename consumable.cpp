#include "stdafx.h"
#include <iostream>
#include "string"
using namespace std;

class Consumable
{
	bool unopened;

public:
	virtual void readLabel() const = 0;
	virtual void consume(int) = 0;
	virtual int quantity() const = 0;
};

class Eatable :Consumable
{
	int weight;
	int pieces;

public:
	Eatable(int _weight, int _pieces) :weight(_weight), pieces(_pieces) {}
	void comsume(int _pieces)
	{
		pieces--;
	}
	int quantity() const
	{
		return pieces;
	}
	void readLabel()
	{
		cout << "Weight per piece: " << weight << endl;
		cout << "Pieces: " << pieces << endl;
	}
};

class Drinkable :Consumable
{
	int volume;

public:
	Drinkable(int _volume) :volume(_volume) {}
	void consume(int quantity)
	{
		if(quantity<=volume)
			volume -= quantity;
	}
	int quantity() const
	{
		return volume;
	}
	void readLabel()
	{
		cout << "Volume: " << volume << endl;
	}
};

class Chocolate :Eatable
{
	double cocoa;
	int rows;
	int cols;

public:
	Chocolate(int weight, int pieces, double _cocoa, int _rows, int _cols)
		:Eatable(weight, pieces), cocoa(_cocoa), rows(_rows), cols(_cols) {}
	void readLabel() 
	{
		cout << "Cocoa: " << cocoa << endl;
		cout << "Rows: " << rows << endl;
		cout << "Cols:" << cocoa << endl;
		((Eatable*)this)->readLabel();
	}
};

class Croissant :Eatable
{
	char filling[101];

public:
	Croissant(int weight, char *_filling)
		:Eatable(weight, 1)
	{
		strcpy(filling, _filling);
	}
	void readLabel() 
	{
		cout << "Filling: " << filling << endl;
		((Eatable*)this)->readLabel();
	}
};

class Beer :Drinkable 
{
	double alcohol;
	char brand[101];

public:
	Beer(int volume, double _alcohol, char* _brand)
		:Drinkable(volume), alcohol(_alcohol)
	{
		strcpy(brand, _brand);
	}
	void readLabel() 
	{
		cout << "Alcohol: " << alcohol << "%" << endl;
		cout << "Brand: " << brand << endl;
		((Drinkable*)this)->readLabel();
	}
};

class MineralWater :Drinkable
{
	int pH;

public:
	MineralWater(int volume, int _pH)
		:Drinkable(volume), pH(_pH) {}
	void readLabel() 
	{
		cout << "PH: " << pH << endl;
		((Drinkable*)this)->readLabel();
	}
};

int main()
{
    return 0;
}
