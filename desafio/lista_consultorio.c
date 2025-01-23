#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente {
    char nome[100];
    int tipo; /*0 para normal e 1 para preferencial*/
    struct Paciente *proximo; /*aponta para o próximo da fila*/
} Paciente;
typedef struct Fila {
    Paciente *inicio; /*aponta pro primeiro paciente da fila*/
    Paciente *fim; /*aponta pro último*/
    int totalNormal; /*aqui crio os contadores para os tipos de pacientes*/
    int totalPreferencial; 
} Fila; 
typedef struct Medico{
    char nome[100];
    Fila fila; /*aqui eu crio um tipo Fila que está associado a um médico*/
    struct Medico *proximo; 
}Medico;

void criar_fila(Fila *fila) { /*crio a fila vazia, aqui, por usar ponteiro, eu posso alterar diretamente os dados da struct fila referenciada pelo ponteiro*/
    fila->inicio = NULL;
    fila->fim =  NULL;
    fila->totalNormal = 0;
    fila->totalNormal = 0;
}

void adicionar_elemento(int valor)
{
    struct Node *novo_node = (struct Node *)malloc(sizeof(struct Node));
    novo_node->valor = valor;
    novo_node->proximo = inicio_da_lista;
    inicio_da_lista = novo_node;
}

void adicionar_final(int valor)
{
    struct Node *novo_node = (struct Node *)malloc(sizeof(struct Node));
    novo_node->valor = valor;
    novo_node->proximo = NULL;
    if (inicio_da_lista == NULL)
    {
        inicio_da_lista = novo_node;
    }
    else
    {
        struct Node *atual = inicio_da_lista;
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo_node;
    }
}

void remover_inicio()
{
    struct Node *temp = inicio_da_lista;
    inicio_da_lista = inicio_da_lista->proximo;
    free(temp);
}

void remover_elemento(int valor)
{
    struct Node *atual = inicio_da_lista;
    struct Node *anterior = NULL;
    while (atual != NULL)
    {
        if (atual->valor == valor)
        {
            if (anterior == NULL)
            {
                remover_inicio();
            }
            else
            {
                anterior->proximo = atual->proximo;
                free(atual);
            }
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void remover_final()
{
    struct Node *atual = inicio_da_lista;
    struct Node *anterior = NULL;
    while (atual->proximo != NULL)
    {
        anterior = atual;
        atual = atual->proximo;
    }
    if (anterior == NULL)
    {
        inicio_da_lista = NULL;
    }
    else
    {
        anterior->proximo = NULL;
    }
    free(atual);
}

void imprimir_lista()
{
    struct Node *atual = inicio_da_lista;

    printf(" INICIO --> ");
    while (atual != NULL)
    {
        printf("%d --> ", atual->valor);
        atual = atual->proximo;
    }
    printf(" NULL\n");
}

int tamanho_da_lista()
{
    struct Node *atual = inicio_da_lista;
    int tamanho = 0;
    while (atual != NULL)
    {
        tamanho++;
        atual = atual->proximo;
    }
    return tamanho;
}

void imprimir_menu()
{
    printf("Escolha uma opção abaixo:\n");
    printf("1. Adicionar paciente\n");
    printf("2. Atender/Remover paciente\n");
    printf("3. Imprimir fila por médico\n");
    printf("4. Sair\n");
}

int main()
{
    criar_lista();
    int opcao;
    char nome[100];
    int tipo;
    int indice;
    while (1)
    {
        imprimir_menu();
        scanf("%d", &opcao);
        switch (opcao){
        case 1:
            printf("Lista de médicos disponível para atendimento: \n");
            listarMedicos(listaMedicos);
            printf("Digite o número correspondendo ao médico desejado: ");
            scanf("%d", &indice);

            Medico *medicoatual = buscarMedico(listaMedicos, indice);
            if (medicoAtual == NULL) {
                printf("Opção inválida. Medico não encontrado. Tente novamente.\n");
            } else {
                printf("Digite o nome do paciente: ");
                scanf(" %[ˆ\n]", nome);
                printf("Para atendimento Normal digite 0, para Preferencial digite 1: ");
                scanf("%d, &tipo");
            }
            break;
        case 2:
            printf("Lista de médicos disponível para atendimento: \n");
            listarMedicos(listaMedicos);
            printf("Digite o número correspondendo ao médico desejado: ");
            scanf("%d", &indice);

            Medico *medicoatual = buscarMedico(listaMedicos, indice);
            if (medicoAtual == NULL) {
                printf("Opção inválida. Medico não encontrado. Tente novamente.\n");
            } else {
                removerPaciente(&medicoAtual->fila);
            }
            break;
        case 3:
             printf("Lista de médicos disponível para atendimento: \n");
            listarMedicos(listaMedicos);
            printf("Digite o número correspondendo ao médico desejado: ");
            scanf("%d", &indice);

            Medico *medicoatual = buscarMedico(listaMedicos, indice);
            if (medicoAtual == NULL) {
                printf("Opção inválida. Medico não encontrado. Tente novamente.\n");
            } else {
                imprimirFila(&medicoAtual->fila);
            }
            break;
        case 4:
            printf("Encerrando o programa.\n");
            return 0;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
    return 0;
}
