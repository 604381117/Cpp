 ///
 /// @file    buffer.cc
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 16:03:15
 ///
#include "buffer.h" 

namespace wd
{

Buffer::Buffer(size_t size)
:_mutex()
,_notFull(_mutex)
,_notEmpty(_mutex)
,_size(size)
{ }

bool Buffer::full()
{	return _que.size()==_size;	}

bool Buffer::empty()
{	return _que.size()==0;	}

//运行于生产者线程
void Buffer::push(int number)
{
	_mutex.lock();
	while(full())     //while 代替 if可避免条件变量被异常唤醒
		_notFull.wait();
	_que.push(number);
	_notEmpty.notify();
	_mutex.unlock();
}

//运行于消费者线程
int Buffer::pop()
{
	_mutex.lock();
	while(empty())
		_notEmpty.wait();
	int ret=_que.front();
	_que.pop();
	_notFull.notify();
	_mutex.unlock();
	return ret;
}

}
