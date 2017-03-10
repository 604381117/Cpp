#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

//class Singleton;

template<typename T>
class Singleton{
public:
	static T* getInstance()
	{
		cout<<"static T* getInstance()"<<endl;
		pthread_once(&_once,init);
		return _pInstance;
	}	

	static void init()
	{
		cout<<"static void init()"<<endl;
		_pInstance =new T;
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
	static T* _pInstance;
	static pthread_once_t _once;
};

template<typename T>
T* Singleton<T>::_pInstance=NULL;
template<typename T>
pthread_once_t Singleton<T>::_once=PTHREAD_ONCE_INIT;
int main(void)
{
	int *p1=Singleton<int>::getInstance();
	int *p2=Singleton<int>::getInstance();
	cout<<p1<<"--"<<p2<<endl;
	char *ch1=Singleton<char>::getInstance();
	char *ch2=Singleton<char>::getInstance();
	printf("%p--%p\n",ch1,ch2);
	//cout<<Singleton<Singleton>::getInstance()<<endl;
	return 0;
}

