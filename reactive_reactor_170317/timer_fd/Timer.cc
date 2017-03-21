#include "Timer.h"
#include "log4func.h"

#include <unistd.h>
#include <sys/timerfd.h>
#include <poll.h>

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

Timer::Timer(int initTime,int intervalTime,TimerCallback cb)
:_fd(createTimerFd())
 ,_initTime(initTime)
 ,_intervalTime(intervalTime)
 ,_cb(cb)
 ,_isStarted(false)
{}

Timer::~Timer()
{
	if(_isStarted)
		stop();
}

void Timer::start()
{
	if(!_isStarted)
		_isStarted = true;

	//开启定时器
	setTimerFd(_initTime, _intervalTime);

	struct pollfd pfd;
	pfd.fd = _fd;
	pfd.events = POLLIN;

	while(_isStarted)
	{
		int nready = ::poll(&pfd, 1, 5000);
		if(nready == -1)
		{
			if(errno == EINTR){
				continue;
			}else{
				LogError("poll return error!");
			}
		}else if(nready == 0){
			LogInfo("poll timeout!");
		}else{
			if((pfd.fd == _fd) && (pfd.revents & POLLIN))
			{
				readTimerFd();//对定时器作了处理,执行read操作
				if(_cb) //执行任务
					_cb();
			}
		}
	}//end of while
}

void Timer::stop()
{
	if(_isStarted)
	{
		stopTimerFd();//先停止定时器
		_isStarted = false;
	}
}

int Timer::createTimerFd()
{
	int fd = ::timerfd_create(CLOCK_REALTIME, 0);
	if(fd == -1)
	{
		LogError("timerfd_create error");
	}
	return fd;
}

void Timer::setTimerFd(int initTime, int intervalTime)
{
	struct itimerspec value;
	value.it_value.tv_sec = initTime;
	value.it_value.tv_nsec = 0;
	value.it_interval.tv_sec = intervalTime;
	value.it_interval.tv_nsec = 0;

	int ret = ::timerfd_settime(_fd, 0, &value, NULL);
	if(ret == -1)
	{
		LogError("timerfd_settime error!");
	}
}

void Timer::readTimerFd()
{
	uint64_t howmany = 0;
	int ret = ::read(_fd, &howmany, sizeof(uint64_t));
	if(ret != sizeof(uint64_t))
	{
		LogError("read timerfd error!");
	}
}

void Timer::stopTimerFd()
{
	setTimerFd(0, 0);
}

}
