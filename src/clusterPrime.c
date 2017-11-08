#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <mpi.h>
#include <gmp.h>
#include "database.h"

#ifndef NULL
#define NULL ((void *) 0)
#endif

int getProcessorNumber(int, int *);
char *getMacAddres();
char *getHostName();

int main()
{
	int i, p, expoente, size, rank, processor = 0;
	MPI_Status status;
	mpz_t mersenneNumber, s, aux;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	mpz_init(mersenneNumber);
	mpz_init(s);
	mpz_init(aux);

	if (rank == 0)
	{
		while(1)
		{
			p = getNextPrime();
			MPI_Send(&p, 1, MPI_INT, getProcessorNumber(size, &processor), 0, MPI_COMM_WORLD);
		}
	}
	else
	{
		while(1)
		{
			MPI_Recv(&expoente, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
			mpz_ui_pow_ui(mersenneNumber, (long)(2), expoente);
			mpz_sub_ui(mersenneNumber, mersenneNumber, (long)(1));
			mpz_set_ui(s, (long)(4));

			for (i = 1; i <= expoente - 2; i++)
			{
				mpz_powm_ui(aux, s, (long)(2), mersenneNumber); 
				mpz_sub_ui(s, aux, (long)(2)); 
			}

			putPrime(expoente, getMacAddres(), getHostName(), (mpz_sgn(s) == 0));
			if (mpz_sgn(s) == 0)
				gmp_printf("Processador: %d - M%d%c%Zd %c%c", rank, expoente, 10, mersenneNumber, 10, 10);
		}
	}

	MPI_Finalize();
}

int getProcessorNumber(int size, int *processor)
{
	if (++(*processor) >= size)
		*processor = 1;
	return *processor;
}

char *getMacAddres()
{
	int fd;
	struct ifreq ifr;
	char *iface = "em1";
	static char macAddres[50];
	unsigned char *mac;

	fd = socket(AF_INET, SOCK_DGRAM, 0);

	ifr.ifr_addr.sa_family = AF_INET;
	strncpy(ifr.ifr_name , iface , IFNAMSIZ-1);

	ioctl(fd, SIOCGIFHWADDR, &ifr);

	close(fd);

	mac = (unsigned char *)ifr.ifr_hwaddr.sa_data;

	sprintf(macAddres, "%.2x:%.2x:%.2x:%.2x:%.2x:%.2x" , mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

	return macAddres;
}


char *getHostName()
{
	static char name[150];
	gethostname(name, 150);

	return name;
}
