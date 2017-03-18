///
/// @file    EpollPoller.h
/// @author  yangyu/Icot(jobyang@163.com)
/// @date    2017-03-17 23:24:19
///
#ifndef __WD_EPOLLPOLLER_H__
#define __WD_EPOLLPOLLER_H__
#include "Noncopyable.h"
#include <vector>
#include <map>
#include <sys/epoll.h>
#include "TcpConnection.h"

namespace wd
{

class EpollPoller : Noncopyable{
public:
	typedef TcpConnection::TcpConnectionCallback EpollCallback;

	explicit EpollPoller(int listenfd);
	~EpollPoller();
	void loop(); //启动epoll
	void unloop(); //关闭epoll
	void setConnectCallback(EpollCallback cb)
	{ _onConnectCallback = std::move(cb); }
	void setMessageCallback(EpollCallback cb)
	{ _onMessageCallback = std::move(cb); }
	void setCloseCallback(EpollCallback cb)
	{ _onCloseCallback = std::move(cb); }

private:
	void waitEpollFd(); //循环
	void handleConnection(); //处理accept
	void handleMessage(int peerfd); //处理msg
private:
	const int _epollfd;
	const int _listenfd; 
	bool _isLooping; //是否在运行
	typedef std::vector<struct epoll_event> EventList;
	EventList _events;  //保存活跃的fd
	typedef std::map<int, TcpConnectionPtr> ConnectionList;//保存连接的sfd和tcpconnection对
	ConnectionList _lists; //实现fd到conn的映射
	EpollCallback _onConnectCallback;
	EpollCallback _onMessageCallback;
	EpollCallback _onCloseCallback;
};

}
#endif
