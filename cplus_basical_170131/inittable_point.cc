#include <iostream>
using std::cout;
using std::endl;

class Point{
public:
	Point(int ix, int iy, double z)
	:_ix(ix)
	,_iy(iy)
	,_ref1(ix)
	,_ref2(z)
	{
		cout << "Point(int int)" << endl; 
	}

	void Print()
	{
		cout << "(" << _ix << "," << _iy << ")" << endl;
		cout << "_ref1=" << _ref1 << "," << "_ref2=" << _ref2 << endl;
	}
	
	~Point()
	{
		cout <<"~Point()"<<endl;
	}
private:
	const int _ix;
	const int _iy;
	int &_ref1;
	double &_ref2;
};

int main(void)
{
	Point p(3,4,78);
	p.Print();
	Point p1=p;
	p1.Print();
	return 0;
}
