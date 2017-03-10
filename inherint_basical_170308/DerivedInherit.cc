#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	void print()
	{
		cout << "A::print()" << endl;
	}
};

class B
{
public:
	void print()
	{
		cout << "B::print()" << endl;
	}
};


class C
: public A
, public B
{
public:
	void display()
	{
		cout << "C::display()" << endl;
	}
};

int main(void)
{
	C c;
	//c.print();//Error,会产生二义性
	c.A::print();//使用类作用域解决二义性
	c.B::print();
	c.display();
}


