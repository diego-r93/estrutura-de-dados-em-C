#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 10000

struct arquivo
{
   FILE *f;
   int pos, MAX, *buffer;
};

void quickSort(int *v, int inicio, int fim)
{
   int i = inicio, j = fim, aux, meio, x;
   meio = (inicio + fim) / 2;
   x = v[meio];
   while (i <= j)
   {
      if (v[i] < x)
         i++;
      else if (v[j] > x)
         j--;
      else
      {
         aux = v[i];
         v[i++] = v[j];
         v[j--] = aux;
      }
   }
   if (inicio < j)
      quickSort(v, inicio, j);
   if (fim > i)
      quickSort(v, i, fim);
}

void criaArquivoTeste(char *nome)
{
   int i;
   FILE *myFile = fopen(nome, "w");
   srand(time(NULL));

   for (i = 1; i < 9000; i++)
      fprintf(myFile, "%d\n", rand());
   fprintf(myFile, "%d", rand());
   fclose(myFile);
}

void salvaArquivo(char *nome, int *V, int tam, int mudaLinhaFinal)
{
   int i;
   FILE *myFile = fopen(nome, "a");

   for (i = 0; i < tam - 1; i++)
      fprintf(myFile, "%d\n", V[i]);

   if (mudaLinhaFinal == 0)
      fprintf(myFile, "%d", V[tam - 1]);
   else
      fprintf(myFile, "%d\n", V[tam - 1]);

   fclose(myFile);
}

int criaArquivosOrdenados(char *nome)
{
   int V[NUMBER];
   char novo[20];
   int K = 0, total = 0;
   FILE *myFile = fopen(nome, "r");

   while (!feof(myFile))
   {
      fscanf(myFile, "%d", &V[total]);
      total++;

      if (total == NUMBER)
      {
         K++;
         sprintf(novo, "Temp%d.txt", K);
         quickSort(V, 0, total - 1);
         salvaArquivo(novo, V, total, 0);
         total = 0;
      }
   }

   if (total > 0)
   {
      K++;
      sprintf(novo, "Temp%d.txt", K);
      quickSort(V, 0, total - 1);
      salvaArquivo(novo, V, total, 0);
   }

   fclose(myFile);
   return K;
}

void preencheBuffer(struct arquivo *arq, int T)
{
   int i;

   if (arq->f == NULL)
      return;

   arq->pos = 0;
   arq->MAX = 0;

   for (i = 0; i < T; i++)
   {
      if (!feof(arq->f))
      {
         fscanf(arq->f, "%d", &arq->buffer[arq->MAX]);
         arq->MAX++;
      }
      else
      {
         fclose(arq->f);
         arq->f = NULL;
         break;
      }
   }
}

int procuraMenor(struct arquivo *arq, int K, int T, int *menor)
{
   int i, idx = -1;

   for (i = 0; i < K; i++)
   {
      if (arq[i].pos < arq[i].MAX)
      {
         if (idx == -1)
            idx = i;
         else
         {
            if (arq[i].buffer[arq[i].pos] < arq[idx].buffer[arq[idx].pos])
               idx = i;
         }
      }
   }

   if (idx != -1)
   {
      *menor = arq[idx].buffer[arq[idx].pos];
      arq[idx].pos++;

      if (arq[idx].pos == arq[idx].MAX)
         preencheBuffer(&arq[idx], T);

      return 1;
   }
   else
      return 0;
}

void merge(char *nome, int K, int T)
{
   char novo[20];
   int i;
   int *saida = (int *)malloc(T * sizeof(int));
   struct arquivo *arq;
   arq = (struct arquivo *)malloc(K * sizeof(struct arquivo));

   for (i = 0; i < K; i++)
   {
      sprintf(novo, "Temp%d.txt", i + 1);
      arq[i].f = fopen(novo, "r");
      arq[i].buffer = (int *)malloc(T * sizeof(int));
      preencheBuffer(&arq[i], T);
   }

   int menor, qtdSaida = 0;
   while (procuraMenor(arq, K, T, &menor) == 1)
   {
      saida[qtdSaida] = menor;
      qtdSaida++;

      if (qtdSaida == T)
      {
         salvaArquivo(nome, saida, T, 1);
         qtdSaida = 0;
      }
   }

   if (qtdSaida != 0)
      salvaArquivo(nome, saida, qtdSaida, 1);

   for (i = 0; i < K; i++)
      free(arq[i].buffer);

   free(arq);
   free(saida);
}

void mergeSortExterno(char *origem, char *destino)
{
   char novo[20];
   int K = criaArquivosOrdenados(origem);
   int i, T = NUMBER / (K + 1);

   merge(destino, K, T);

   for (i = 0; i < K; i++)
   {
      sprintf(novo, "Temp%d.txt", i + 1);
      remove(novo);
   }
}

int main()
{
   // criaArquivoTeste("ordenados.txt");
   mergeSortExterno("desordenados.txt", "ordenados.txt");

   return 0;
}