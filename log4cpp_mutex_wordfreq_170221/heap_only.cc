#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Student{
public:
	Student(int num,const char* name)
	:_num(num)
	,_name(new char[strlen(name) + 1])
	{
		cout<< "init Student()"<< endl;
		strcpy(_name, name);
	}
	
	void Print()
	{
		cout<<"Print()"<<endl;
		cout << "num=" << _num << endl;
		cout << "name=" << _name << endl;
	}
	
	void Destroy()
	{
		cout<<"Destroy()"<<endl;
		delete this;
	}
	void operator delete(void* p)
	{
		cout<<"delete"<<endl;
		free(p);
	}
private:
	~Student()
	{
		cout << "~Student()" << endl;
		delete [] _name;
	}
private:
	int _num;
	char* _name;
};

int main(void)
{
	Student* s=new Student(100,"wangdao");
	s->Print();
	//delete s;
	s->Destroy();
	return 0;
}
