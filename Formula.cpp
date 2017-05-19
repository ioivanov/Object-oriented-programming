#include "stdafx.h"
#include <iostream>
using namespace std;

class Formula
{
public:
	virtual double value() const = 0;
	virtual void print() const = 0;
	virtual void clear() = 0;
};

class Constant :public Formula
{
	int val;

public:
	Constant(int val)
	{
		this->val = val;
	}
	double value() const
	{
		return (double)val;
	}
	void print() const
	{
		cout << val;
	}
	void clear()
	{
		
	}
};

class BinaryOperation :public Formula
{
	Formula* leftArgument;
	Formula* rightArgument;
	char operation;

	void clear()
	{
		leftArgument->clear();
		rightArgument->clear();
		delete leftArgument;
		delete rightArgument;
	}
public:
	BinaryOperation(Formula* larg, Formula* rarg, char op)
	{
		leftArgument = larg;
		rightArgument = rarg;
		operation = op;
	}

	double value() const
	{
		switch(operation)
		{
		case '+': return leftArgument->value() + rightArgument->value();
		case '-': return leftArgument->value() - rightArgument->value();
		case '*': return leftArgument->value() * rightArgument->value();
		case '/': return leftArgument->value() / rightArgument->value();
		}
		return 0;
	}
	void print() const
	{
		cout << "(";
		leftArgument->print();
		cout << " " << operation << " ";
		rightArgument->print();
		cout << ")";
	}
};

Formula* readFormula(char *expr, int length, int &i)
{

	if (i >= length)
		return NULL;
	else if (expr[i] >= '0'&&expr[i] <= '9')
	{
		i++;
		return new Constant(expr[i-1] - '0');
	}
	else if(expr[i]=='(')
	{
		i++;
		Formula* larg = readFormula(expr, length, i);
		char op = expr[i];
		i++;
		Formula* rarg = readFormula(expr, length, i);
		i++;
		return new BinaryOperation(larg, rarg, op);
	}
	return NULL;
}

int main()
{

	Formula *f;
	int i = 0;
	char *str = "(((1+2)*3)*(6+7))";
	f = readFormula(str, strlen(str), i);
	f->print();
	cout << endl << f->value();
	f->clear();
	delete f;
	return 0;
}
