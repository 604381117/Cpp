#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Figure
{
public:
	//作为接口存在
	virtual void display()=0;
	virtual float area()=0;
};

class Rectangle : public Figure
{
public:
	Rectangle(float a, float b)
	: _a(a) , _b(b)
	{
	
	}

	void display()
	{
		cout << "矩形";
	}
	float area()
	{
		return _a * _b;
	}
private:
	float _a;
	float _b;
};

class Circle : public Figure
{
	static const float Pi = 3.14159;
public:
	Circle(float radius)
	: _radius(radius)
	{}
	void display()
	{
		cout << "圆";
	}
	float area()
	{
		return Pi * _radius * _radius; 
	}
private:
	float _radius;
};

class Triangel : public Figure
{
public:
	Triangel(float a, float b, float c)
	: _a(a), _b(b), _c(c)
	{}

	void display()
	{
		cout << "三角形";
	}

	float area()
	{
		float p = (_a + _b + _c) / 2;
		return sqrt(p * (p - _a) * (p - _b) * (p - _c));
	}

private:
	float _a;
	float _b;
	float _c;
};

void print(Figure * fig)
{
	fig->display();
	cout << "的面积:" << fig->area() << endl;
}


int main(void)
{
	Rectangle rectangle(5, 6);
	Circle circle(5);
	Triangel triangle(3, 4, 5);

	print(&rectangle);
	print(&circle);
	print(&triangle);

	return 0;
}
