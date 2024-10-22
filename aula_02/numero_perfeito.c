#include <stdio.h>

int main() {
    int numero = 28;
    int soma_divisores = 0;

    for (int i = 1; i <= numero / 2; i++) {
        if (numero % i == 0) {
            print (i)
            soma_divisores += i;
            print (soma_divisores)
        }
    }

    if (soma_divisores == numero) {
        printf("O número é perfeito\n");
    } else {
        printf("O número não é perfeito\n");
    }

    return 0;
}
