// ExampleSolution.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "string"
using namespace std;

template <typename T>
class Named
{
protected:
	T data;
	char *name;

public:
	Named()
	{
		data = T();
		name = NULL;
	}
	Named(T _data, char *_name)
	{
		data = _data;
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
	Named(Named const& n)
	{
		data = n.data;
		name = new char[strlen(n.name) + 1];
		strcpy(name, n.name);
	}
	Named& operator=(Named const& n)
	{
		if(this!=&n)
		{
			delete name;

			data = n.data;
			name = new char[strlen(n.name) + 1];
			strcpy(name, n.name);
		}
		return *this;
	}
	~Named()
	{
		delete name;
	}

	template <typename T>
	friend ostream& operator<<(ostream&, Named<T> const&);
	template <typename T>
	friend istream& operator>>(istream&, Named<T> const&);

};

template <typename T>
ostream& operator<<(ostream& os, Named<T> const& n)
{
	os << "Name: " << n.name;
	os << "Data: " << n.data;
	return os;
}

template <typename T>
istream& operator<<(istream& is, Named<T> const& n)
{
	is << "Name: " << n.name;
	is << "Data: " << n.data;
	return is;
}

void testNamed()
{
	Named<int> n(10, "myVariable");
	Named<int> v = n;
	cout << v;
}

template <typename T>
class Variable :public Named<T>
{
public:
	Variable(T data, char *name) :Named(data,name) {}
	T operator*()
	{
		return data;
	}
	void operator=(Variable const& v)
	{
		data = v.data;
	}
	bool operator==(Variable const& v)
	{
		if (data == v.data && strcmp(name, v.name) == 0)
			return true;
		return false;
	}
	bool operator!=(Variable const& v)
	{
		return !operator==(v);
	}

};

void testVariable()
{
	Variable<double> v(3.14, "v");
	cout << v << endl;
	cout << *v << endl;

	Variable<double> var(1.7, "var");
	cout << var << endl;
	cout << *var << endl;

	v = var;
	cout << v << endl;

}

int main()
{
	//testNamed();
	//testVariable();
    return 0;
}

