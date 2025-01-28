#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Função para ordenar o array usando o algoritmo de ordenação por inserção */
void ordenarPorInsercao(int arr[], int n)
{
    // Laço para percorrer o array
    for (int i = 1; i < n; ++i) {
        int chave = arr[i];  // O valor atual que será inserido na posição correta
        int j = i - 1;       // Índice para percorrer os elementos anteriores

        /* Mover os elementos de arr[0..i-1] que são maiores que a chave
           uma posição à frente de onde estavam */
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];  // Mover o elemento maior para a posição seguinte
            j = j - 1;             // Mover para o próximo elemento à esquerda
        }
        arr[j + 1] = chave;  // Colocar a chave na posição correta
    }
}
// Função para ler os números de um arquivo e retornar o array e seu tamanho
int* lerArrayDoArquivo(const char* nomeArquivo, int* n){
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    // Contar quantos números há no arquivo
    int contador = 0;
    int numero;
    while (fscanf(arquivo, "%d", &numero) != EOF) {
        contador++;
    }
    // Voltar para o começo do arquivo
    rewind(arquivo);

    // Alocar espaço para o array
    int* arr = (int*)malloc(contador * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    // Ler os números do arquivo e armazenar no array
    int i = 0;
    while (fscanf(arquivo, "%d", &arr[i]) != EOF) {
        i++;
    }

    fclose(arquivo);

    // Retornar o array e o tamanho
    *n = contador;
    return arr;
}
int main(){
    int n;
    // Lê os números de um arquivo txt
    int* arr = lerArrayDoArquivo("dados.txt", &n);

    // Medir o tempo de execução
    clock_t inicio = clock();

    // Chamar a função de ordenação
    ordenarPorInsercao(arr, n);
    
    clock_t fim = clock();

    // Calcula e imprime o tempo de execução
    double tempoGasto = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.5f segundos\n", tempoGasto);

    // Libera a memória alocada para o array
    free(arr);

    return 0;  // Finalizar o programa
}
