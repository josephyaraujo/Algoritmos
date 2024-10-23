#include <stdio.h>

int main() {
    int n1, n2, maior, menor, mdc;
    printf("Digite dois números: ");
    scanf("%d %d", &n1, &n2);
    
    if (n1 > n2){
        maior = n1;
        menor = n2;
    }
    else{
        maior = n2;
        menor = n1;
    }
    mdc = 1;
    
    for (int i = 2; i < menor; i++) {
        if (maior%i == 0 && menor%i == 0){
            mdc = i;
        }
    }    
    printf ("%d", mdc);
    return 0;
}
