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

//通过this指针获取指向本this的shared_ptr指针
class TcpConnection
:private Noncopyable
,public std::enable_shared_from_this<TcpConnection>{
public:
	typedef std::function<void (const TcpConnectionPtr &)> TcpConnectionCallback;

	explicit TcpConnection(int sockfd);
	~TcpConnection();

	//C++11 move semantics
	void setConnectCallback(TcpConnectionCallback cb)
	{ _onConnectCallback = std::move(cb); }
	void setMessageCallback(TcpConnectionCallback cb)
	{ _onMessageCallback = std::move(cb); }
	void setCloseCallback(TcpConnectionCallback cb)
	{ _onCloseCallback = std::move(cb); }
	
	void handleConnectCallback();
	void handleMessageCallback();
	void handleCloseCallback();

	void shutdown()
	{ _sockfd.shutdownWrite(); _isShutdownWrite = true; }

	ssize_t readn(char *buf, size_t count);
	ssize_t writen(const char *buf, size_t count);
	ssize_t readLine(char *usrbuf, size_t maxlen);

	//提供获取系统缓存区保存至应用缓存区并返回缓存区首地址的接口
	//缓存区大小函数体可设置
	std::string receive();
	void send(const std::string &s);


	const InetAddress &getLocalAddr() const
	{ return _localAddr; }
	const InetAddress &getPeerAddr() const
	{ return _peerAddr; }

	//打印源ip port与目的ip port
	std::string toString() const;

private:
	Socket _sockfd;
	SocketIO _sockIO;
	const InetAddress _localAddr;
	const InetAddress _peerAddr;
	bool _isShutdownWrite;  //是否关闭写端

	TcpConnectionCallback _onConnectCallback;
	TcpConnectionCallback _onMessageCallback;
	TcpConnectionCallback _onCloseCallback;
};

}
#endif
