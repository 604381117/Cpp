#include "TimerThread.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

TimerThread::TimerThread(int initTime, int intervalTime, TimerCallback cb)
: _timer(initTime, intervalTime, cb)
, _thread(std::bind(&Timer::start, &_timer))
{
}

TimerThread::~TimerThread()
{
	if(_timer.isStarting())
		stop();
}

void TimerThread::start()
{
	_thread.start();
}

void TimerThread::stop()
{
	if(_timer.isStarting())
		_timer.stop();
	_thread.join();
}

}//end of namespace wd

