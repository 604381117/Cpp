#include "Thread.h"
 
namespace wd
{

Thread::Thread(ThreadCallback cb)
:_pthId(0)//默认给个0
,_isRunning(false)
,_cb(cb)
{}

void Thread::start()
{
	pthread_create(&_pthId, NULL, threadFunc, this);
	_isRunning = true;
}

void * Thread::threadFunc(void * arg)
{
	Thread * p = static_cast<Thread*>(arg);
	if(p)
		p->_cb();
	return NULL;
}

void Thread::join()
{
	if(_isRunning)
	{
		pthread_join(_pthId, NULL);
		_isRunning = false;
	}
}

Thread::~Thread()
{
	if(_isRunning)
	{
		pthread_detach(_pthId);
		_isRunning = false;
	}
}

}//end of namespace wd

