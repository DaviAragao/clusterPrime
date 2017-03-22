#include <gmp.h>

int main()
{
	system("clear");
	system("date");
	int p, i;
	mpz_t mersenneNumber, s, aux;

	mpz_init(mersenneNumber);
	mpz_init(s);
	mpz_init(aux);

	for (p = 3; ; p += 2)
	{
		mpz_ui_pow_ui(mersenneNumber, (long)(2), p);
		mpz_sub_ui(mersenneNumber, mersenneNumber, (long)(1));
		mpz_set_ui(s, (long)(4));

		for (i = 1; i <= p - 2; i++)
		{
			mpz_powm_ui(aux, s, (long)(2), mersenneNumber); 
			mpz_sub_ui(s, aux, (long)(2)); 
		}

		if (mpz_sgn(s) == 0)
		{
			gmp_printf("M%d%c %Zd %c%c", p, 10, mersenneNumber, 10, 10);
			system("date");
		}
	}
}
