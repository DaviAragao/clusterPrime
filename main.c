#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	int i, s, p, mp;

	p = atoi(argv[1]); /* Lemos p da linha de comando */

	mp = 2; for ( i = 2 ; i <= p ; i++ ) mp *= 2; mp--;
	/* Calculamos mp. */

	s = 4;
	for ( i = 2 ; i <= p - 1 ; i++ )
	{ s = s*s - 2; printf("%d\n",s); }
	/* Calculamos s(p-2). */

	if ( s%mp == 0 ) /* Verificamos de s eh multiplo de mp. */
	{ printf("M%d é primo.\n\n",p); }
	else
	{ printf("M%d é composto.\n\n",p); }
}
