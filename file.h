#include <stdio.h>

#define MAX_SIZE_NAMES_CONFIG 32
#define FILE_CONF_NAME "conf"

typedef struct
{
	char host[MAX_SIZE_NAMES_CONFIG];
	char port[MAX_SIZE_NAMES_CONFIG];
}configuracao;

configuracao *getConfs();
char *getHost();
char *getPort();
