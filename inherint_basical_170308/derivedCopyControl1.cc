#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class Base
{
public:
	Base(const char * pdata)
	: _pdata(new char[strlen(pdata) + 1])
	{
		strcpy(_pdata, pdata);
	}

	Base(const Base & rhs)
	: _pdata(new char[strlen(rhs._pdata) + 1])
	{
		cout << "Base(const Base&)" << endl;
		strcpy(_pdata, rhs._pdata);
	}

	Base & operator=(const Base & rhs)
	{
		cout << "Base & operator=(const Base &)" << endl;
		if(this != &rhs)
		{
			delete [] _pdata;
			_pdata = new char[strlen(rhs._pdata) + 1];
			strcpy(_pdata, rhs._pdata);
		}
		return *this;
	}


	~Base()
	{
		delete [] _pdata;
	}

	friend std::ostream & operator<<(std::ostream &os, const Base& rhs);
private:
	char * _pdata;
};


//当派生类没有定义复制控制函数，而基类有定义复制控制函数时,
//且进行派生类对象的复制操作时，派生类部分执行缺省行为，
//基类部分会自动调用基类的复制控制函数
class Derived
: public Base
{
public:
	Derived(const char * pdata)
	: Base(pdata)
	{
		cout << "Derived(const char *)" << endl;
	}
	
	friend std::ostream & operator<<(std::ostream &os, const Derived & rhs);
};

std::ostream & operator<<(std::ostream &os, const Base& rhs)
{
	os << rhs._pdata;
	return os;
}

std::ostream & operator<<(std::ostream &os, const Derived & rhs)
{
	os << (Base)rhs;
	return os;
}
int main(void)
{
	Derived d1("hello");
	cout << "d1 = " << d1 << endl;

	Derived d2 = d1;
	cout << "d2 = " << d2 << endl;
	cout << endl;

	Derived d3(",world");
	cout << "d3 = " << d3 << endl;
	
	d3 = d1;
	cout << "d3 = " << d3 << endl;

	return 0;
}
