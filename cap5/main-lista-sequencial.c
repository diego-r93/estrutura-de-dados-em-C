#include <stdio.h>
#include <stdlib.h>

#include "ListaSequencial.h"

int main()
{
   Lista *Turma_A;

   Turma_A = cria_lista();

   printf("\nTamanho da lista: %i\n\n", tamanho_lista(Turma_A));

   struct aluno novoAluno = {1234, "Matheus Rodrigues", 9.5, 7.8, 8.5};

   insere_lista_inicio(Turma_A, novoAluno);

   printf("\nTamanho da lista: %i\n\n", tamanho_lista(Turma_A));

   return 0;
}