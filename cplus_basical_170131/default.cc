#include <iostream>
using std::cout;
using std::endl;


//函数可以设置默认参数
//默认参数的设置必须要从右到左的顺序进行
//注意:如果有同名函数,要注意避免二义性问题
int add(int x = 1, int y = 0)
{
	return x + y;
}

int add(int x, int y, int z)
{
	return x + y + z;
}


int main(void)
{
	int a = 3, b = 4;
	cout << "a + b = " << add(a, b) << endl;

	cout << add(a) << endl;
	cout << add() << endl;

	return 0;
}
