#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int soma, dado1, dado2;
	char continua;

	srand (time(NULL));

	do {
	    printf("Lance o primeiro dado\n");
	    dado1 = rand() % 6 + 1;
	    printf("Lance o segundo dado\n");
	    dado2 = rand() % 6 + 1;

	    soma = dado1+dado2;
	    
		printf("O primeiro dado deu: %d\n", dado1);
        printf("O segundo dado deu: %d\n", dado2);
		printf("A soma entre os dados foi:%d\n", soma);
		
		 if (soma == 7) {
            printf("7 é seu numero da sorte! Mandou bem!\n");
        } else if (soma == 11) {
            printf("11 foi uma jogada e tanto, truque de mestres!\n");
        } else {
            printf("Ande as casas correspondentes.\n");
	    }
	      printf("Deseja jogar os dados mais uma vez? (Y/N): ");
        scanf(" %c", &continua);

    } 
    while (continua == 'Y' || continua == 'y');

    printf("Finalizando as jogadas!\n");
    return 0;
}
