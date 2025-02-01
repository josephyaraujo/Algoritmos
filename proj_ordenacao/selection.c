#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) { /*Funcao para ordenar o array usando o algoritmo de ordenacao por selecao. Recebe o array (arr[]) e o numero de elementos dele (n).*/
    for (int i = 0; i < n - 1; i++) { /*Esse laço mais externo vai percorrer os elementos do array até o penúltimo (n-1)
                                      isso porque como o selection ordena através da seleção do menor valor da parte não ordenada
                                      e troca esse valor com o elemento que esta ocupando a posição correta desse valor selecionado,
                                      e como isso acontece a cada iteração, o últimi elemento (n) não precisa ser comparado, considerando
                                      que ele é o último justamente por ser o maior.*/
        int menor_indice = i; /*A gente assume que o menor elemento esta ocupando a posição atual (i).
                              Fazemos isso antes de entrar no laço interno para termos um ponto de partida
                              para as comparações que se sucederão.*/
        for (int j = i + 1; j < n; j++) { /*Esse laço mais interno é usado pra percorrer os elementos restantes, por isso
                                          o j começa em i+1 (e vai até n), pq ele vai comparar o elemento na posição i com o seu seguinte
                                          na posição j, para verificar se é menor ou não, caso seja o menor_indice é atualizado.*/
            if (arr[j] < arr[menor_indice]) { /*Nesse if que é feita essa comparação.*/
                menor_indice = j; /*E aqui é feita a atualização do novo menor_indice.*/
            }
        }
                            /*Logo, após o fim do laço interno quando o medor_indice já está atualizado, procedemos com a troca*/
        int temp = arr[i];  /*caso o menor indice seja diferente de i. Armazenamos temporariamente o valoir do indice i em temp.*/
        arr[i] = arr[menor_indice]; /*atribuimos a i o valor do menor indice, para que ele ocupe a posicao correta*/
        arr[menor_indice] = temp; /*e atribuimos ao menor indice o valor de i, mudando a posicao de i para a posicao de onde veio o menor índice atualizado.*/
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
    int *arr = lerArrayDoArquivo("1000000Numeros.txt", &n); /*leitura dos numeros do arquivo txt*/

    clock_t inicio = clock(); /*funcao para medir o tempo de execucao*/

    selectionSort(arr, n); /*ordena o array usando bubble sort*/

    clock_t fim = clock();

    /*calculo e impressao do tempo de execução*/ 
    double tempoGasto = (double)(fim - inicio) *1000 / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.2f milissegundos\n", tempoGasto);
    /*Libera a memória alocada para o array*/
    free(arr);

    return 0;
}

/*Referência: https://www.geeksforgeeks.org/selection-sort-algorithm-2/*/