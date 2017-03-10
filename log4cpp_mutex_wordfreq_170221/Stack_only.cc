#include <string.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Student{
public:
	Student(int num,const char* name)
	:_num(num)
	,_name(new char[strlen(name)+1])
	{
		cout<<"Student()"<<endl;
		strcpy(_name,name);
	}
	
	void Print()
	{
		cout<<"Print()"<<endl;
		cout<< "num="<< _num<< endl;
		cout<< "name="<< _name<< endl;
	}
	
	~Student()
	{
		cout<< "~Student()"<<endl;
		delete []_name;
	}
private:
	void* operator new(size_t size)
	{
		cout<<"new"<<endl;
		void* p=(Student*)malloc(size);
		return p;
	}	
	void operator delete(void* p)
	{
		cout<<"delete"<<endl;
		free(p);
	}
private:
	int _num;
	char *_name;
};

int main(void)
{
	Student s(101,"Jackie");//调用构造函数和析构函数
	s.Print();
	//Student * s1 = new Student(100, "Mike");
	return 0;
}
