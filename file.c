#include "file.h"

char *getConfigFile()
{
	FILE *fp;
	int i;
	char text[MAX_LINES_FILE_CONFIG][25];

	fp = fopen(FILE_CONF_NAME, "r");
	if(fp)
		for(i = 1; i <= MAX_LINES_FILE_CONFIG; i++)
			fgets(text[i], sizeof(text[i]), fp);

	fclose(fp);
	return text;
}

char *getConfs()
{
	char *config = getConfigFile();
	char retorno[2];

	printf("%s", config);
}
