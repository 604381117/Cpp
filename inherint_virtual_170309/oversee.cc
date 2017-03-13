 ///
 /// @file    oversee.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-11 10:37:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Base
{
public:
	virtual int func(int x)
	{
		cout << "Base::func(int)" << endl;
		return x;
	}
};

class Sub : public Base
{
public:
	virtual int func(float x)
	{
		cout << "Sub::func(float)" << endl;
		return (int)x;
	}
};

void test(Base & base)
{
	cout << "x = " << base.func(5) << endl;
}

int main(void)
{
	Base base;
	Sub sub;

	test(base);
	test(sub);


	sub.func(5);//Sub::func(float), 隐藏了基类的func(int)


	return 0;
}
