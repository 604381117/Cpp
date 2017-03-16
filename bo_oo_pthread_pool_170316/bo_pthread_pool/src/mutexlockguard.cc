 ///
 /// @file    mutexlockguard.cc
 /// @author  yangyu/icot(jobyang@163.com)
 /// @date    2017-03-16 16:37:14
 ///
#include "mutexlockguard.h"

namespace wd
{

MutexLockGuard::MutexLockGuard(MutexLock &mutex)
:_mutex(mutex)
{
	_mutex.lock();	
}

MutexLockGuard::~MutexLockGuard()
{
	_mutex.unlock();	
}

}
