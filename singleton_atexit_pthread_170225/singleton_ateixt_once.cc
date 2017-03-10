#include <pthread.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton{
public:
	static Singleton* getInstance()
	{
		cout<<"static Singleton* getInstance()"<<endl;
		pthread_once(&_once,init);
		return _pInstance;
	}	

	static void init()
	{
		cout<<"static void init()"<<endl;
		_pInstance =new Singleton;
		atexit(destroy);
	}

	static void destroy()
	{
		cout<<"static void destroy()"<<endl;
		if(_pInstance)
			delete _pInstance;
	}

	void Print()
	{
		cout<<"void Print()"<<endl;
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
	static pthread_once_t _once;
};

Singleton* Singleton::_pInstance=NULL;
pthread_once_t Singleton::_once=PTHREAD_ONCE_INIT;

int main(void)
{
	cout<<Singleton::getInstance()<<endl;
	Singleton::getInstance()->Print();
	Singleton *p1=Singleton::getInstance();
	Singleton *p2=Singleton::getInstance();
	cout<<p1<<"--"<<p2<<endl;
	return 0;
}

