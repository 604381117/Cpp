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
#include <functioinal>
namespace wd
{

typedef std::function<void()> ElemType;

class Task;
typedef Task* ElemType;

class Buffer{
public:
	Buffer(size_t size);
	void push(ElemType elem);
	ElemType pop();
	bool empty();
	bool full();
	void weakup();
private:
MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	size_t _size;
	std::queue<ElemType> _que;
};

}
#endif
