 ///
 /// @file    Point3D.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-08 11:35:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
	//	cout << "Point(int,int)" << endl;
	}

	~Point()
	{
	//	cout << "~Point()" << endl;
	}

	//Point & operator=(const Point & rhs);


	void display()
	{	cout << "(" << _ix
		     << "," << _iy
			 << ")" << endl;
	}

	int getX() const
	{	return _ix;	}

	int getY() const
	{	return _iy;	}

private:
	int _ix;
	int _iy;
};



//继承关系表达的是is A 的关系
class Point3D
: public Point
{
public:
	Point3D(int ix, int iy, int iz)
	: Point(ix, iy)
	, _iz(iz)
	{
	//	cout << "Point3D(int,int,int)" << endl;
	}

	~Point3D()
	{
	//	cout << "~Point3D()" << endl;
	}

	//Point3D & operator=(const Point3D & rhs);

	void display()
	{
		cout << "(" << getX()
			 << "," << getY()
			 << "," << _iz
			 << ")" << endl;
	}


private:
	int _iz;
};

int main(void)
{
	cout << "sizeof(Point) = " << sizeof(Point) << endl;
	cout << "sizeof(Point3D) = " << sizeof(Point3D) << endl;
	Point pt1(1, 2);
	
	pt1.display();
	Point3D pt2(3, 4, 5);
	pt2.display();

	pt1 = pt2;//调用赋值运算符函数, 可以把派生类对象赋值给基类的引用
	pt1.display();//
	cout << endl;

//	pt2 = pt1;//调用赋值运算符函数, Error

	Point * p = &pt2;
	p->display();

	//Point3D * p2 = &pt1;
	p//2->display();

	return 0;
}
