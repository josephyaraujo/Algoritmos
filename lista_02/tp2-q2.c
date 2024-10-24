#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int numero_secreto, palpite;
    
    srand(time(0));
    numero_secreto = rand() % 100 + 1;
    
    printf("Vamos jogar um jogo?\n");
    printf("Tente advinhar o numero que estou pensando entre 0 e 100\n");
    
    do{
        printf("Digite seu palpite: \n");
        scanf("%d", &palpite);
        
        if (palpite < numero_secreto){
            printf("Muito baixo, Tente Novamente!\n"); 
        }
        else if (palpite > numero_secreto){
            printf("Muito alto, Tente Novamente!\n");
        }
        else{
            printf("Parabens!, Voce acertou!\n");
        }

    } 
    
    while (palpite != numero_secreto);
    
    return 0;
}
