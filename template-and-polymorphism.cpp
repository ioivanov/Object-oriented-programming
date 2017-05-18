#include "stdafx.h"
#include <iostream>
using namespace std;

template<typename T>
void mySwap(T& left, T& right)
{
	T tmp = left;
	left = right;
	right = tmp;
}

void testSwap()
{
	char grade = 'a';
	char universal = 'b';
	mySwap(grade, universal);
	cout << "grade: " << grade << " universal: " << universal << endl;
}

template<typename T>
void myReverse(T *arr, int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		mySwap(arr[i], arr[size - i - 1]);
	}
}

void testReverse()
{
	int arr[] = { 1,2,3,4,5,6 };
	myReverse(arr, 6);
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << " ";
	}
}

template <typename K, typename V>
class MyPair
{
	K key;
	V value;

public:
	MyPair(K, V);
	K getKey();
	V getValue();
	template <typename K, typename V>
	friend ostream& operator<<(ostream&, MyPair<K, V> const&);
};

template <typename K, typename V>
MyPair<K,V>::MyPair(K _key, V _value)//cant use this
{
	key = _key;
	value = _value;
}

template <typename K, typename V>
K MyPair<K, V>::getKey()
{
	return key;
}

template <typename K, typename V>
V MyPair<K, V>::getValue()
{
	return value;
}

template <typename K, typename V>
ostream& operator<<(ostream& os, MyPair<K, V> const& p)
{
	os << "(" << p.key << ", " << p.value << ")" << endl;
	return os;
}

void testMyPair()
{
	MyPair<double, int> p(3.14, 6);
	cout << p;
}

class Shape 
{
protected:
	int width, height;

public:
	Shape(int a = 0, int b = 0) 
	{
		width = a;
		height = b;
	}

	virtual int area() 
	{
		cout << "Parent class area :" << endl;
		return 0;
	}
};

class Rectangle : public Shape 
{
public:
	Rectangle(int a = 0, int b = 0) :Shape(a, b) { }
	int area() 
	{
		cout << "Rectangle class area :" << endl;
		return (width * height);
	}
};

class Triangle : public Shape {
public:
	Triangle(int a = 0, int b = 0) :Shape(a, b) { }
	int area() 
	{
		cout << "Triangle class area :" << endl;
		return (width * height / 2);
	}
};

void testPolymorphism()
{
	Shape *shape;
	Rectangle rec(10, 7);
	Triangle  tri(10, 5);

	shape = &rec;

	shape->area();

	shape = &tri;

	shape->area();
}

int main()
{
	//testSwap();
	//testReverse();
	//testMyPair();
	//testPolymorphism();
    return 0;
}
