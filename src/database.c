#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "database.h"

char *response;
int responsePosition;

int getNextPrime(void)
{
	generateGetRequest();
	return atoi(getPrimeToJson());
}

bool putPrime(int prime, char *macAddres, char* name, bool mersenne)
{
	puts("Será que deu ruim?");
	printf("%s", makePutJson(macAddres, name, mersenne));
	return generatePutRequest(makePutJson(macAddres, name, mersenne), prime);
}

char *makePutJson(char *macAddres, char* name, bool mersenne)
{
	char *body;
	sprintf(body, "{\"calc\": 2, \"machine\": {\"clientType\": 1,\"macAddres\": \"%s\",\"name\": \"%s\"},\"mersenne\": %d}", macAddres, name, mersenne);

	return body;
}

void writefunc(void *ptr, size_t size, size_t nmemb, void *stream)
{
	response = (char *) ptr;
}

bool generatePutRequest(char *body, int prime)
{
	char *url = API;
	CURL *curl;
	CURLcode res;

	strcat(url, (char *) &prime);
	printf("%s", body);
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);

	puts("Aqui na requisição?");
	res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);

	return res == CURLE_OK;
}


void generateGetRequest(void)
{
	CURL *curl;

	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, API);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);

	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
}

char *getPrimeToJson()
{
	return getValueFromKey("nextPrime");
}

char *getValueFromKey(char *key)
{
	char *value;
	responsePosition = 0;
	while((strcmp(getNetxValue(), key) != 0) && (responsePosition < strlen(response)));
	value = getNetxValue();
	return value;
}

char *getNetxValue()
{
	int initialPosition = 0, finalPosition = 0;
	char *nextValue;

	while(finalPosition == 0)
	{
		if (response[responsePosition] == 34)
		{
			if (initialPosition == 0)
			{
				initialPosition = responsePosition;
			}
			else
			{
				finalPosition = responsePosition;
				nextValue = substr(response, ++initialPosition, finalPosition);
			}
		}
		responsePosition++;
	}

	return nextValue;
}

char *substr(char *str, int offset, int len)
{
	char *newStr = malloc(len - offset);
	strncpy(newStr, str + offset, len - offset);
	newStr[len - offset] = '\0';
	return newStr;
}
