#include <iostream>
using std::cout;
using std::endl;

class Singleton{
public:
	static Singleton* getInstance()
	{
		cout<<"static Singleton* getInstance()"<<endl;
		if(!_pInstance)
			_pInstance =new Singleton;
		return _pInstance;
	}

	void Print()
	{
		cout<<"void Print()"<<endl;
	}

private:
	class Autorelease{
	public:
		Autorelease()
		{
			cout<<"Autorelease()"<<endl;
		}
		
		~Autorelease()
		{
			cout<<"~Autorealse()"<<endl;
			if(_pInstance)
				delete _pInstance;
		}
	};
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
	static Autorelease ar;
};

Singleton* Singleton::_pInstance=Singleton::getInstance();
Singleton::Autorelease Singleton::ar;

int main(void)
{
	cout<<Singleton::getInstance()<<endl;
	Singleton::getInstance()->Print();
	Singleton *p1=Singleton::getInstance();
	Singleton *p2=Singleton::getInstance();
	cout<<p1<<"--"<<p2<<endl;
	return 0;
}

