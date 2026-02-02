#include <stdio.h>

void trocar(int* a, int* b);
int particionar(int* array, int left, int right);
void quickSort(int arr[], int low, int high);
void imprimirArray(int arr[], int tamanho);

void trocar(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particionar(int* array, int left, int right) {
    int pivot = array[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            trocar(&array[i], &array[j]);
        }
    }
    trocar(&array[i + 1], &array[right]);
    return (i + 1); // Retorna a posição do pivô
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = particionar(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void imprimirArray(int arr[], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", arr[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int dados[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(dados) / sizeof(dados[0]);

    printf("Array original: ");
    imprimirArray(dados, n);

    quickSort(dados, 0, n - 1);

    printf("Array ordenado: ");
    imprimirArray(dados, n);

    return 0;
}
