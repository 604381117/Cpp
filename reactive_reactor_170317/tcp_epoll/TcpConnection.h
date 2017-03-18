///
/// @file    TcpConnection.h
/// @author  yangyu/Icot(jobyang@163.com)
/// @date    2017-03-17 21:18:12
///
#ifndef __WD_TCPCONNECTION_H__
#define __WD_TCPCONNECTION_H__

#include "Noncopyable.h"
#include "Socket.h"
#include "SockIO.h"
#include <memory>
#include <functional>

namespace wd
{  
	
class TcpConnection;
typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;

class TcpConnection
:private Noncopyable
,public std::enable_shared_from_this<TcpConnection>
{
public:
	typedef std::function<void (const TcpConnectionPtr &)> TcpConnectionCallback;

	explicit TcpConnection(int sockfd);
	~TcpConnection();

	//C++11 move semantics
	void setConnectCallback(TcpConnectionCallback cb)
	{ onConnectCallback_ = std::move(cb); }
	void setMessageCallback(TcpConnectionCallback cb)
	{ onMessageCallback_ = std::move(cb); }
	void setCloseCallback(TcpConnectionCallback cb)
	{ onCloseCallback_ = std::move(cb); }
	
	void handleConnectCallback();
	void handleMessageCallback();
	void handleCloseCallback();

	void shutdown()
	{ _sockfd.shutdownWrite(); _isShutdownWrite = true; }

	ssize_t readn(char *buf, size_t count);
	ssize_t writen(const char *buf, size_t count);
	ssize_t readLine(char *usrbuf, size_t maxlen);

	std::string receive();
	void send(const std::string &s);


	const InetAddress &getLocalAddr() const
	{ return _localAddr; }
	const InetAddress &getPeerAddr() const
	{ return _peerAddr; }

	std::string toString() const;

private:
	Socket _sockfd;
	SocketIO _sockIO;
	const InetAddress _localAddr;
	const InetAddress _peerAddr;
	bool _isShutdownWrite;  //是否关闭写端

	TcpConnectionCallback onConnectCallback_;
	TcpConnectionCallback onMessageCallback_;
	TcpConnectionCallback onCloseCallback_;
};

}
#endif
