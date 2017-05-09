#include "file.h"

int main()
{
	configuracao *conf = getConfs();
	printf("%s", conf->host);
	printf("%s", conf->port);
}

configuracao *getConfs()
{
	FILE *fp;
	configuracao *conf;

	fp = fopen(FILE_CONF_NAME, "r");
	if(fp)
	{
		fgets(conf->host, MAX_SIZE_NAMES_CONFIG, fp);
		fgets(conf->port, MAX_SIZE_NAMES_CONFIG, fp);
	}

	fclose(fp);
	return conf;
}

char *getHost()
{
	configuracao *configuracao = getConfs();
	char retorno[2];
}

char *getPort()
{

}
