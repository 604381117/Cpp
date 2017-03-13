 ///
 /// @file    virtualInherit1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-11 11:11:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class A
{
public:
	A(double ia) : _ia(ia) {}

	virtual void display()
	{
		cout << "A::display()" << endl;
	}
private:
	double _ia;
};

//1.如果是采用虚继承，其对象布局之中又会多一个虚基指针
//该虚基指针指向的是虚基类的子对象
//2.虚基类子对象位于派生类对象布局的末尾
//3.如果派生类没有新定义自己的虚函数， 此时其存储布局
//不会再其开始添加一个虚函数指针
//4.如果派生类有新定义自己的虚函数，则会其存储布局中的
//开始位置再添加一个虚函数指针
//5.对于GCC的编译器而言， 它会将虚函数指针和虚基指针合并
// 就是虚函数表与虚基表合并
class B : virtual public A
{
public:
	B(double ia, double ib) : A(ia), _ib(ib){}

	virtual void print()
	{
		cout << "B::print()" << endl;
	}

private:
	double _ib;
};

int main(void)
{
	cout << "sizeof(A) = " << sizeof(A) << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;

	return 0;
}
