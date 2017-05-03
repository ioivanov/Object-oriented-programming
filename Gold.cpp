class Gold {
private:
	
	int numer, denom; //голда ще бъден представен като рационално число
	
	int gcd(int x, int y) 
	{
		if (x <= 0 || y <= 0) 
		{
			return 1;
		}
		while (x != y)
		{
			if (x > y)
				x -= y;
			else
				y -= x;
		}
		return x;
	}

public:
	
	Gold()
	{
		numer=1;
		denom=1;
	}	

	Gold(int n, int d) 
	{
		numer=n;
		denom=d;
		if (denom == 0) //не може да имаме знаменател 0
		{
			cout <<"ERROR!";
			denom = 1;
		}	
		if (numer != 0) 
		{
			int g = gcd(numer, denom);
			numer /= g;
			denom /= g;
		}
		else // ако числителя е 0 ще представяме дробта като 0/1
			denom = 1;
	}

	Gold(Gold const& r) 
	{
		numer=r.numer;
		denom=r.denom;
	}

	//гетъри
	int getNumerator() const { return numer; }

	int getDenominator() const { return denom; }

	void print() const 
	{
		cout << getNumerator() << '/' << getDenominator()<<endl;
	}

	//От тук нататък предефинираме почти всички оператори на света...
	const Gold& operator=(const Gold& other) 
	{
		if(this != &other)
		{
			numer = other.numer;
			denom = other.denom;
		}
		return *this;
	}

	Gold operator+(const Gold& q) 
	{
		return Gold(getNumerator() * q.getDenominator()+ getDenominator() * q.getNumerator(),
								getDenominator() * q.getDenominator());
	}

	Gold operator-(const Gold& q) 
	{
		return Gold(getNumerator() * q.getDenominator()- getDenominator() * q.getNumerator(),
						getDenominator() * q.getDenominator());
	}

	Gold operator*(const Gold& q) 
	{
		return Gold(getNumerator() * q.getNumerator(),
						getDenominator() * q.getDenominator());
	}

	Gold operator/(const Gold& q) 
	{
		return Gold(getNumerator() * q.getDenominator(),
						getDenominator() * q.getNumerator());
	}

	operator double() const 
	{
		return (double)numer / (double)denom;
	}

	friend istream& operator>>(istream& in, Gold& gold) 
	{
		in>>gold.numer;
		in>>gold.denom;
		return in;
	}

	friend ostream& operator<<(ostream& out,const Gold& gold)
	{
		out<<gold.numer<<"/"<<gold.denom<<endl;
		return out;
	}

	bool operator==(Gold& rgold) const
	{
		return (numer==rgold.numer && denom==rgold.denom);
	}

	bool operator>(Gold& rgold) const
	{
		Gold helper;
		helper=rgold;
		helper= helper-*this;
		return (helper.numer<0);
	}

	bool operator>=(Gold& rgold) const
	{
		Gold helper;
		helper=rgold;
		helper= helper-*this;
		return (helper.numer<=0);
	}

	bool operator<(Gold& rgold) const
	{
		return (rgold>=*this);
	}

	bool operator<=(Gold& rgold) const
	{
		return (rgold>*this);
	}

	const Gold& operator+=(const Gold& rgold) 
	{	
		*this=*this+rgold;
		return *this;
	}

	const Gold& operator-=(const Gold& rgold) 
	{	
		*this=*this-rgold;
		return *this;
	}

	const Gold& operator*=(const Gold& rgold) 
	{	
		*this=*this*rgold;
		return *this;
	}

	const Gold& operator/=(const Gold& rgold) 
	{	
		*this=*this/rgold;
		return *this;
	}

};
