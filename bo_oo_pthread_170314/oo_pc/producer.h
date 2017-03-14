 ///
 /// @file    producer.h
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 16:15:46
 ///
#ifndef __WD_PRODUCER_H__
#define __WD_PRODUCER_H__

#include "pthread.h"

namespace wd
{

class Buffer;

class Producer :public Thread{
public:
	Producer(Buffer &_buffer);
	virtual void run();

private:
	Buffer &_buf;
};

}
#endif
