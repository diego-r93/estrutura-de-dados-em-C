#ifndef PONTO_H
#define PONTO_H

typedef struct ponto Ponto;

Ponto *Ponto_cria(float, float);
void Ponto_libera(Ponto *);
int Ponto_acessa(Ponto *, float *, float *);
int Ponto_atribui(Ponto *, float, float);
float Ponto_distancia(Ponto *, Ponto *);

#endif