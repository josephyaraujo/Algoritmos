#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int i1, int j1, int i2, int j2) {
    int size = (j1 - i1 + 1) + (j2 - i2 + 1);
    int *arrayTemp = (int *)malloc(size * sizeof(int));
    int i = i1, j = i2, k = 0;

    while (i <= j1 && j <= j2) {
        if (arr[i] < arr[j]) {
            arrayTemp[k++] = arr[i++];
        } else {
            arrayTemp[k++] = arr[j++];
        }
    }

    while (i <= j1) {
        arrayTemp[k++] = arr[i++];
    }

    while (j <= j2) {
        arrayTemp[k++] = arr[j++];
    }

    for (i = i1, j = 0; i <= j2; i++, j++) {
        arr[i] = arrayTemp[j];
    }

    free(arrayTemp);
}

void sort(int arr[], int primeiro, int ultimo) {
    int meio;
    if (primeiro < ultimo) {
        meio = (primeiro + ultimo) / 2;
        sort(arr, primeiro, meio);
        sort(arr, meio + 1, ultimo);
        merge(arr, primeiro, meio, meio + 1, ultimo);
    }
}
int *lerArrayDoArquivo(const char *filename, int *n){ /*essa funcao sera responsavel por ler os números do arquivo e retornar o array e seu tamanho*/
    FILE *arquivo = fopen(filename, "r"); /*esse f na frente do open eh tipo f de file, pra dizer que vai abrir o arquivo*/
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    int contador = 0; /*esse contador vai ser usado para verificar quantos números existem no arquivo*/
    int numero;
    while (fscanf(arquivo, "%d", &numero) != EOF) { /*por issso tambem tem o f aqui, na frente do scanf, que eh pra dizer que ta lendo o dado do arquivo. esse laco que vai percorrer o arquivo, lendo os nuemeros um por um para poder adicionar aos contador*/
        contador++;
    }
    rewind(arquivo); /*apos contar os numeros a funcao rewind faz o ponteiro de leitura voltar ao inicio do arquivo*/

    int* arr = (int*)malloc(contador *sizeof(int)); /*aqui eh onde sera alocada a memoria, em um array, com tamanho necessario para armazenar os numeros*/
    if (arr == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(arquivo, "%d", &arr[i]) != EOF) {  /*aqui os numeros do arquivo serao lidos novamente e armazenados no array criado na funcao acima dessa*/
        i++;
    }
    fclose(arquivo); /*para fechar o arquivo pos leitura*/

    /*Retorna o array e o tamanho*/ 
    *n = contador;
    return arr;
}
int main(){
    int n;
    int *arr = lerArrayDoArquivo("100Numeros.txt", &n); /*leitura dos numeros do arquivo txt*/

    clock_t inicio = clock(); /*funcao para medir o tempo de execucao*/

    sort(arr, 0, n-1); /*ordena o array usando bubble sort*/

    clock_t fim = clock();

    /*calculo e impressao do tempo de execução*/ 
    double tempoGasto = (double)(fim - inicio) *1000 / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.2f milissegundos\n", tempoGasto);
    /*Libera a memória alocada para o array*/
    free(arr);

    return 0;
}

/*Referência: https://www.geeksforgeeks.org/merge-sort/*/