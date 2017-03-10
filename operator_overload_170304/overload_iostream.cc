#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

class AnotherPoint;
class Point{
public:
	Point(int ix,int iy)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point(int,int)"<< endl;
	}
	
	void Print()
	{
		cout<<"("<<_ix<<","<<_iy<<")"<<endl;
	}
	
	operator AnotherPoint();

	//1.只能是成员函数形式
	//2.没有返回值，但是必须采用return语句以传值方式返回一个目标类型变量
	//3.函数无参
	operator int()
	{	
		return _ix;
	}

	operator double()
	{	
		return _ix*_iy;
	}
	friend std::ostream& operator<<(std::ostream & os,const Point & rhs);
private:
	int _ix;
	int _iy;
};

Point::operator AnotherPoint()
{
	return AnotherPoint(_ix,_iy);	
}

std::ostream& operator<<(std::ostream & os,const Point & rhs)
{
	os<<"("<<rhs._ix<<","<<rhs._iy<<")"<<endl;
	return os;
}

int main(void)
{
	Point pt1(1,4);
	Point pt2(7,9);
	cout << pt1<<pt2<<endl;	
	int x=pt2;
	cout<<x<<endl;
	double y;
	cout<<(y=pt1)<<endl;
	return 0;
}
