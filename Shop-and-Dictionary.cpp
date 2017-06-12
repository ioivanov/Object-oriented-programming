#include "stdafx.h"
#include <iostream>
#include "string"
using namespace std;

const unsigned NAME_SIZE = 101;
const unsigned SHOP_SIZE = 42;
const unsigned DICT_SIZE = 42;


class Product
{
protected:
	double price;

public:
	virtual bool identify() const = 0;
	virtual void print() const = 0;
	virtual const char* getName() const = 0;

	Product(double _price) :price(_price) {}
	double getPrice() const
	{
		return price;
	}
};

class Tobacco :public Product
{
	char name[NAME_SIZE];
	double nicotine;

public:
	Tobacco(double price, char *_name, double _nicotine)
		:Product(price), nicotine(_nicotine)
	{
		strcpy(name, _name);
	}
	bool identify() const
	{
		return 0;
	}
	void print() const
	{
		cout << "Price: " << price << " Name: " << name << " Nicotine: " << nicotine << endl;
	}
	const char* getName() const
	{
		return name;
	}
	double getNicotine() const
	{
		return nicotine;
	}
};

class Alcohol :public Product
{
	char name[NAME_SIZE];
	double percentige;

public:
	Alcohol(double price, char *_name, double _percentage)
		:Product(price), percentige(_percentage)
	{
		strcpy(name, _name);
	}
	bool identify() const
	{
		return 1;
	}
	void print() const
	{
		cout << "Price: " << price << " Name: " << name << " Percentige: " << percentige << endl;
	}
	const char* getName() const
	{
		return name;
	}
	double getPercentige() const
	{
		return percentige;
	}
};

class Shop
{
	Product *products[SHOP_SIZE];
	int index;

public:
	Shop() :index(-1) {}
	Shop& operator+=(Product *p)
	{
		if (index == SHOP_SIZE - 1)
		{
			cout << "The shop is full!";
		}
		else
		{
			products[++index] = p;
		}
	}
	Shop& operator-=(Product *p)
	{
		if (index == -1)
		{
			cout << "The shop is empty!";
		}
		else
		{
			for (int i = 0; i <= index; i++)
			{
				if (strcmp(products[i]->getName(), p->getName()))
				{
					products[i] = products[index--];
				}
			}
		}
	}
	double income()
	{
		double sum = 0;
		for (int i = 0; i <= index; i++)
		{
			sum += products[i]->getPrice();
		}
		return sum;
	}
	Product* minNicotine() const
	{
		double nic = 100;
		int i;
		for (int j = 0; j <= index; j++)
		{
			if (products[j]->identify() == 1)
			{
				if (((Tobacco*)products[j])->getNicotine() < nic)
					i = j;
			}
		}
		return products[i];
	}
	Product* maxAlcohol()
	{
		double alc = 0;
		int i;
		for (int j = 0; j <= index; j++)
		{
			if (products[j]->identify() == 1)
			{
				if (((Alcohol*)products[j])->getPercentige() > alc)
					i = j;
			}
		}
		return products[i];
	}
};

template <typename K, typename V>
class Pair
{
protected:
	K key;
	V value;

public:
	Pair(K _key = K(), V _value = V())
		:key(_key), value(_value) {}

	bool operator==(Pair const& p)
	{
		return key == p.key&&value == p.value;
	}

	V getValue(K key) const
	{
		return this->key == key ? this->value : V();
	}
};

template <typename K, typename V>
class Dictionary
{
	Pair<K, V> pairs[DICT_SIZE];
	int top;

public:
	Dictionary()
		:top(-1) {}

	void add(Pair<K,V> const& p)
	{
		if (top == DICT_SIZE - 1)
		{
			cout << "Full!";
		}
		else
		{
			pairs[++top] = p;
		}
	}
	void remove(Pair<K, V> const& p)
	{
		for (int i = 0; i <= top; i++)
		{
			pairs[i] == p ? pairs[i] = pairs[top--] : 0;
		}
	}
	V find(K key) const
	{
		for (int i = 0; i <= top; i++)
		{
			if(pairs[i].getValue(key)!=V())
			{
				return pairs[i].getValue(key);
			}
		}
		return V();
	}
};

void testDictionary()
{
	Pair<int, string> p1(1, "First");
	Pair<int, string> p2(2, "Second");
	Pair<int, string> p3(3, "Third");

	Dictionary<int, string> dict;
	dict.add(p1);
	dict.add(p2);
	dict.add(p3);

	cout << dict.find(3);

	dict.remove(p3);

	cout << dict.find(3);
}

int main()
{
   testDictionary();
   return 0;
}
