///
/// @file    TcpConnection.cc
/// @author  yangyu/Icot(jobyang@163.com)
/// @date    2017-03-17 21:49:13
///
#include "TcpConnection.h"

namespace wd
{

TcpConnection::TcpConnection(int sockfd)
: _sockfd(sockfd)
,_sockIO(sockfd)
,_localAddr(Socket::getLocalAddr(sockfd))
,_peerAddr(Socket::getPeerAddr(sockfd))
,_isShutdownWrite(false)
{ }

TcpConnection::~TcpConnection()
{
	if(!_isShutdownWrite)
	{
		shutdown();
	}
}

//conn->handleConnectCalback()
#if 1
void TcpConnection::handleConnectCallback()
{
	if(onConnectCallback_)
	{
		onConnectCallback_(shared_from_this());
	}
}

void TcpConnection::handleMessageCallback()
{
	if(onMessageCallback_)
	{
		onMessageCallback_(shared_from_this());
	}
}

void TcpConnection::handleCloseCallback()
{
	if(onCloseCallback_)
	{
		onCloseCallback_(shared_from_this());
	}
}
#endif

ssize_t TcpConnection::readn(char *buf, size_t count)
{
	ssize_t ret = _sockIO.readn(buf, count);
	if(ret == -1)
	{
		fprintf(stderr, "TcpConnection readn\n");
		exit(EXIT_FAILURE);
	}
	return ret;
}

ssize_t TcpConnection::writen(const char *buf, size_t count)
{
	ssize_t ret = _sockIO.writen(buf, count);
	if(ret == -1)
	{
		fprintf(stderr, "TcpConnection writen\n");
		exit(EXIT_FAILURE);
	}
	return ret;
}

ssize_t TcpConnection::readLine(char *usrbuf, size_t maxlen)
{
	ssize_t ret = _sockIO.readline(usrbuf, maxlen);
	if(ret == -1)
	{
		fprintf(stderr, "TcpConnection readLine\n");
		exit(EXIT_FAILURE);
	}
	return ret;
}

std::string TcpConnection::receive()
{
	char str[65535] = {0};//64kB
	int ret = readLine(str, sizeof str);
	if(ret == 0)
		return std::string();
	else
		return std::string(str);
}

void TcpConnection::send(const std::string &s)
{
	writen(s.c_str(), s.size());
}

std::string TcpConnection::toString() const
{
	char text[100];
	snprintf(text, sizeof text, "%s:%d -> %s:%d", 
			_localAddr.toIp().c_str(),
			_localAddr.toPort(),
			_peerAddr.toIp().c_str(),
			_peerAddr.toPort());

	return text;
}

}
