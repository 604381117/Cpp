 ///
 /// @file    Socket.h
 /// @author  yangyu/Icot(jobyang@163.com)
 /// @date    2017-03-17 20:17:29
 ///
#ifndef __WD_SOCKET_H__
#define __WD_SOCKET_H__

#include "Noncopyable.h"
#include "InetAddress.h"

namespace wd
{

typedef struct sockaddr SA;

class Socket:Noncopyable{
public:
	explicit Socket(int sockfd);
	~Socket();

	void ready(const InetAddress &,bool on);
	int fd()const;
	void bindAddress(const InetAddress &addr);
	void listen();
	int accept();
	
	void shutdownWrite();
	
	void setTcpNoDelay(bool on);
	void setReusePort(bool on);
	void setReuseAddr(bool on);
	void setKeepAlive(bool on);

	static InetAddress getLocalAddr(int sockfd); //静态调用，有时候在对象不存在的情况下需要刁永红
	static InetAddress getPeerAddr(int sockfd);
private:
	const int _sockfd;
};

}
#endif
