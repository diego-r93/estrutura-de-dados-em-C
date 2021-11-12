#include <stdio.h>
#include <time.h>

#include "vector-1kk.h"
#include "ordering.h"
#include "search.h"

int main(int argc, char const *argv[])
{
   clock_t t;
   int size, busca, valorProcurado = 1330462196;

   size = sizeof(myVector) / sizeof(myVector[0]);

   t = clock();
   // heapSort(myVector, size);
   busca = buscaLinear(myVector, size, valorProcurado);
   t = clock() - t;

   if (busca == -1)
      printf("\n\nO valor %i nao foi encontrado.", valorProcurado);
   else
      printf("\n\nO valor %i pertence ao array.", valorProcurado);

   printf("\n\nTempo de execucao: %.4lf milissegundos\n\n", ((double)t) / ((CLOCKS_PER_SEC / 1000)));

   return 0;
}