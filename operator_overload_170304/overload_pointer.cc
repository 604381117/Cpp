#include <iostream>
using std::cout;
using std::endl;

class Data{
public:
	int length()
	{
		return 5;
	}
};

class DataPtr{
public:
	DataPtr()
	:_p(new Data)
	{}

	~DataPtr()
	{
		delete _p;
	}

//实现跨类输出
	Data * operator->()
	{
		return _p;
	}
private:
	Data *_p;
};

int main(void)
{
	DataPtr dp;
	cout<<dp->length()<<endl;
	cout<<(dp.operator->())->length()<<endl;
}
