#include <iostream>
using std::cout;
using std::endl;

template<typename T1,typename T2>
class Convert{
public:
	T2 execute(T1 data)
	{
		return T2(data);
	}
};

template <typename T1>
class Convert{
public:
	template<typename T2>
	T2 execute(T1 data)
	{
		return T2(data);
	}
};

int main(void)
{
		

}
