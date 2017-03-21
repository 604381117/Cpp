#ifndef __WD_EVENTFD_H_
#define __WD_EVENTFD_H_

#include "Noncopyable.h"
#include <functional>

namespace wd
{

class Eventfd: public Noncopyable{
public:
	typedef std::function<void()> EventfdCallback;

	Eventfd(EventfdCallback cb);
	~Eventfd();

	void start();
	void stop();
	bool isStarting()const
	{ return _isStarted; }

	void wakeup();

private:
	int createEventFd();
	void handleRead();
private:
	bool            _isStarted;
	int             _fd;
	EventfdCallback _cb;
};

}//end of namespace wd
#endif
