#include <iostream>
using std::cout;
using std::endl;

class A{
public:
protected:
	int _ia=1000;
};


class B:public A
{
public:
	void print()
	{
		cout<<"A::_ia="<<_ia<<endl;
	}
};

class C
:public B
{
public:
	void show()
	{
		cout<<"A::_ia="<<_ia<<endl;
	}
};

class D
:public C
{
public:
	void show()
	{
		cout<<"A::_ia="<<_ia<<endl;	
		
	}
};

int main()
{
	B b;
	cout<<"b.print()=";
	b.print();
	C c;
	cout<<"c.print()=";
	c.show();
	D d;
	cout<<"d.show()=";
	d.show();
}
