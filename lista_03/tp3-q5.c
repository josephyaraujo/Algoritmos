#include <stdio.h>

typedef struct {
    float numero;
    int contador;    
}indice;

int main(){
    int n, i, j, novo;
    printf("Quantos números reais você deseja digitar? ");
    scanf("%d", &n);

    float sequencia[n];
    
    printf("Digite os %d números reais abaixo, utilize espaço entre eles:\n", n);
    for (i = 0; i < n; i++){
        scanf ("%f", &sequencia[i]);
    }
    indice elementos[n];
    int totalElementos = 0;

    for (i = 0; i < n; i++){
        novo = 0;
        for (j = 0; j < totalElementos; j++){
            if (elementos[j].numero == sequencia[i]) {
                elementos[j].contador++;
                novo = 1;
                break;
            }
        }
        if (!novo) {
        elementos[totalElementos].numero = sequencia[i];
        elementos[totalElementos].contador = 1;
        totalElementos++;
        }
    }
    printf("\nNúmeros digitados e a frequência com que foram repetidos:\n");
    for (i = 0; i < totalElementos; i++) {
        printf("%.2f ocorre %d vezes\n", elementos[i].numero, elementos[i].contador);
    }
    return 0;
    }