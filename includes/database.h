#ifndef API
#define API_PROD "https://apimos.herokuapp.com/prime/"
#define API_LOCAL "http://localhost:5000/prime/"
#define API API_LOCAL
#endif

typedef enum {false, true} bool;

int getNextPrime();
bool putPrime(int prime, char *macAddres, char* name, bool mersenne);
void generateGetRequest();
bool generatePutRequest(char *body, int prime);
char *makePutJson(char *macAddres, char* name, bool mersenne);
char *getPrimeToJson();
char *getValueFromKey(char *key);
char *getNetxValue();
char *substr(char *str, int offset, int len);
