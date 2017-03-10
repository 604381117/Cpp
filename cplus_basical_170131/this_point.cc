#include <iostream>
using std::cout;
using std::endl;

class Point{
public:
	Point(int ix=0, int iy=0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "point(int=0,int=0)" << endl;
	}

	Point(const Point & rhs)
	{
		cout << "Point(const Point & rhs)" << endl;
		_ix=rhs._ix;
		_iy=rhs._iy;
	}

	//隐含的this指针形式，代表当前对象本身
	void Print(/*Point *const this*/)
	{
		cout << "" << this-> _ix << "," << this->_iy << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point pt1(12,3);
	pt1.Print();

	Point pt2=pt1;
	pt2.Print();

	return 0;
}
