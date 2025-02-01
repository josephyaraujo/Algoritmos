#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) { /*Funcao para ordenar o array usando o algoritmo de ordenacao por insercao. Recebe o array (arr[]) e o numero de elementos dele (n).*/
    for (int i = 1; i < n; ++i) { /*Aqui usamos um laco para percorrer o array, ele comeca em 1 (i = 1), porque temos o primeiro elemento do array ja como "ordenado",*/
                                  /*em consequencia, o laco em si, so comeca no segundo elemento do array, o qual sera comparado com o primeiro para seguir com a ordenacao.*/
        int valorAtual = arr[i];  /*Essa variavel armazena o valor do elemento do indice i. Ele serah comparado com os elementos anteriorese e sem seguida inserido na posicao correta.*/     
        int j = i - 1;            /*Essa variavel serve ao segundo laco, que ira percorrer os elementos a esquerda do valorAtaul, para assim encontrar o lugar correto do valorAtual.*/
                                     
        while (j >= 0 && arr[j] > valorAtual) { /*O while compara o valor do elemento arr[j] com o valorAtual. Se o valor de arr[j] for maior que valorAtual, ele move o elemento para uma posicao a frente*/
            arr[j + 1] = arr[j]; /*no caso para o indice j+1, e diminui j, para seguir na verificacao dos elementos anteriores.*/ 
            j = j - 1;           /*o laco segue ate achar um elemento menor ou igual ao valorAtual ou ate chegar no inicio do array*/  
        }
        arr[j + 1] = valorAtual;  /*Insere o elemento do valorAtual na posicaoo correta da ordenacao*/
    }
}
int *lerArrayDoArquivo(const char *filename, int *n){
    FILE *arquivo = fopen(filename, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    int contador = 0;
    int numero;
    while (fscanf(arquivo, "%d", &numero) != EOF) {
        contador++;
    }
    rewind(arquivo);
      int *arr = (int*)malloc(contador *sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(arquivo, "%d", &arr[i]) != EOF) {
        i++;
    }

    fclose(arquivo);
    
    *n = contador;
    return arr;
}
int main(){
    int n;
    int *arr = lerArrayDoArquivo("100Numeros.txt", &n);

    clock_t inicio = clock();

    insertionSort(arr, n);
    
    clock_t fim = clock();

    double tempoGasto = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.2f milissegundos\n", tempoGasto);

    free(arr);

    return 0;  
}
/*Referência: https://www.geeksforgeeks.org/insertion-sort-algorithm/*/