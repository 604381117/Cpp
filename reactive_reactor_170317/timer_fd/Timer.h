#ifndef __WD_WIMER_H__
#define __WD_WIMER_H__

#include "Noncopyable.h"
#include <functional>

namespace wd
{

class Timer:public Noncopyable{
public:
	typedef std::function<void()> TimerCallback;
	Timer(int initTime,int intervalTime,TimerCallback cb);
	~Timer();
	
	void start();
	void stop();
	bool isStarting()const
	{ return _isStarted; }
private:
	int createTimerFd();
	void setTimerFd(int initTime,int intervalTimer);
	void stopTimerFd();
	void readTimerFd();
private:
	int _fd;
	int _initTime;
	int _intervalTime;
	TimerCallback _cb;
	bool _isStarted;
};

}
#endif
