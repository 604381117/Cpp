 ///
 /// @file    inline.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-02 11:08:38
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#define minus(x,y)  ((x) - (y))

//inline也可以达到带参数的宏定义的效果
inline int add(int x, int y)
{
	return x + y;
}


int main(void)
{
	cout << add(3, 4) << endl;
}
