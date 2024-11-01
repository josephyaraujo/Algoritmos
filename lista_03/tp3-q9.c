#include <stdio.h>

int main(){
    char string [100];
    int contador = 0;
    int i = 0;

    printf("Digite uma sequência aleatória de 0 e 1:\n");
    scanf("%s", string);

    while (string[i] != '\0'){
        if (string[i] == '1'){
            contador++;
        }
    i++;
    }
    printf ("O numero 1 aparece %d vezes nessa sequência.\n", contador);
    return 0;
}