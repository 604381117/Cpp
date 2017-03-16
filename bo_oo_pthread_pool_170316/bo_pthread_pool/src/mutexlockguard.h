 ///
 /// @file    mutexlockguard.h
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 17:05:12
 ///
#ifndef __WD_MUTEXLOCKGUARD_H__
#define __WD_MUTEXLOCKGUARD_H__

#include "mutex.h"

namespace wd
{

class MutexLock;

class MutexLockGuard{
public:
	MutexLockGuard(MutexLock &);
	~MutexLockGuard();
private:
	MutexLock & _mutex;
};

}
#endif
