#include <stdio.h>

int main() {
    int numero = 28;
    int soma_divisores = 0;

    for (int i = 1; i <= numero / 2; i++) {
        if (numero % i == 0) {
            printf ("%d\n", i);
            soma_divisores += i;
        }
    }
    printf ("%d", soma_divisores);
    return 0;
}
