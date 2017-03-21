#include "log4func.h"
#include "Eventfd.h"

#include <unistd.h>
#include <sys/eventfd.h>
#include <poll.h>

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

Eventfd::Eventfd(EventfdCallback cb)
: _fd(createEventFd())
, _cb(cb)
, _isStarted(false)
{}

Eventfd::~Eventfd()
{
	if(_isStarted)
		stop();
}

void Eventfd::start()
{
	if(!_isStarted)
		_isStarted = true;

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
				handleRead();//对eventfd执行read操作
				if(_cb) //执行任务
					_cb();
			}
		}
	}//end of while
}

void Eventfd::stop()
{
	if(_isStarted)
	{
		_isStarted = false;
	}
}

int Eventfd::createEventFd()
{
	int fd = ::eventfd(0, 0);
	if(fd == -1)
	{
		LogError("envetfd create error");
	}
	return fd;
}

void Eventfd::handleRead()
{
	uint64_t howmany = 0;
	int ret = ::read(_fd, &howmany, sizeof(uint64_t));
	if(ret != sizeof(uint64_t))
	{
		LogError("read eventfd error!");
	}
}

void Eventfd::wakeup()
{
	uint64_t one = 1;
	int ret = ::write(_fd, &one, sizeof(one));
	if(ret == -1)
	{
		LogError("write eventfd error!");
	}
}

}//end of namespace wd
