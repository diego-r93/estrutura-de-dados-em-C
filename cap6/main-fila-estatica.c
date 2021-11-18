#include <stdio.h>
#include <stdlib.h>

#include "FilaEstatica.h"

int main()
{
   Fila *Turma_A;
   struct aluno novoAluno[] = {{0001, "Matheus Rodrigues", 9.5, 7.8, 8.5},
                               {0002, "Diego Rodrigues", 8.5, 9.8, 8.0},
                               {0003, "Lucas Amaral", 9.2, 7.9, 8.8}

   };
   struct aluno aluno;

   Turma_A = cria_Fila();

   printf("\nTamanho da fila: %i\n", tamanho_Fila(Turma_A));

   insere_Fila(Turma_A, novoAluno[0]);
   printf("\nTamanho da fila: %i\n", tamanho_Fila(Turma_A));
   consulta_Fila(Turma_A, &aluno);
   printf("\nNome do proximo aluno: %s\n\n", aluno.nome);

   insere_Fila(Turma_A, novoAluno[1]);
   printf("\nTamanho da fila: %i\n", tamanho_Fila(Turma_A));
   consulta_Fila(Turma_A, &aluno);
   printf("\nNome do proximo aluno: %s\n\n", aluno.nome);

   insere_Fila(Turma_A, novoAluno[2]);
   printf("\nTamanho da fila: %i\n", tamanho_Fila(Turma_A));
   consulta_Fila(Turma_A, &aluno);
   printf("\nNome do proximo aluno: %s\n\n", aluno.nome);

   printf("\nMatheus saiu.\n");
   remove_Fila(Turma_A);
   printf("\nTamanho da fila: %i\n", tamanho_Fila(Turma_A));
   consulta_Fila(Turma_A, &aluno);
   printf("\nNome do proximo aluno: %s\n\n", aluno.nome);

   printf("\nDiego saiu.\n");
   remove_Fila(Turma_A);
   printf("\nTamanho da fila: %i\n", tamanho_Fila(Turma_A));
   consulta_Fila(Turma_A, &aluno);
   printf("\nNome do proximo aluno: %s\n", aluno.nome);

   printf("\nLucas saiu.\n");
   remove_Fila(Turma_A);
   printf("\nTamanho da fila: %i\n\n", tamanho_Fila(Turma_A));
   consulta_Fila(Turma_A, &aluno);
}