#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct {int ini; int fim; float vet[MAX];} Fila2;

Fila2* inicializa() 
{
	Fila2* fila = (Fila2*) malloc(sizeof(Fila2));
	fila->ini = fila->fim = 0;
	return fila;
}

void insere_ini(Fila2* f, float v) {
	f->ini--;
	if (f->ini < 0) f->ini = MAX - 1;

	if (f->ini == f->fim) {
		printf("Ta cheio essa porra");
		exit(1);
	}

	f->vet[f->ini] = v;

}

void insere_fin(Fila2* f, float v) {
	
	if ((f->fim+1) % MAX == f->ini) {
		printf("Ta cheio");
		exit(1);
	}

	f->vet[f->fim] = v;
	f->fim = (f->fim + 1) % MAX;
}

float rem_ini(Fila2* f) {
	float v = f->vet[f->ini];
	f->vet[f->ini] = 0;
	f->ini = (f->ini + 1) % MAX;
	return v;
}

float rem_fin(Fila2* f) {

	float v = f->vet[f->fim];
	f->vet[f->fim] = 0;
	f->fim--;
	if (f->fim < 0) f->fim = MAX - 1;
	return v;

}

void imprime(Fila2* f) {

	int a;
	for (a = f->ini; a != f->fim; a = (a+1) % MAX) {
		printf("%.1f \n", f->vet[a]);		
	}

}


int main() {

	Fila2* fila = inicializa();
	insere_fin(fila, 10.0);
	insere_fin(fila,20.0);
	insere_ini(fila, 5.0);
	imprime(fila);
	rem_ini(fila);
	rem_fin(fila);
	imprime(fila);
}
