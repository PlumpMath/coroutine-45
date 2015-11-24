#include "tcp_svr.h"

TcpSvr::TcpSvr(char * ip, unsigned short port)
{
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
	int flag = fcntl(svr_fd, F_GETL, 0);
	if(flag < 0)
	{
		return -1;
	}

	if(fcntl(svr_fd, F_SETL, flag | O_NONBLOCK) < 0)
	{
		return -1;
	}

	return 0;

}

int TcpSvr::Bind()
{

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
	return 0;
}

int TcpSvr::Recv(int fd, char buffer, size_t buffer_size)
{
	return 0;
}


