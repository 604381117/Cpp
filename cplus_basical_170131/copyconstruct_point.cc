#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	explicit
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int = 0, int = 0)" << endl;
	}

	//如果不显式复制构造函数,系统会自动生成一个
	//复制构造函数的参数不能是对象的形式,否则会
	//导致复制构造函数的无穷递归，最终导致栈溢出
	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point &)" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};

//当实参和形参都是对象，进行形参和实参的结合时
void func(Point pt)
{//初始化形参的过程 Point pt = pt2
	pt.print();
}

int getInt()
{
	int a = 1;
	return a;
}

//编译器的优化技术:RVO
//去RVO的编译选项: -fno-elide-constructors
Point getPoint()
{
	Point pt(3, 4);
	pt.print();
	return pt;
}


int test(void)
{
	Point p;
	Point pt1(1, 2);//有名对象
	pt1.print();

	//Point pt2 = pt1;
	Point pt2(pt1);//调用复制构造函数
	pt2.print();
	func(pt2);

	cout << endl;
	Point pt3 = getPoint();//匿名对象 --> 右值
	pt3.print();

	//Point pt4();//函数的声明，并不是创建了一个对象

#if 0

	int a = 10;
	int & refa = a;

	const int & ref = 10;
#endif

	return 0;
}

int main(void)
{
	Point pt = 1;//发生了隐式转换 --> 禁止隐式转换,需要关键字explicit
	pt.print();
	return 0;
}
