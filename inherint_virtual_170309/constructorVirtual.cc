#include <iostream>
using std::cout;
using std::endl;


class Base0
{
public:
	Base0(){	cout << "Base0()" << endl;	}
	~Base0(){	cout << "~Base0()" << endl;	}

	virtual void func1()
	{	cout << "Base0::func1()" << endl;	}	
	virtual void func2()
	{	cout << "Base0::func2()" << endl;	}	
};


class Base1 : public Base0
{
public:
	Base1()
	: Base0()
	{
		cout << "Base1()" << endl;
		func1();
	}

	~Base1()
	{
		func2();
		cout << "~Base1()" << endl;
	}

	void func1()
	{
		cout << "Base1::func1()" << endl;
	}

	void func2()
	{	cout << "Base1::func2()" << endl;	}

};

class Sub : public Base1
{
public:
	Sub()
	: Base1()
	{
		cout << "Sub()" << endl;
	}

	void func1()
	{	cout << "Sub::func1()" << endl;	}

	void func2()
	{	cout << "Sub::func2()" << endl;	}

	~Sub()
	{
		cout << "~Sub()" << endl;
	}
};


int main(void)
{
	Sub sub;

	return 0;
}
