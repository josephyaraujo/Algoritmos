#include <stdio.h>
int main (){
    int n;
    printf ("Quantos números terão na sua coleção? ");
    scanf ("%d", &n);

    int colecao[n];

    printf("Digite os %d números desejados, com espaço entre eles:\n", n);
    for (int i = 0; i < n; i++){
        scanf ("%d", &colecao[i]);
    }
    printf("A coleção de números na ordem inversa é a seguinte:\n");
    for (int i = n-1; i >= 0; i--){
        printf ("%d ", colecao[i]);
    }
    printf("\n");
    return 0;
}
