#include "database.h"
#include "file.h"

void *connectRedis()
{
	int port = 6379, i;
	void *retorno = NULL;
	redisContext *c = redisConnect("localhost", port);
	if (c == NULL && !c->err)
		retorno = c;

	return retorno;
}

int main()
{
	configuracao conf = getConfs();
	printf("%s", conf.host);
	printf("%s", conf.port);
	//int port = 6379, i;
	//redisReply *reply;
	//redisContext *c = redisConnect("localhost", port);


	//reply = redisCommand(c, "SET %s %s", "foo", "bar");
	//freeReplyObject(reply);

	//reply = redisCommand(c, "GET %s", "foo");
	//printf("%s\n", reply->str);
	//freeReplyObject(reply);
	//redisFree(c);
}
