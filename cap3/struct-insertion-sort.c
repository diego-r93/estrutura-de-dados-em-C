#include <string.h>

#include "ordering.h"

void insertionSortMatricula(struct aluno *V, int N)
{
   int i, j;
   struct aluno aux;
   for (i = 1; i < N; i++)
   {
      aux = V[i];
      for (j = i; (j > 0) && (aux.mat < V[j - 1].mat); j--)
      {
         V[j] = V[j - 1];
      }
      V[j] = aux;
   }
}

void insertionSortNome(struct aluno *V, int N)
{
   int i, j;
   struct aluno aux;
   for (i = 1; i < N; i++)
   {
      aux = V[i];
      for (j = i; (j > 0) && (strcmp(aux.nome, V[j - 1].nome) < 0); j--)
      {
         V[j] = V[j - 1];
      }
      V[j] = aux;
   }
}