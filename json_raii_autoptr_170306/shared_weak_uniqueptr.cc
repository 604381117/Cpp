#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <memory>
#include <fstream>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;
using std::vector;
using std::weak_ptr;
using std::ofstream;

class X{
	public:
		X()
		{
			cout<<"X()"<<endl;
		}
		~X()
		{
			cout<<"~X()"<<endl;
		}

		void fun()
		{
			cout<<"X::fun()"<<endl;
		}
};

class Parent;
class Child{
	public:
		Child()
		{
			cout<<"Child()"<<endl;
		}
		~Child()
		{
			cout<<"~Child()"<<endl;
		}

		weak_ptr<Parent> _parentPtr;//weak_ptr可弱指针
		//shared_ptr<Parent> _parentPtr;
};

class Parent{
	public:
		Parent()
		{
			cout<<"Parent()"<<endl;
		}
		~Parent()
		{
			cout<<"~Parent()"<<endl;
		}
		shared_ptr<Child> _childPtr;
};

unique_ptr<int> getValue()
{
	unique_ptr<int> upi(new int(3));
	return upi;
}

struct Fpcloser{
	void operator()(FILE *fp)
	{
		if(fp)
		{
			fclose(fp);
			cout<<"fclose(fp)"<<endl;
		}
	}
};

struct OfstreamCloser{
	void operator()(ofstream *ofs)
	{
		if(ofs)
		{
			ofs->close();
			cout<<"ofs->close();"<<endl;
		}
	}
};

int main(void)
{
	shared_ptr<int> spi(new int(3));
	cout<<"use count="<<spi.use_count()<<endl;
	cout<<"*spi="<<*spi<<endl;
	cout<<"spi's get()="<<spi.get()<<endl;

	//将只能表达对象语义的对象恢复到能够表达值语义
	//shared_ptr<int> spi2(spi) 中的int本身无值语义，交给shared_ptr后即有
	{
		shared_ptr<int> spi2(spi);
		cout<<"use count="<<spi.use_count()<<endl;
		cout<<"use count="<<spi2.use_count()<<endl;
		cout<<"*spi="<<*spi2<<endl;
		cout<<"spi's get()="<<spi2.get()<<endl;
	}
	cout<<"use count="<<spi.use_count()<<endl<<endl;


	unique_ptr<double> upd(new double(345.4654));
	cout<<"*upd="<<*upd<<endl;
	cout<<"upd's get()="<<upd.get()<<endl;
	//unique_ptr<double> upd2(upd);//不能进行复制或赋值,表达对象语义
	//unique_ptr<double> upd2 = upd ;//不能进行复制或赋值,表达对象语义

	unique_ptr<int> upi = getValue();//会调用移动构造函数,表达的是移动语义
	cout << "*upi = " << *upi << endl;

	vector<unique_ptr<int> > vec;
	vec.push_back(std::move(upi));
	//cout << "*upi = " << *upi << endl;
	cout << "-----" << endl<<endl;

	{
		//sParent先入栈引用计数为1，其次sChild入栈引用计数为1
		shared_ptr<Parent> sParent(new Parent);
		cout<<"sParent's usecount="<<sParent.use_count()<<endl;
		shared_ptr<Child> sChild(new Child);
		cout<<"sChild's usecount="<<sChild.use_count()<<endl;

		sParent->_childPtr=sChild;
		cout<<"sChild's usecount="<<sChild.use_count()<<endl;

		//weak_ptr执行引用计数赋值操作时，引用计数并不加1
		sChild->_parentPtr=sParent;
		cout<<"sParent's usecount="<<sParent.use_count()<<endl;


		weak_ptr<X> p;
		{
			shared_ptr<X> p2(new X);
			cout<<"p's usecount="<<p.use_count()<<endl;
			cout<<"p2's usecount="<<p2.use_count()<<endl;

			p=p2;
			cout<<"p's usecount="<<p.use_count()<<endl;
			cout<<"p2's usecount="<<p2.use_count()<<endl;

			shared_ptr<X> p3=p.lock();//将weak_ptr提升为shared_ptr
			if(p3)
				p3->fun();
			else
				cout<<"X has been destroy!"<<endl;
		}
		cout<<"退出语句块！"<<endl;
		shared_ptr<X> p4=p.lock();
		if(p4)
			p4->fun();
		else
			cout<<"X has been destroy!"<<endl;
	}
	double *a(new double(78967.0908));
	shared_ptr<double> sdPtr(a);
	//shared_ptr<double> sdPtr3(a);//不可以重复托管，否则double free错误
	shared_ptr<double> sdPtr2(sdPtr);
	cout<<"----------"<<endl;
#if 0
	double *b(new double(767.0908));
	unique_ptr<double> udPtr(b);
	unique_ptr<double> udPtr2(b);
#endif
	{
	//shared_ptr<FILE>可以只传入一个类型参数，其内部有delete删除器保证
	shared_ptr<FILE> spFile(fopen("shared_delete.txt","w"),Fpcloser());
	char buf[100]={0};
	strcpy(buf,"wangdao");
	fwrite(buf,1,7,spFile.get());
	
	//unique_ptr<FILE,Fpcloser>必须传入第二个删除器类型
	unique_ptr<FILE,Fpcloser> upFile(fopen("shared_delete.txt","a"),Fpcloser());
	strcpy(buf,"\naaaaaaaaaa");
	fwrite(buf,1,strlen(buf),spFile.get());
	}//若无此大括号，则172行不能采用w方式或w+，否则184行无法写入，后入栈先析构释放
	ofstream ofs("shared_delete.txt",std::ios::app);
	unique_ptr<ofstream,OfstreamCloser> upOfstream(&ofs,OfstreamCloser());
	ofs<<"\nbbbbbbbbbbbbbb";
	return 0;
}
