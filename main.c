#include <mpi.h>
#include <gmp.h>
//#include <mysql/mysql.h>

#ifndef NULL
#define NULL ((void *) 0)
#endif

int getProcessorNumber(int, int *);
void mysql(void);
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

	/*
	 * Master.
	 * */
	if (rank == 0)
		for (p = 3; ; p += 2)
			MPI_Send(&p, 1, MPI_INT, getProcessorNumber(size, &processor), 0, MPI_COMM_WORLD);
	/*
	 * Slaves.
	 * */
	else
	{
		for(; ;)
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

//void mysql(void)
//{
//	MYSQL conexao;
//
//	mysql_init(&conexao);
//	if (mysql_real_connect(&conexao, "localhost", "root", "root", "teste", 0, NULL, 0))
//	{
//	    printf("conectado com sucesso!\n");
//	    mysql_close(&conexao);
//	}
//	else
//	{
//	    printf("Falha de conexao\n");
//	    printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
//	}
//}
