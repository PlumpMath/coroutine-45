#ifndef __REDIS_CLIENT_H_
#define __REDIS_CLIENT_H_

#include "hiredis.h"
#include <string>

class RedisClient
{
public:
	RedisClient();
	~RedisClient();

	void Init(char * ip, unsigned short port);
	int Connect();

	int RedisInfo(std::string& redisInfo);

private:
	std::string ip;
	unsigned short port;

	redisContext * redis_context_;
	redisReply * redis_reply_;

};
#endif
