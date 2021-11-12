#include "ordering.h"

void insertionSort(int *V, int N)
{
   int i, j, atual;
   for (i = 1; i < N; i++)
   {
      atual = V[i];
      for (j = i; (j > 0) && (atual < V[j - 1]); j--)
      {
         V[j] = V[j - 1];
      }
      V[j] = atual;
   }
}