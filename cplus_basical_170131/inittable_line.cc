#include <iostream>
using std::cout;
using std::endl;

class Line{
public:
	Line(int x1,int y1,int x2,int y2)
	:_pt1(x1,y1)//类内的对象成员在初始化列表内初始化
	,_pt2(x2,y2)
	{
		cout<<"Line(int ,int ,int ,int)"<<endl;
	}
	
	void Display()
	{
		_pt1.print();
		_pt2.print();
	}
	
	~Line()
	{
		cout << "~Line()" << endl;
	}
prvate:
	Point _pt1;
	Point _pt2;
};

int main(void)
{
	Line l=Line(1,234,5,78);
	Line.Display();
	return 0;
}
