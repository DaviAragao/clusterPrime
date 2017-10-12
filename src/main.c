#include <mpi.h>
#include <gmp.h>
#include "database.h"

#ifndef NULL
#define NULL ((void *) 0)
#endif

int getProcessorNumber(int, int *);

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
		p = getNextPrime();
		putPrime(p, "34:64:a9:00:d0:23", "aragao", true);
		while(1)
		{
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
