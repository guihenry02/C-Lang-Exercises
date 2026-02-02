#include <stdio.h>
#include <stdlib.h>

typedef struct { float x; float y; float z;} Point;
typedef struct no { Point* point; struct no* next;} No; 

struct no* createNode(float x, float y, float z) {
	No* newNode = (No*)malloc(sizeof(No));
	if (newNode == NULL) {
		perror("Erro ao alocar memoria");
		exit(1);
	}
	Point* p = (Point*)malloc(sizeof(Point));
	if (p == NULL) {
		perror("Erro ao alocar memoria para ponto");
		free(newNode);
		exit(1);
	}
	p->x = x;
	p->y = y;
	p->z = z;
	newNode->point = p;
	newNode->next = NULL;
	return newNode;
}

void createFile(char* filename, char* content) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
}

void printList(No* head) {
    if (head == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    printf("\n=== LISTA DE PONTOS ===\n");
    No* current = head;
    int count = 1;
    
    while (current != NULL) {
        printf("Ponto %d: (%.2f, %.2f, %.2f)\n", 
               count, current->point->x, current->point->y, current->point->z);
        current = current->next;
        count++;
    }
    printf("=======================\n");
}

void freeList(No* head) {
    No* current = head;
    No* next;
    
    while (current != NULL) {
        next = current->next;
        free(current->point);  // Libera o Point
        free(current);         // Libera o nó
        current = next;
    }
}

No* insertAtEnd(No* head, float x, float y, float z) {
    No* newNode = createNode(x, y, z);
    
    if (head == NULL) {
        return newNode;
    }
    
    No* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    
    return head;
}

No* findPoint(No* head, float x, float y, float z) {
    No* current = head;
    
    while (current != NULL) {
        Point* p = current->point;
        if (p->x == x && p->y == y && p->z == z) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;  // Não encontrado
}

int main() {
    char str[100]; 
    FILE* fp;
	No* head = NULL;   // Lista inicialmente vazia
	No* current = NULL;
    float x, y, z;

    createFile("example.txt", "10.0 4.3 20.5\n5.5 6.6 7.7\n10.1 11.2 0.0");
    
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    while (fgets(str, sizeof(str), fp) != NULL) { 
        x = y = z = 0; 
        int n = sscanf(str, "%f %f %f", &x, &y, &z);
		
        if (n == 3) {  // Se conseguiu ler 3 valores
            No* newNode = createNode(x, y, z);
            
            // Inserir no final da lista
            if (head == NULL) {
                head = newNode;
                current = head;
            } else {
                current->next = newNode;
                current = newNode;
            }
            
            printf("Ponto lido: (%.2f, %.2f, %.2f)\n", x, y, z);
        }
    }

    fclose(fp);
    
    // Demonstração do uso da lista
    printList(head);
    
    // Exemplo de inserção de um novo ponto
    printf("\nInserindo novo ponto (1.1, 2.2, 3.3)...\n");
    head = insertAtEnd(head, 1.1, 2.2, 3.3);
    printList(head);
    
    // Exemplo de busca
    printf("\nProcurando ponto (5.5, 6.6, 7.7)...\n");
    No* found = findPoint(head, 5.5, 6.6, 7.7);
    if (found != NULL) {
        printf("Ponto encontrado: (%.2f, %.2f, %.2f)\n", 
               found->point->x, found->point->y, found->point->z);
    } else {
        printf("Ponto não encontrado.\n");
    }
    
    // Liberar memória
    freeList(head);
    printf("\nMemória liberada. Lista destruída.\n");
    
    return 0;
}