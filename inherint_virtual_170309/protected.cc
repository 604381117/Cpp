#include <iostream>
using std::cout;
using std::endl;


class A
{
public:
	A() : _ia(10)
	{}
protected:
	int _ia;
};

class B
: protected A
{
public:
	void print()
	{
		cout << "A::_ia = " << _ia << endl;//_ia的访问权限是protected
	}
};

class C 
: protected B
{
public:
	void show()
	{
		cout << "A::_ia = " << _ia << endl;//_ia的访问权限是protected
	}
};

class D
: protected C
{
public:
	void show()
	{	
		cout << "A::_ia = " << _ia << endl;//_ia的访问权限是protected
	}
};

int main(void)
{
	C c;
	c.show();

	D d;
	d.show();

	return 0;
}
