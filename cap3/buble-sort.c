#include "ordering.h"

void bubleSort(int *V, int N)
{
   int i, continua, aux, fim = N;

   do
   {
      continua = 0;

      for (i = 0; i < fim - 1; i++)
      {
         if (V[i] > V[i + 1])
         {
            aux = V[i];
            V[i] = V[i + 1];
            V[i + 1] = aux;
            continua = i;
         }
      }
      fim--;
   } while (continua != 0);
}