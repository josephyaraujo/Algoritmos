#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Função que realiza a partição do array original por meio do estabelecimento de um elemento pivô, que irá ser usado para determinar um sub-array antetior e posterior este elemento*/
int particao(int arr[], int primeiro, int ultimo) {
    int pivo = arr[ultimo]; /*Definição do pivô como o último elemento do array. Ele será o elemento de comparação.*/
    int i = primeiro - 1; /*Definição do menor índice do array. O índice i mantém a posição em que os elementos menores que o pivô serão alocados. É importante ressaltar que ele começa
    primeiro -1, pelo fato de ainda não existirem elementos ordenados.*/

    for (int j = primeiro; j <= ultimo - 1; j++) { /*Nesse primeiro laço serão percorridos os elementos do primeiro índice até o elemento anterior ao pivô*/
        if (arr[j] < pivo) { /*Se o elemento em questão for menor que o pivô*/
            i++; /*O índice i é incrementado, para continuar a organizar os elementos menores à esquerda do pivô*/
            /*E troca os elementos a[i] e a[j] para alocar os elementos menores na posição correta*/
            int temp = arr[i]; /*A variável temporária recebe o elemento de índice i*/
            arr[i] = arr[j]; /*O índice i recebe o elemento do índice j*/
            arr[j] = temp; /*O índice j recebe o elemento que estava anteriomente no índice i*/
        }
    }
    /*Ao sair do laço, aloca-se o pivô na posição correta, trocando-o com o elemento [i+1]. Dessa forma, os elementos menores ficam à esquerda e os maiores à direita do pivô.*/
    int temp = arr[i + 1];
    arr[i + 1] = arr[ultimo];
    arr[ultimo] = temp;

    return i + 1; /*Retorna a posição onde o pivô foi armazenado*/
}
/*A função quickSort é recursiva e, além de ordenar, divide o array ao meio até que ele não possa mais sofrer divisões*/
void quickSort(int arr[], int primeiro, int ultimo) {
    if (primeiro < ultimo) { /*Condicional que verifica se ainda há elementos para dividir (isto é, se o sub-array tem mais de um elemento).*/
        int pivo = particao(arr, primeiro, ultimo);/*Definicção da variável pivô e chama a função particao, que aloca o pivô na posição correta e retorna o índice do pivô*/

        quickSort(arr, primeiro, pivo - 1); /*Ordena o subarray à esquerda do pivô*/

        quickSort(arr, pivo + 1, ultimo); /*Ordena o subarray à direita do pivô*/
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

    quickSort(arr, 0, n-1); /*ordena o array usando bubble sort*/

    clock_t fim = clock();

    /*calculo e impressao do tempo de execução*/ 
    double tempoGasto = (double)(fim - inicio) *1000 / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.2f milissegundos\n", tempoGasto);
    /*Libera a memória alocada para o array*/
    free(arr);

    return 0;
}

/*Referência: https://www.geeksforgeeks.org/quick-sort-algorithm/*/
