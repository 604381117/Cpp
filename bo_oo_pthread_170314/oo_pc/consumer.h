 ///
 /// @file    consumer.h
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 16:21:49
 ///
#ifndef __WD_CONSUMER_H__
#define __WD_CONSUMER_H__

#include "pthread.h"

namespace wd
{

class Buffer;

class Consumer:public Thread{
public:
	Consumer(Buffer &buf);
	virtual void run();

private:
	Buffer & _buf;
};

}
#endif
