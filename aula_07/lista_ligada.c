#include <stdio.h>
#include <stdlib.h>

struct Node* inicio = NULL;
struct Node* fim = NULL;

struct Node {
    int valor;
    struct Node* anterior;
    struct Node* proximo;
    
}; 

int main() {
    struct Node* novo = (struct Node*)malloc(sizeof(struct Node));
    novo->valor = 10;
    novo->anterior = inicio;
    novo->proximo = fim;
    inicio = novo; 
    fim = novo;
    
    printf ("%d ", novo->anterior);
    printf ("%d ", inicio->valor);
    printf ("%d ", novo->proximo);

    novo->valor = 5;
    novo->anterior = fim;
    novo->proximo = NULL; 
    fim->proximo = novo; 
    fim = novo;    
    
    printf ("%d ", novo->anterior);
    printf ("%d ", inicio->valor);
    printf ("%d ", novo->proximo);

    return 0;
}




