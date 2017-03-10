#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	int a = 3;
	double c = (double)a;//C的强制转换不一定安全
	double d = double(a);

	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	double e = static_cast<double>(a);
	cout << "e = " << e << endl;

	//const_cast/dynamic_cast/reinterpret_cast

	return 0;
}
