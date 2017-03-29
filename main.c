#include <gmp.h>
#include <pthread.h>
#include <mysql.h>

void *getPrime(void *p);
void mysql(void);

int main()
{
	int p;
	pthread_t thread;

	for (p = 3; ; p += 2)
		if (!pthread_create(&thread, NULL, getPrime, &p))
			gmp_printf("Thread criada. Expoente %d%c%c", p, 10);
}

void *getPrime(void *p)
{
	mpz_t mersenneNumber, s, aux;
	int i, expoente = * (int *) p;

	mpz_init(mersenneNumber);
	mpz_init(s);
	mpz_init(aux);

	mpz_ui_pow_ui(mersenneNumber, (long)(2), expoente);
	mpz_sub_ui(mersenneNumber, mersenneNumber, (long)(1));
	mpz_set_ui(s, (long)(4));

	for (i = 1; i <= expoente - 2; i++)
	{
		mpz_powm_ui(aux, s, (long)(2), mersenneNumber); 
		mpz_sub_ui(s, aux, (long)(2)); 
	}

	if (mpz_sgn(s) == 0)
		gmp_printf("M%d%c%Zd %c%c", expoente, 10, mersenneNumber, 10, 10);
}

void mysql(void)
{
	MYSQL conexao;

	mysql_init(&conexao);
	if (mysql_real_connect(&conexao, "localhost", "root", "root", "teste", 0, NULL, 0))
	{
	    printf("conectado com sucesso!\n");
	    mysql_close(&conexao);
	}
	else
	{
	    printf("Falha de conexao\n");
	    printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
	}
}
