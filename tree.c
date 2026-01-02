#include <stdio.h>
#include <stdlib.h>

typedef struct arv {char info; struct arv* esq; struct arv* dir;} Arv;

Arv* cria(char info, Arv* sae, Arv* sad)
{
	Arv* a = (Arv*) malloc(sizeof(Arv));
	a->info = info;
	a->esq = sae;
	a->dir = sad;
	return a;
}

void imprime(Arv* a)
{
	if( a != NULL ){
		printf("%c ", a->info);
		imprime(a->esq);
		imprime(a->dir);
	}
}

int altura(Arv* raiz) {

	if (raiz == NULL) {
		return -1 ;
	}
	else {
		int esq = altura(raiz->esq);
		int dir = altura(raiz->dir);
		if(esq > dir)
			return esq + 1;
		else
			return dir + 1;
	}

	
}

int busca (Arv a*, char c) {
	if (a == NULL) return 0
	else return a->info == c || busca(a->esq, c)|| busca(a->dir, c);
}

int main() {

	Arv* a = cria('a', 
			cria('b', NULL,	cria('d', NULL, NULL)),
			cria('c', cria('e', NULL, NULL), cria('f', NULL, NULL)));
	imprime(a);
	printf("%d",altura(a));
	
	
}
