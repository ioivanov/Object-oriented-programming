#include <iostream>
using namespace std;

class Gold {
private:
	
	int numer, denom;
	
	int gcd(int x, int y) {
	if (x <= 0 || y <= 0) {
		return 1;
	}
	while (x != y)
		if (x > y)
			x -= y;
		else
			y -= x;

	return x;
}

public:
	
Gold()
{
	numer=1;
	denom=1;
	}	

Gold(int n, int d) {
	numer=n;
	denom=d;
	if (denom == 0) {
		cout <<"ERROR!1";
		denom = 1;
	}
	if (numer != 0) {
		int g = gcd(numer, denom);
		numer /= g;
		denom /= g;
	}
	else
		denom = 1;
}

Gold(Gold const& r) {
	numer=r.numer;
	denom=r.denom;
}

int getNumerator() const { return numer; }

int getDenominator() const { return denom; }

void print() const {
	cout << getNumerator() << '/' << getDenominator()<<endl;
	}

const Gold& operator=(const Gold& other) {
	if(this != &other){
		numer = other.numer;
		denom = other.denom;
	}
	return *this;
}

Gold operator+(const Gold& q) {
	return Gold(getNumerator() * q.getDenominator()
			        + getDenominator() * q.getNumerator(),
			        
					getDenominator() * q.getDenominator());
}

Gold operator-(const Gold& q) {
	return Gold(getNumerator() * q.getDenominator()
			        - getDenominator() * q.getNumerator(),
					getDenominator() * q.getDenominator());
}

Gold operator*(const Gold& q) {
	return Gold(getNumerator() * q.getNumerator(),
					getDenominator() * q.getDenominator());
}

Gold operator/(const Gold& q) {
	return Gold(getNumerator() * q.getDenominator(),
					getDenominator() * q.getNumerator());
}

operator double() const {
	return (double)numer / (double)denom;
}

friend istream& operator>>(istream& in, Gold& gold) {
 
	in>>gold.numer;
	in>>gold.denom;
  	return in;
}

friend ostream& operator<<(ostream& out, Gold& gold){
	out<<gold.numer<<"/"<<gold.denom<<endl;
	return out;
}

};

int main()
{
	
	Gold result;
	cin>>result;
	cout<<result;

	Gold a(1,2), b(1,3);
	result = a + b;
	result.print();
	
	result = a - b;
	result.print();
	
	result = a * b;
	result.print();
	
	result = a / b;
	result.print();
}
