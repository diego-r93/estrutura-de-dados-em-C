#ifndef SEARCH_H
#define SEARCH_H

int buscaLinear(int *, int, int);
int buscaOrdenada(int *, int, int);
int buscaBinaria(int *, int, int);

struct aluno
{
   int mat;
   char nome[30];
   float n1, n2, n3;
};

int buscaLinearMatricula(struct aluno *, int, int);
int buscaLinearNome(struct aluno *, int, char *);

#endif