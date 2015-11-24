#ifndef __TCP_SVR_H_
#define __TCP_SVR_H_

class TcpSvr
{
public:
	TcpSvr(char * ip, unsigned short port);
	~TcpSvr();

	int SetNonBlocking();
	int Bind();
	int Listen(int backflags);
	int Accept();
	int Send(int fd, char * buffer, size_t buffer_size);
	int Recv(int fd, char * buffer, size_t buffer_size);
private:
	std::string ip;
	unsigned short port;

	int svr_fd;
};
#endif
