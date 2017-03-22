#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

unsigned long int mersenne(unsigned long int expoente);
unsigned long int lucasLehmer(unsigned long int expoente, unsigned long int mersenneNumber);

int main(int argc, char *argv[])
{
	unsigned long p, s, mp;
	mpz_t pp, ll, aux;

	mpz_init(pp);
	mpz_init(ll);
	mpz_init(aux);

	for (p = 3; ; p += 2)
	{
		mp = mersenne(p);
		s = lucasLehmer(p, mp);
		if (s == 0)
			printf("M%lu é primo. - %lu \n\n", p, mp);
	}

	mpz_set_ui(ll, (long)(4));

	for (i = 1; i + 2 <= p; i++)
	{
		mpz_powm_ui(aux, ll, (long)(2), pp); 
		mpz_sub_ui(ll, aux, (long)(2)); 
	}

	if (mpz_sgn(ll) == 0)
		printf("M%ld é primo.\n",p);
	else
		printf("M%ld é composto.\n",p);

}

mpz_t mersenne(unsigned long expoente)
{
	mpz_t mersenneNumber;

	mpz_init(mersenneNumber);
	mpz_ui_pow_ui(mersenneNumber, (long)(2), expoente);
	mpz_sub_ui(mersenneNumber, (long)(1));

	return mersenneNumber;
}

unsigned long int lucasLehmer(unsigned long int expoente, unsigned long int mersenneNumber)
{
	unsigned long int s = 4, i;
	for (i = 1; i <= expoente - 2; i++)
		s = (s * s - 2) % mersenneNumber;
	return s;
}
