#include "redis_client.h"
#include <string.h>

#define REDIS_CONETEXT_IS_NULL -1

RedisClient::RedisClient()
{
	redis_context_ = NULL;
	redis_reply_ = NULL;

}

RedisClient::~RedisClient()
{
	if(redis_context_ != NULL)
	{
		redisFree(redis_context_);
	}

}

void RedisClient::Init(char * ip, unsigned short port)
{
	printf("edn\n");
	this->ip = ip;
	this->port = port;
}

int RedisClient::Connect()
{
	redis_context_ = redisConnect(this->ip.c_str(), port);

	if(redis_context_ == NULL)
	{
		return -1;
	}

	if(redis_context_ != NULL && redis_context_ -> err)
	{
		printf("Error:%s\n", redis_context_->errstr);
		return -1;
	}

	return 0;
}

int RedisClient::RedisInfo(std::string &redisInfo)
{
	if(redis_context_ == NULL)
	{
		return -1;
	}

	redis_reply_ =(redisReply *)redisCommand(redis_context_, "INFO");
	
	if(redis_reply_ == NULL)
	{
		return -1;
	}

	redisInfo = redis_reply_->str;
	freeReplyObject(redis_reply_);
	redis_reply_ = NULL;
	return 0;
}
