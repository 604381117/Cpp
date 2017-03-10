#include <iostream>
using std::cout;
using std::endl;



class A
{
public:
	virtual void a()
	{	cout << "A::a()" << endl;	}

	virtual void b()
	{	cout << "A::b()" << endl;	}

	virtual void c()
	{	cout << "A::c()" << endl;	}
};

class B
{
public:
	virtual void a()
	{	cout << "B::a()" << endl;	}

	virtual void b()
	{	cout << "B::b()" << endl;	}

	void c()
	{	cout << "B::c()" << endl;	}

	void d()
	{	cout << "B::d()" << endl;	}
};


class C
: public A, public B
{
public:
	virtual void a()
	{	cout << "C::a()" << endl;	}

	void c()
	{	cout << "C::c()" << endl;	}

	void d()
	{	cout << "C::d()" << endl;	}
};

int main(void)
{
	A a;
	B b;
	C c;

	cout << "sizeof(a) = " << sizeof(a) << endl;
	cout << "sizeof(b) = " << sizeof(b) << endl;
	cout << "sizeof(c) = " << sizeof(c) << endl;

	//c.b();//Error, 二义性
	c.A::b();
	c.B::b();

	cout << endl;

	A * pA = &c;
	pA->a();
	pA->b();
	pA->c();
	cout << pA << endl;
	cout << endl;

	B * pB = &c;
	pB->a();
	pB->b();
	pB->c();
	pB->d();
	cout << pB << endl;
	cout << endl;


	C * pC = &c;
	pC->a();
	//pC->b();//Error,二义性
	pC->A::b();
	pC->B::b();
	pC->c();
	pC->d();




	
	
	return 0;
}
