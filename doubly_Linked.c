#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct no {void* data; struct no* ant; struct no* prox;} No;

No* insere(No* lista, int data) {

	No* new_data = (No*) malloc(sizeof(No));
	new_data->ant = NULL;
	new_data->data = (void* ) (intptr_t) data;
	new_data->prox = lista;
	if (lista != NULL) lista->ant = new_data;
	return new_data;

}

void imprime(No* lista) 
{
	if (lista != NULL) 
	{
		No* p = lista;
		while ( p != NULL) {
			printf("%d \n", (int) (intptr_t) p->data);
			p = p->prox;
		}
		return;
	}
	printf("Empty list");
}

No* retira(No* lista, int value) {

	No* no = lista;
	while( no != NULL) {
		if( (intptr_t) no->data == value) {
				if (no->ant == NULL) {
					lista = lista->prox;
					if (lista != NULL) lista->ant = NULL;
				}

				else {
					no->ant->prox = no->prox;
					if (no->prox != NULL) no->prox->ant = no->ant;
				}
			free(no);
			return lista;
		
		}
		no = no->prox;	
	}
	return NULL;
}

int main() {
	No* lista0 = NULL;
	lista0 = insere(lista0, 0);
	lista0 = insere(lista0, 1);
	lista0 = insere(lista0, 2);
	imprime(lista0);
	lista0 = retira(lista0, 0);
	imprime(lista0);

}
