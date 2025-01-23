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
} Medico;

void criarFila(Fila *fila) { /*crio a fila vazia, aqui, por usar ponteiro, eu posso alterar diretamente os dados da struct fila referenciada pelo ponteiro*/
    fila->inicio = NULL;
    fila->fim =  NULL;
    fila->totalNormal = 0;
    fila->totalPreferencial = 0;
}
Medico *adicionarMedico (Medico **listaMedicos, const char *nome){
    Medico *novo = (Medico *)malloc(sizeof(Medico));
    strcpy (novo->nome, nome);
    criarFila (&novo->fila); 
    novo->proximo = *listaMedicos;
    *listaMedicos = novo;
    return novo;
}
void adicionarPaciente(Fila *fila, const char *nome, int tipo){
    if (fila->totalNormal + fila->totalPreferencial >=15){
        printf("O médico já atingiu o limite diário de 15 pacientes.\n");
        return;
    }
    Paciente *novo = (Paciente *)malloc(sizeof(Paciente));
    strcpy (novo->nome, nome);
    novo->tipo = tipo;
    novo->proximo = NULL; 
    if (fila->fim == NULL){
        fila->inicio = novo;
    } else {
        fila->fim->proximo = novo; 
    }
    fila->fim = novo;
    if (tipo == 0) {
        fila->totalNormal++;
    } else {
        fila->totalPreferencial++;
    }
    printf("Paciente %s, tipo de atendimento %s, foi adicionado à fila.\n", nome, tipo == 0? "Normal" : "Preferencial");
}
void removerPaciente(Fila *fila){
    if (fila->inicio == NULL){
        printf("A fila está vazia.\n");
        return;
    }
    int contPreferenciais = 0; /*contador de preferenciais atendidos*/
    Paciente *anterior = NULL;
    Paciente *atual = fila->inicio; 

    while (atual != NULL) {
        if (contPreferenciais < 2 && atual->tipo == 1){
            break;
        }
        if (contPreferenciais == 2 && atual->tipo == 0){
            break; 
        }
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) {
        printf ("Nenhum paciente aguardando atendimento.\n");
        return;
    }
    if (anterior == NULL){
        fila->inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    if (atual == fila->fim){
        fila->fim = anterior;
    }
    printf("Paciente %s foi atendido/removido da fila.\n", atual->nome);

    if (atual->tipo == 0){
        fila->totalNormal--;
        contPreferenciais = 0; /*reset do contador após atender um normal*/
    } else {
        fila->totalPreferencial--;
        contPreferenciais++;
    }
    free(atual);
}
void imprimirFila(Fila *fila){
    if (fila->inicio == NULL){
        printf("A fila está vazia.\n");
        return;
    }
    Paciente *atual = fila->inicio;
    printf("Fila de espera:\n");
    while (atual != NULL){
        printf("Nome: %s, Tipo: %d.\n", atual->nome, atual->tipo); 
        atual = atual->proximo;
    }
}
void listarMedicos (Medico *listaMedicos){
    printf ("Lista de Médicos:\n");
    int indice = 0;
    Medico *atual = listaMedicos;
    while (atual != NULL){
        printf("[%d] %s\n", indice, atual->nome);
        atual = atual->proximo;
        indice++;
    }
}
Medico *buscarMedico (Medico *listaMedicos, int indice){
    int contador = 0; 
    Medico *atual = listaMedicos;
    while (atual != NULL){
        if (contador == indice){
            return atual;
        }
        atual = atual->proximo; 
        contador++;
    }
    return NULL; /*vai retornar NULL se o índice não for válido*/
}
Medico *criarListaMedicos(){
    Medico *listaMedicos = NULL; 
    adicionarMedico(&listaMedicos,"Dr. Potter");
    adicionarMedico(&listaMedicos,"Dra. Granger");
    adicionarMedico(&listaMedicos,"Dr. Wislley");

    return listaMedicos;
}
void imprimir_menu(){
    printf("Escolha uma opção abaixo:\n");
    printf("1. Adicionar paciente\n");
    printf("2. Atender/Remover paciente\n");
    printf("3. Imprimir fila por médico\n");
    printf("4. Sair\n");
}

int main(){
    Medico *listaMedicos = criarListaMedicos();
   
    int opcao;
    char nome[100];
    int tipo;
    int indice;

    while (1){
        imprimir_menu();
        scanf("%d", &opcao);
        switch (opcao){
        case 1:
            printf("Lista de médicos disponível para atendimento: \n");
            listarMedicos(listaMedicos);
            printf("Digite o número correspondente ao médico desejado: ");
            scanf("%d", &indice);

            Medico *medicoAtual = buscarMedico(listaMedicos, indice);
            
            if (medicoAtual == NULL) {
                printf("Opção inválida. Medico não encontrado. Tente novamente.\n");
            } else {
                printf("Digite o nome do paciente: ");
                scanf(" %[^\n]", nome);
                printf("Para atendimento Normal digite 0, para Preferencial digite 1: ");
                scanf("%d", &tipo);
                adicionarPaciente(&medicoAtual->fila, nome, tipo);
            }
            break;
        case 2:
            printf("Lista de médicos disponível para atendimento: \n");
            listarMedicos(listaMedicos);
            printf("Digite o número correspondendo ao médico desejado: ");
            scanf("%d", &indice);

            Medico *medicoAtualRemover = buscarMedico(listaMedicos, indice);

            if (medicoAtualRemover == NULL) {
                printf("Opção inválida. Medico não encontrado. Tente novamente.\n");
            } else {
                removerPaciente(&medicoAtualRemover->fila);
            }
            break;
        case 3:
             printf("Lista de médicos disponível para atendimento: \n");
            listarMedicos(listaMedicos);
            printf("Digite o número correspondendo ao médico desejado: ");
            scanf("%d", &indice);

            Medico *medicoAtualImprimir = buscarMedico(listaMedicos, indice); 

            if (medicoAtualImprimir == NULL) {
                printf("Opção inválida. Medico não encontrado. Tente novamente.\n");
            } else {
                imprimirFila(&medicoAtualImprimir->fila);
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
