#include <stdio.h>
#include <stdlib.h>

struct Node* inicio = NULL;

struct Node {
    int valor;
    struct Node* proximo;
}; 

int main() {
    struct Node* novo = (struct Node*)malloc(sizeof(struct Node));
    novo->valor = 10;
    novo->proximo = inicio; 
    inicio = novo;
    
    return 0;
}




