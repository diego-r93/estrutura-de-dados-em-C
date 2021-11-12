#include <stdio.h>
#include <stdlib.h>

#include "ponto.h"

int main()
{
   float d;
   Ponto *p, *q;

   p = Ponto_cria(10, 21);
   q = Ponto_cria(7, 25);

   d = Ponto_distancia(p, q);
   printf("\nDistancia entre os pontos p e q: %.2f\n\n", d);

   Ponto_libera(p);
   Ponto_libera(q);

   return 0;
}