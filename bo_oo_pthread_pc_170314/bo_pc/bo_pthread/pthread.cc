 ///
 /// @file    thread.cc
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 11:21:37
 ///
#include "pthread.h"

namespace wd
{

Thread::Thread(ThreadCallback cb)
:_pthId(0)
,_isRunning(false)
,_cb(cb)
{ }

void Thread::start()
{
	pthread_create(&_pthId,NULL,threadFunc,this);
	_isRunning = true;
}

void Thread::join()
{
	if(_isRunning){
		pthread_join(_pthId,NULL);
		_isRunning = false;
	}
}

void * Thread::threadFunc(void* arg)
{
	Thread* p=static_cast<Thread*>(arg);
	if(p)
		p->_cb();
	return NULL;
}

Thread::~Thread()
{
	if(_isRunning){
		pthread_detach(_pthId);//资源回收交给主线程进行托管
		_isRunning=false;
	}
}

}

