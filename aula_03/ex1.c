#include <stdio.h>

void imprimir(int numeros[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", numeros[i]);
    }
} 

int main() {
    int numeros[5] = {10, 20, 30, 40, 50};

    imprimir(numeros, 5);

    return 0;
}
