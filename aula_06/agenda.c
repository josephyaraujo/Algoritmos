#include <stdio.h>
#include <stdlib.h>

struct Contato {
    char nome[50];
    char telefone[15];
}; 

void inserir (struct Contato agenda [], int contador){
    printf("Digite o nome do contato %d: ", contador + 1);
    scanf("%s", agenda[contador].nome);

    printf("Digite o telefone do contato %d: ", contador + 1);
    scanf("%s", agenda[contador].telefone);
    
    }
void listar ( struct Contato agenda[], int contador){
    printf("Contatos:\n");
        for (int i = 0; i < contador; i++) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
        }
    }
void remover (struct Contato agenda[], int opContato){
    int opcao = opContato -1;
    for (int i = opcao;  i < (sizeof(agenda)/sizeof(agenda[0])) - 1; i ++){
        agenda [i] = agenda [i+1];
    }
}
void atualizar (struct Contato agenda[], int opContato){
    int opcao = opContato -1;
    struct Contato* contato = &agenda[opcao];

    printf("Digite o nome do contato %d: ", opcao + 1);
    scanf("%s", agenda[opcao].nome);

    printf("Digite o telefone do contato %d: ", opcao + 1);
    scanf("%s", agenda[opcao].telefone);
    
}
int main() {
    int opcoes = 0;
    int contador = 0;
    int opContato = 0;

    struct Contato agenda[100];
    
    while (opcoes != 9){
        printf("Escolha uma das opções:\n1 - Inserir,\n2 - Listar Contatos,\n3 - Remover,\n4 - Atualizar,\n9 - Finalizar\n");
        printf("Digite a opção desejada:");
        scanf("%d", &opcoes);

        if (opcoes == 1 && contador < sizeof(agenda)){
            printf ("Inserir contato\n");
            inserir(agenda, contador);
            contador += 1;
        }    
        else if (opcoes == 2){
            listar (agenda, contador);
        }    
        else if (opcoes == 3){
            printf ("Excluir contato\n");
            listar (agenda, contador);
            printf ("Qual contato vooê deseja excluir?");
            scanf ("%d",&opContato); 
            contador -= 1;
            remover(agenda, opContato);
            printf ("Contato removido\n");
        } 
        else if (opcoes == 4){
            printf ("Atualizar contato\n");
            listar(agenda, contador);
            printf ("Qual contato você deseja alterar?");
            scanf ("%d", &opContato);
            atualizar (agenda, opContato);
            printf ("Contato atualizado\n");
        } 
    }
    return 0;
}