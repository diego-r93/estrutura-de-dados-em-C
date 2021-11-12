#ifndef ORDERING_H
#define ORDERING_H

void bubleSort(int *, int);
void selectionSort(int *, int);
void insertionSort(int *, int);
void mergeSort(int *, int);
void quickSort(int *, int);
void heapSort(int *, int);

void breaking(int *, int, int);
void merge(int *, int, int, int);

int particiona(int *, int, int);
void quick(int *, int, int);

void criaHeap(int *, int, int);

struct aluno
{
   int mat;
   char nome[30];
   float n1, n2, n3;
};

void insertionSortMatricula(struct aluno *, int);
void insertionSortNome(struct aluno *, int);

#endif