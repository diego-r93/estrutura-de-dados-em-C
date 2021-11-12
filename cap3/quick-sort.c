#include "ordering.h"

int particiona(int *V, int inicio, int final)
{
   int esq, dir, pivo, aux;
   esq = inicio;
   dir = final;
   pivo = V[inicio];

   while (esq < dir)
   {
      while (V[esq] <= pivo)
         esq++;
      while (V[dir] > pivo)
         dir--;
      if (esq < dir)
      {
         aux = V[esq];
         V[esq] = V[dir];
         V[dir] = aux;
      }
   }
   V[inicio] = V[dir];
   V[dir] = pivo;

   return dir;
}

void quickSort(int *V, int N)
{
   int inicio = 0, fim = N - 1;

   quick(V, inicio, fim);
}

void quick(int *V, int inicio, int fim)
{
   int pivo;

   if (fim > inicio)
   {
      pivo = particiona(V, inicio, fim);
      quick(V, inicio, pivo - 1);
      quick(V, pivo + 1, fim);
   }
}