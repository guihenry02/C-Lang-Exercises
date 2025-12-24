#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef struct Node {void *data; struct Node* next;} Node;
typedef struct {Node *tail;} CircularList;

CircularList* insere(CircularList* list, int value) {
	Node* new_node = (Node*) malloc(sizeof(Node));
	new_node->data = (void*)(intptr_t)value; 
	if (list->tail == NULL) {
		new_node->next = new_node;
		list->tail = new_node;
	}
	else {
		new_node->next = list->tail->next;
		list->tail->next = new_node;
		list->tail = new_node;
	}

	return list;
}

void imprime(CircularList* list) {
	
	Node* p = list->tail->next;
	Node* head = p;

	do {
		printf("%d\n", (int)(intptr_t)p->data);
		p = p->next;	

	} while(p != head);
	
}

void retirar(CircularList* list, int value) {

	Node* p = list->tail->next;
	Node* head = p;
	Node* ant = list->tail;
	do {
		if ((int)(intptr_t)p->data == value) {
			if (p == ant && p == p->next) {
				list->tail = NULL;
			}
			
			else {
				ant->next = p->next;
				if (p == list->tail) {
					list->tail = ant;
				}
			}

			free(p);
			return;
		}

		ant = p;
		p = p->next;
	} while(p != head);
}

int main() {
	CircularList* lista = (CircularList*) malloc(sizeof(CircularList));
	lista->tail = NULL;
	insere(lista, 32);
	insere(lista, 30);
	imprime(lista);
	retirar(lista, 32);
	imprime(lista);
}
