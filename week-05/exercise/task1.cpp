#include <iostream>
#include <string>
using namespace std;

class Student
{
	char *name;
	double grade;

public:
/*
	//конструктор 1
	Student()
	{
		name = NULL;	// или name = nullptr;
		grade = 2;
	}

	//конструктор 2
	Student(char *name, double grade)
		:this->grade(grade)		//инициализиращ списък работи като this->grade = grade
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
*/

	//конструктор 3 изпълнява ролята на конструктор 1 и контруктор 2
	//приема се за констуктор без аргументи, с един агрумент и с два аргумента
	Student(char *name="anonymus", double grade=2)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->grade = grade;
	}

	//конструнтор за копиране
	//не трием нищо защото обекта още не е създаден т.е. няма какво да трием
	Student(Student const& other) //предаваме other като const& за да не правим излишни копирания
	{
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->grade = other.grade;
	}

	//предефиниране на оператор равно
	//типа на връщане е Student& за да може да се прави student1=student2=student3
	Student& operator=(Student const& other)
	{
		//трябва да се защитим от следната ситуация student1=student1
		if(this!=&other)
		{
			//стандартното изтриване, заделяне и копиране на памет
			delete[] this->name;
			this->name = new char[strlen(other.name) + 1];
			strcpy(this->name, other.name);
			this->grade = other.grade;
		}
		//this е указател *this е референция, какъвто е и типа на втъщане на оператора
		return *this;
	}

	//деструктор
	~Student()
	{
		//използваме delete[] от теоретична гледна точка защото name е масив от елементи а не само един елемент
		//само delete би свършило същата работа
		delete[] name;
	}
};
