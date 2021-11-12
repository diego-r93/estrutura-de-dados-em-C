#include <stdio.h>
#include <stdlib.h>

#include "search.h"

int main(int argc, char const *argv[])
{
   struct aluno V[4] = {{2, "Andre", 9.5, 7.8, 8.5},
                        {4, "Ricardo", 7.5, 8.7, 6.8},
                        {1, "Bianca", 9.7, 6.7, 8.4},
                        {3, "Ana", 5.7, 6.1, 7.4}};

   int pos = buscaLinearNome(V, 4, "Andre");
   if (pos != -1)
      printf("\nNome encontrado.\n\n");
   else
      printf("\nNome NAO encontrado.\n\n");

   return 0;
}