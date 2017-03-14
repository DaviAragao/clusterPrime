#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i, s, p, mp;

	p = atoi(argv[1]);

	mp = 2;
	for(i = 2; i <= p; i++)
		mp *= 2;
	mp--;

	s = 4;
	for(i = 2; i <= p - 1; i++)
	{
		s = s * s - 2;
		printf("%d\n", s);
	}

	if(s % mp == 0)
		printf("M%d é primo.\n\n", p);
	else
		printf("M%d é composto.\n\n", p);
}
