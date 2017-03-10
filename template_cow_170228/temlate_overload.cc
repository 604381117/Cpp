#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

template <typename T>//函数模板，代码生成器
T add(T x,T y)
{
	return x+y;
}

template<>
const char* add(const char* x,const char *y)
{
	char *temp=new char(strlen(x)+strlen(y)+1);
	strcpy(temp,x);
	strcat(temp,y);
	return temp;
}

//函数模板与普通函数可重载，且普通函数的执行优先于函数模板
int add(int x,int y)//模板函数
{
	return x+y;
}

double add(double x,double y)
{
	return x+y;
}

class Point{
public:
	Point(int ix,int iy)
	:_ix(ix)
	,_iy(iy)
	{}
	
	friend std::ostream &operator<<(std::ostream &os,const Point &rhs);
	friend Point operator+(const Point &lhs,const Point &rhs);

private:
	int _ix,_iy;
};

Point operator+(const Point &lhs,const Point &rhs)
{
	return Point(lhs._ix+rhs._ix,lhs._iy+rhs._iy);
}

std::ostream &operator<<(std::ostream &os,const Point &rhs)
{
	os<<"("<<rhs._ix<<","<<rhs._iy<<")"<<endl;
	return os;
}

//template的模板参数中的非类型参数只能是int
//必须在显示实例化时给出
template<typename T,int num>
T fun(T a)
{
	return a*num;
}

int main(void)
{
	int a=3,b=4;
	cout<<"a+b="<<add(a,b)<<endl;//模板参数推导

	double x=3.0,y=4.44;
	cout<<"x+y="<<add(x,y)<<endl;
	cout<<"x+y="<<add<double>(x,y)<<endl;//模板参数的显式实例化
	cout<<fun<int,4>(100)<<endl;
	const char *p1="aaaaaa";
	const char *p2="bbbbbbbb";
	cout<<add(p1,p2)<<endl;
	cout<<add<const char*>(p1,p2)<<endl;
	cout<<add(p1,p2)<<endl;
	return 0;
}
