#ifndef __WD_TIMERTHREAD_H__
#define __WD_TIMERTHREAD_H__

#include "Timer.h"
#include "Thread.h"

namespace wd
{

class TimerThread{
public:
	typedef std::function<void()> TimerCallback;
	TimerThread(int initTime, int intervalTime, TimerCallback cb);

	~TimerThread();

	void start();
	void stop();

private:
	Timer  _timer;
	Thread _thread;
};

}//end of namespace wd
#endif

