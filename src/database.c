#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "database.h"

char *response;

int getNextPrime(void)
{
	generateRequest();
	printf("%s", response);
}

void writefunc(void *ptr, size_t size, size_t nmemb, void *stream)
{
	response = (char *) ptr;
}

void generateRequest(void)
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, API);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);

	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
}
