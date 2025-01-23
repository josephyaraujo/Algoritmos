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
    int contPreferenciais;
    int contNormal;
} Medico;

void criarFila(Fila *fila) { /*crio a fila vazia, aqui, por usar ponteiro, eu posso alterar diretamente os dados da struct fila referenciada pelo ponteiro*/
    fila->inicio = NULL;
    fila->fim =  NULL;
    fila->totalNormal = 0;
    fila->totalPreferencial = 0;
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
void remover_paciente(Medico *medicoAtual, const char *nomePaciente) {
    Paciente *atual = medicoAtual->fila.inicio; 
    Paciente *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->nome, nomePaciente) == 0) {  
            printf("Paciente %s atendido(a)\n", atual->nome);
            if (anterior == NULL) {
                remover_inicio(medicoAtual);
            } else {
                anterior->proximo = atual->proximo;  
                if (atual == medicoAtual->fila.fim) {   
                    medicoAtual->fila.fim = anterior; 
                }
                free(atual);  
            }
            if (atual->tipo == 0) {
                medicoAtual->fila.totalNormal--;
            } else {
                medicoAtual->fila.totalPreferencial--;
            }
            return; 
        }
        anterior = atual; 
        atual = atual->proximo;
    }
}

void remover_inicio(Medico *medicoAtual) {
    Paciente *atual = medicoAtual->fila.inicio;
    medicoAtual->fila.inicio = medicoAtual->fila.inicio->proximo;  
    if (medicoAtual->fila.inicio == NULL) {
        medicoAtual->fila.fim = NULL;  
    }
    free(atual);
}
void atenderPaciente(Fila *fila, Medico *medicoAtual){
    Paciente *atual = medicoAtual->fila.inicio;
    while (atual != NULL){
        if (medicoAtual->contPreferenciais < 2 && atual->tipo == 1){
            remover_paciente(medicoAtual, atual->nome); 
            medicoAtual->contPreferenciais++;                            
            fila->totalPreferencial--;
        }
        else if (medicoAtual->contPreferenciais == 2 && atual->tipo == 0){ 
            remover_paciente(medicoAtual, atual->nome); 
            medicoAtual->contNormal++;
            fila->totalNormal--;                                
            medicoAtual->contPreferenciais = 0;                        
        }
        else if (medicoAtual->contNormal == 1 && atual->tipo == 1){ 
            remover_paciente(medicoAtual, atual->nome); 
            medicoAtual->contPreferenciais++;                            
            medicoAtual->contNormal = 0;                                
            fila->totalPreferencial--; 
        } 
        else if (fila->totalPreferencial == 0 && atual->tipo == 0){
            remover_paciente(medicoAtual, atual->nome);
            medicoAtual->contNormal++;                                 
        }
        atual = atual->proximo;
    }
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
    Medico *atual = listaMedicos;
    int indice = 1;
    while (atual != NULL){
        printf("%d. %s\n", indice, atual->nome);
        atual = atual->proximo;
        indice++;
    }
}
Medico *buscarMedico (Medico *listaMedicos, int indice){
    int contador = 1; 
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
    Medico *medico1 = (Medico *)malloc(sizeof(Medico));
    Medico *medico2 = (Medico *)malloc(sizeof(Medico));
    Medico *medico3 = (Medico *)malloc(sizeof(Medico));
    
    strcpy (medico1->nome, "Dr. Harry"); 
    criarFila(&medico1->fila);
    medico1->proximo = medico2;

    strcpy (medico2->nome, "Dra. Hermione"); 
    criarFila(&medico2->fila);
    medico2->proximo = medico3;

    strcpy (medico3->nome, "Dr. Ronny"); 
    criarFila(&medico3->fila);
    medico3->proximo = NULL;

    return medico1;
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

            Medico *medicoAtualAtender = buscarMedico(listaMedicos, indice);

            if (medicoAtualAtender == NULL) {
                printf("Opção inválida. Medico não encontrado. Tente novamente.\n");
            } else {
                atenderPaciente(&medicoAtualAtender->fila, medicoAtualAtender);
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