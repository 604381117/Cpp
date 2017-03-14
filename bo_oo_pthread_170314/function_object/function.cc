 ///
 /// @file    function.cc
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 11:38:31
 ///
#include <iostream>
#include <functional>
#include <memory>
using std::cout;
using std::endl;
using std::function;
using std::bind;

void printNumber(int num)
{	cout<<num<<" "<<endl;	}

class Foo{
public:
	void printFoo(int num)
	{
		cout<<"printFoo(int)"<<num<<" "<<endl;
	}
};

class Figure{
public:
	Figure(function<void()> cb1, function<double()> cb2)
	:_cb1(cb1)
	 ,_cb2(cb2)
	{ }

	void display()
	{	if(_cb1) _cb1();	}

	double area()
	{	return _cb2 ? _cb2() : 0;	}

	void setCb1(function<void()> cb1)
	{	_cb1 = cb1; }

	void setCb2(function<double()> cb2)
	{	_cb2 = cb2;	}

private:
	function<void()> _cb1;
	function<double()> _cb2;
};

class Rectangle{
public:
	Rectangle(double a,double b)
	:_a(a)
	,_b(b)
	{ }

	void print()
	{	cout<<"矩形";	}

	double calcArea()
	{	return _a * _b;	}

private:
	double _a , _b;
};

class Circle{
public:
	Circle(double radius)
	:_dRadius(radius)
	{ }

	void show()
	{	cout<<"圆形";	}

	double area()
	{	return 3.14159 * _dRadius * _dRadius;	}

private:
	double _dRadius;
};

void func(Figure & fig)
{
	fig.display();
	cout<<"的面积："<<fig.area()<<endl;
}

int main(void)
{
	function<void(int)> f=printNumber;	//function看成一个容器，存放固定标签的函数
	f(23578.9876);
	function<void()> f1=bind(printNumber,67.98);
	f1();
	f1=bind(&Foo::printFoo,Foo(),678.987);
	f1();
	cout<<endl;

	Rectangle rectangle(6.54,87.4);
	Circle circle(7);
	Figure fig(bind(&Rectangle::print, &rectangle),
			   bind(&Rectangle::calcArea, &rectangle));
	func(fig);
	fig.setCb1(bind(&Circle::show, &circle));
	fig.setCb2(bind(&Circle::area, &circle));
	func(fig);
	
	return 0;
}

