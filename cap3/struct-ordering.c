#include <stdio.h>
#include <stdlib.h>

#include "ordering.h"

int main(int argc, char const *argv[])
{
   int i;
   struct aluno V[4] = {{2, "Andre", 9.5, 7.8, 8.5},
                        {4, "Ricardo", 7.5, 8.7, 6.8},
                        {1, "Bianca", 9.7, 6.7, 8.4},
                        {3, "Ana", 5.7, 6.1, 7.4}};

   insertionSortNome(V, 4);

   for (i = 0; i < 4; i++)
      printf("%d) %s\n", V[i].mat, V[i].nome);

   return 0;
}