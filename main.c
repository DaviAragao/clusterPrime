#include <stdio.h>

unsigned long int calcMersenne(unsigned long int expoente);
unsigned long int lucasLehmer(unsigned long int expoente, unsigned long int mersenneNumber);

int main()
{
	unsigned long int p, s, mp;

	for (p = 3; ; p += 2)
	{
		mp = calcMersenne(p);
		s = lucasLehmer(p, mp);
		if (s == 0)
			printf("M%lu é primo. - %lu -\n\n", p, mp);
	}
}

unsigned long int calcMersenne(unsigned long int expoente)
{
	unsigned long int mp = 2, i;
	for (i = 2; i <= expoente; i++)
		mp *= 2;
	return --mp;
}

unsigned long int lucasLehmer(unsigned long int expoente, unsigned long int mersenneNumber)
{
	unsigned long int s = 4, i;
	for (i = 1; i <= expoente - 2; i++)
		s = (s * s - 2) % mersenneNumber;
	return s;
}
