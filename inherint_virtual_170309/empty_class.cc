 ///
 /// @file    empty.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-11 09:52:39
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//空类还是会占据一个字节的大小，
//目的是为了区分出其创建的对象是
//不同的对象
class Empty
{
public:
	virtual void display()
	{	cout << "Empty::display()" << endl;	}
};

int main(void)
{
	Empty e;//默认构造函数
	Empty e2;
	cout << "sizeof(Empty) = " << sizeof(e) << endl;
	cout << "sizeof(e2) = " << sizeof(e2) << endl;
	cout << &e << endl;
	cout << &e2 << endl;

	e = e2;//赋值运算符函数

	Empty e3(e);//复制构造函数

	Empty * p = new Empty;
	delete p;

	return 0;
}
