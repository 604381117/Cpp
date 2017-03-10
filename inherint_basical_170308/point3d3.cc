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
		cout << "Point(int,int)" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

	void print()
	{	cout << "(" << _ix
		     << "," << _iy
			 << ")" << endl;
	}

	int getX() const
	{	return _ix;	}


protected:
	int getY() const
	{	return _iy;	}
private:
	int _ix;
	int _iy;
};


class Point3D
: protected Point //protected 继承
{
public:
	Point3D(int ix, int iy, int iz)
	: Point(ix, iy)
	, _iz(iz)
	{
		cout << "Point3D(int,int,int)" << endl;
	}

	~Point3D()
	{
		cout << "~Point3D()" << endl;
	}

	void display()
	{
		cout << getX() ;     //基类的public成员能在派生类中直接访问, 表现为protected
		cout << "(" << _ix    //基类的private成员是不能在派生类中直接访问
			 << "," << getY() //基类的protected成员能在派生类中直接访问, 表现为protected
			 << "," << _iz
			 << ")" << endl;
	}
private:
	int _iz;
};

int main(void)
{
	Point3D p3D(1, 2, 3);

	cout << "x = " << p3D.getX() << endl;//基类的所有成员不能进行访问
	cout << "y = " << p3D.getY() << endl;
	p3D.print();

	Point pt(1,2);
	//pt.getY();//对于protected修饰的成员不能在类之外进行访问

	return 0;
}
