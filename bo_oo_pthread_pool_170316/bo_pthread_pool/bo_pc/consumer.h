 ///
 /// @file    consumer.h
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 16:21:49
 ///
#ifndef __WD_CONSUMER_H__
#define __WD_CONSUMER_H__

namespace wd
{

class Buffer;

class Consumer{
public:
	void consume(wd::Buffer &_buffer);
};

}
#endif
