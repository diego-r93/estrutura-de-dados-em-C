#include <stdio.h>
#include <time.h>

#include "vector-1kk.h"
#include "ordering.h"

int main(int argc, char const *argv[])
{
   clock_t t;
   int indice, size;

   size = sizeof(myVector) / sizeof(myVector[0]);

   t = clock();
   heapSort(myVector, size);
   t = clock() - t;

   printf("\nVetor ordenado: ");
   for (indice = 0; indice < size; indice++)
   {
      printf("%i ", myVector[indice]);
   }
   printf("\n\nTempo de execucao: %.4lf milissegundos\n\n", ((double)t) / ((CLOCKS_PER_SEC / 1000)));

   return 0;
}