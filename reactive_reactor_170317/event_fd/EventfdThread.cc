#include "EventfdThread.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

EventfdThread::EventfdThread(EventfdCallback cb)
: _event(cb)
, _thread(std::bind(&Eventfd::start, &_event))
{}

EventfdThread::~EventfdThread()
{
	if(_event.isStarting())
		stop();
}

void EventfdThread::start()
{
	_thread.start();
}

void EventfdThread::stop()
{
	if(_event.isStarting())
		_event.stop();
	_thread.join();
}

void EventfdThread::wakeup()
{
	_event.wakeup();
}

}//end of namespace wd
