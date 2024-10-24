#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int dado1, dado2;
    printf("Lance o primeiro dado:\n");
    srand(time(0));
    dado1 = rand() % 5 + 1;
    printf("Lance o segundo dado:\n");
    dado2 = rand() % 5 + 1;
    
    do{
        printf("A soma entre os dados foi:%d\n", dado1+dado2);
    } 
    
    while (dado1+dado2 != 0);
    
    return 0;
}
