///
/// @file    iterative_sever.cc
/// @author  yangyu/Icot(jobyang@163.com)
/// @date    2017-03-17 22:30:04
///
#include "Socket.h"
#include "TcpConnection.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char const *argv[])
{
	int fd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(fd == -1)
	{
		perror("create socket error");
		exit(EXIT_FAILURE);
	}

	wd::InetAddress addr("192.168.4.75", 8888);

	wd::Socket sock(fd);
	sock.ready(addr);

	int peerfd = sock.accept();

	wd::TcpConnectionPtr conn(new wd::TcpConnection(peerfd));

	while(1)
	{
		std::string msg(conn->receive());
		std::cout << msg;
		conn->send(msg);
	}

	conn->shutdown();
	close(fd);

	return 0;
}

