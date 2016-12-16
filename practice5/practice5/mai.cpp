#include <iostream>
//#ifndef __COMPLEX_H__
#define __COMPLEX_H__
using namespace std;
  //_,-,*,--,==,! »ç¿ë !!

class number
{
private:
	double num1;
	double num2;
	bool limit;

public:
	number(double num1)
	{
		this->num1=num1;
		this->num2=0;
		this->limit=false;
	}
	number(double num1, double num2)
	{	this->num1=num1;
	    this->num2=num2;
		this->limit=false;
	}
	friend ostream& operator<<(ostream& out, const number& n);
	friend number operator+(const number& c1, const number& c2);
	friend number operator-(const number& c1, const number& c2);
	friend number operator*(const number& c1, const number& c2);
	
	number operator--()
	{
		this->num1--;
		this->num2--;
		return *this;
	}
	bool operator== (const number& c)
	{
		return (this->num1==c.num1) &&(this->num2 ==c.num2);
	}
	bool operator!()
	{
		return! (this->num1 || this->num2);
	}
	double getReal()
	{
		return this->num1;
	}
	double getImag()
	{
		return this->num2;
	}
};
number operator+(const number& c1,const number& c2)
	{
		return number(c1.num1 +c2.num1,c1.num2 +c2.num2);
	}
number operator-(const number& c1,const number& c2)
	{
		return number(c1.num1 -c2.num1,c1.num2 -c2.num2);
	}
number operator*(const number& c1,const number& c2)
	{
		return number(c1.num1 *c2.num1,c1.num2 *c2.num2);
	}
ostream& operator<<(ostream& out, const number& n)
{
	//out<<n.num1<<" : "<<n.num2;
	out<<n.num2;
	if(n.limit) out<<"Limited"<<endl;
	else out<<"UnLimited"<<endl;
	return out;
}

void main(void)
{
	
	number c1(1,4);
	number c2(2,5);
	number c3(0);

	cout<<"c1 : "<<c1;
	cout<<"c2 : "<<c2;
	cout<<"c3 : "<<c3;
	cout<<"c1 * c2 : " <<c1*c2;
	c1=c1*c1;
	cout<<"c1 *= c1 : " <<c1;
	cout<<"c1 - c2 : " <<c1-c2;
}