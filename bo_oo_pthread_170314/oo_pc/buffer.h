 ///
 /// @file    buffer.h
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 16:00:39
 ///
#ifndef __WD_BUFFER_H__
#define __WD_BUFFER_H__

#include "mutex.h"
#include "condition.h"

#include <queue>

namespace wd
{

class Buffer{
public:
	Buffer(size_t size);
	void push(int);
	int pop();
	bool empty();
	bool full();
private:
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	size_t _size;
	std::queue<int> _que;
};

}
#endif
