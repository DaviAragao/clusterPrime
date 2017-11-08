# clusterPrime
### Algorítimo para a busca de números primos de mersenne usando cluster beowulf mpi.

[Referência acadêmica.](http://sinte.btv.ifsp.edu.br/index.php/SInTE/article/view/367)

#### Usando o programa

##### Dependências

  1. [GMP](https://gmplib.org/) `sudo apt-get install libgmp3-dev`.
  
  2. [libcurl](https://curl.haxx.se/libcurl/) `sudo apt-get install libcurl4-openssl-dev`.
  
  3. [MPICH](http://www.mpich.org/) Instruções para a instalação e primeiros passos [aqui.](http://mpitutorial.com/tutorials/installing-mpich2/)
  
##### Compilação

   `make`

##### Execução do programa

   `mpirun -np 8 --hostfile hosts ./clusterPrime`
