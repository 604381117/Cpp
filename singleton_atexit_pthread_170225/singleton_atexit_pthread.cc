#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton{
public:
	static Singleton* getInstance()
	{
		cout<<"static Singleton* getInstance()"<<endl;
		if(!_pInstance)
		{
			_pInstance =new Singleton;
			atexit(destroy);
		}
		return _pInstance;
	}

	static void destroy()
	{
		cout<<"static void destroy()"<<endl;
		if(_pInstance)
			delete _pInstance;
	}

private:
	Singleton()
	{
		cout<<"Singleton()"<<endl;
	}

	~Singleton()
	{
		cout<<"~Singleton()"<<endl;
	}
private:
	static Singleton* _pInstance;	
};

Singleton* Singleton::_pInstance=getInstance();

int main(void)
{
	Singleton *p1=Singleton::getInstance();
	Singleton *p2=Singleton::getInstance();
	cout<<p1<<"--"<<p2<<endl;
	return 0;
}

