#include <stdio.h>

int main(){
    int n;
    printf("Quantas vezes você deseja lançar o dado? ");
    scanf("%d", &n);

    int lancamentos[6] = {0};
    
    printf("Digite o resultado dos %d lançamentos que foram feitos:\n", n);
    for (int i = 0; i < n; i++){
        int resultado;
        scanf ("%d", &resultado);

        if (resultado >= 1 && resultado <= 6){
            lancamentos[resultado-1]++;
        }
        else {
            printf("Resultado inválido, o valor prescisar estar entre 1 e 6.\n");
            i--;
        }
    }
    printf("Dentre os %d lancamentos, os resultados se repetiram da seguinte forma: \n", n);
    for (int i = 0; i < 6; i++){
        printf("Resultado %d: ocorreu %d vezes\n", i+1, lancamentos[i]);
    } 
    return 0;
    }