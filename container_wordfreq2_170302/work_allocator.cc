#include <vector>
#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

template<typename T>
class Vector{
public:
	Vector();
	~Vector();
	void push_back(const T &);
	void pop_back();
	int size()const;
	int capacity()const;
	T &operator[](int idx)
	{
		return *(_begin+idx);
	}
	
private:
	void reallocate();
private:
	static std::allocator<T> _alloc;
	T* _begin;
	T* _end;
	T* _first_free;
};

template<typename T>
std::allocator<T> Vector<T>:: _alloc;

//内存空间的申请与对象的创建是分开的
//对象的销毁与空间的回收相分开
//new/delete则是合二为一，先operator new接着调用构造函数初始化
template<typename T>
Vector<T>::Vector()
:_begin(0)//or NULL
,_end(0)
,_first_free(0)
{}

template<typename T>
Vector<T>::~Vector()
{
	while(_begin!=_first_free)
		_alloc.destroy(--_first_free);
	_alloc.deallocate(_begin,capacity());
}	

template<typename T>
void Vector<T>::pop_back()
{
	if(_first_free!=_begin)	
		_alloc.destroy(--_first_free);
}

template<typename T>
void Vector<T>::push_back(const T & vec)
{
	if(_first_free==_end)
		reallocate();
	_alloc.construct(_first_free++,vec);
}

template<typename T>
int Vector<T>::size()const
{
	return _first_free-_begin;
}

template<typename T>
int Vector<T>::capacity()const
{
	return _end-_begin;
}

template<typename T>
void Vector<T>::reallocate()
{
	size_t sz=size();
	size_t newcapacity = sz>0 ? 2*sz :1;
	T *newele=_alloc.allocate(newcapacity);
	std::uninitialized_copy(_begin,_first_free,newele);//原始空间赋值uninitialized_copy
	if(_begin)
	{
		while(_first_free!=_begin)
			_alloc.destroy(--_first_free);
		_alloc.deallocate(_begin,sz);
	}
	_begin=newele;
	_first_free=_begin+sz;
	_end=_begin+newcapacity;
}

int main(void)
{
	Vector<int> vecint;
	cout<<"size:"<<vecint.size()<<" capacity:"<<vecint.capacity()<<endl;
	vecint.push_back(12);
	cout<<"size:"<<vecint.size()<<" capacity:"<<vecint.capacity()<<endl;
	vecint.push_back(14);
	cout<<"size:"<<vecint.size()<<" capacity:"<<vecint.capacity()<<endl;

	vecint.push_back(16);
	vecint.push_back(18);
	vecint.push_back(23);
	cout<<"size:"<<vecint.size()<<" capacity:"<<vecint.capacity()<<endl;
	vecint.pop_back();
	cout<<"size:"<<vecint.size()<<" capacity:"<<vecint.capacity()<<endl;
	return 0;
}
