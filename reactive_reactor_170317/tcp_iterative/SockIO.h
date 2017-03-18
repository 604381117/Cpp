///
/// @file    SockIO.h
/// @author  yangyu/Icot(jobyang@163.com)
/// @date    2017-03-17 20:56:25
///
#ifndef __WD_SOCKETIO_H__
#define __WD_SOCKETIO_H__

#include "Noncopyable.h"
#include <sys/types.h>

namespace wd
{

class SocketIO : Noncopyable{
public: 
	explicit SocketIO(int sockfd)
	: _sockfd(sockfd)
	{ }

	ssize_t readn(char *buf, size_t count);
	ssize_t writen(const char *buf, size_t count);
	ssize_t readline(char *usrbuf, size_t maxlen);
private:
	ssize_t recv_peek(char *buf, size_t len);//进入内核扫描数据,设置为私有
	const int _sockfd;
};

}
#endif

