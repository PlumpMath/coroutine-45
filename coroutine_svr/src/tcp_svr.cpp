#include "tcp_svr.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <apra/inet.h>

TcpSvr::TcpSvr(char * ip, unsigned short port)
{
	svr_fd = socket(AF_INET, SOCK_STREAM, 0);
	sockfile_flag = false;
}

TcpSvr::TcpSvr(char * sock_path)
{
	svr_fd = socket(AF_INET, SOCK_STREAM, 0);
	sockfile_flag = true;
}

TcpSvr::~TcpSvr()
{
	if(svr_fd > 0)
	{
		close(svr_fd);
	}
}

int TcpSvr::SetNonBlocking()
{
	int flag = fcntl(svr_fd, F_GETFL, 0);
	if(flag < 0)
	{
		return -1;
	}

	if(fcntl(svr_fd, F_SETFL, flag | O_NONBLOCK) < 0)
	{
		return -1;
    }
	return 0;

}

int TcpSvr::Bind()
{
	if(sockfile_flag == true)
	{
		struct sockaddr_in sockaddr;
		sockaddr.sin_family = AF_INET;
		sockaddr.sin_port = htons(this->port);
		sockaddr_in.sin_addr.s_addr = inet_addr(ip);
	    
		if(bind(svr_fd, (struct sockaddr *)sockaddr, sizeof(struct sockaddr)) != 0)
		{
			return -1;
		}
	}
	else
	{
		struct sockaddr_un sockaddr;
		sockaddr.sun_family = AF_UNIX;
		strncpy(sockaddr.sun_path, sock_path, sizeof(sockaddr.sun_path) - 1)
		unlink(sock_path);

		if(bind(svr_fd, (struct sockaddr *)sockaddr, sizeof(struct sockaddr)) != 0)
		{
			return -1;
		}
	}

	return 0;
}

int TcpSvr::Listen(int backflag)
{
	return listen(svr_fd, backflag);
}

int TcpSvr::Accept()
{
	return 0;
}

int TcpSvr::Send(int fd, char buffer, size_t buffer_size)
{
	int send_len = send(fd, buffer, buffer_size, 0);

	if(send_len < 0)
	{
		if(errno == EAGAIN)
		{
			return -1;
		}
	}

	return send_len;
}

int TcpSvr::Recv(int fd, char buffer, size_t buffer_size)
{
	int recv_len = recv(fd, buffer, buffer_size, 0);

	if(recv_len < 0)
	{
		if(errno == EAGAIN)
		{
			return -1;
		}
	}
	return recv_len;
}
