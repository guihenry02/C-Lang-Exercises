#include <stdio.h>
#include <stdlib.h>


typedef struct no {float info; struct no* prox;} No;
typedef struct {No* first;} Stack;

Stack* create() {
	Stack* p = (Stack*) malloc(sizeof(Stack));
	p->first = NULL;
	return p;
}

Stack* push(Stack* stack, float value) {
	No* no = (No*) malloc(sizeof(No));
	no->info = value;
	no->prox = stack->first;
	stack->first = no;
	return stack;
}

float pop(Stack* stack) {

	No* p = stack->first;
	float v = p->info;
	stack->first = p->prox;
	free(p);
	return v;
}

void imprime(Stack* stack) 
{
	No* p;
	for(p = stack->first; p != NULL; p = p->prox) {
		printf("%f \n",p->info);
	}
}

int main() {
	Stack* p = create();
	p = push(p, 0.5);
	p = push(p, 1.1);
	p = push(p, 2.0);
	imprime(p);
	pop(p);
	pop(p);
	imprime(p);

}
