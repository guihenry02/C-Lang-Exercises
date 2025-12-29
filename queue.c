#include <stdio.h>
#include <stdlib.h>

typedef struct no {float value; struct no* prox;} No;
typedef struct queue {No* start; No* end;} Queue;

Queue* ins_end(Queue* f, float value) {

	No* no = (No*) malloc(sizeof(No));
	no->prox = NULL;
	no->value = value;

	if (f->end != NULL) {
		f->end->prox = no;
	}

	else {
		f->start = no;
	}

	f->end = no;
}


void rem_beg(Queue* f) {

	No* t;
	t = f->start;
	f->start = t->prox;	
	if (f->start == NULL) f->end = NULL;
	free(t);
}

void print(Queue* f) {

	No* t;
	for (t = f->start; t != NULL; t = t->prox) printf("%2.f \t", t->value);

}

Queue* create(void) {
	Queue* a = (Queue*) malloc(sizeof(Queue));
	a->start = a->end = NULL;
	return a;
}

int main() {
	Queue* a = create();
	a = ins_end(a, 0);
	a = ins_end(a, 1);
	a = ins_end(a, 2);
	print(a);
	rem_beg(a);
	rem_beg(a);
	print(a);


}
