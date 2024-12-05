#include <stdio.h>
#include <stdlib.h>

struct Contato {
    char nome[50];
    char telefone[15];
};

int inserir (){
    struct Contato* inserirContato (char nome[], char telefone[]){
        struct Contato* contato = (struct Contato*) malloc(sizeof(struct Contato));
        strcpy (contato->nome, nome); 
        strcpy (contato->telefone, telefone)

        return contato;
    }
}
int listar (){

}
int remover (){

}
int atualizar (){

}
int main() {
    struct Contato agenda[100];
    int opcoes = 0;
    int cont = 0;

    printf("Escolha uma das opções: 1 - Inserir, 2 - Listar Contatos, 3 - Remover, 4 - Atualizar");
    scanf("%d", &opcoes);

    if opcoes == 1:
        for (int i = 0; i < num_contatos; i++) {
            printf("Digite o nome do contato %d: ", i + 1);
            scanf("%s", agenda[i].nome);

            printf("Digite o telefone do contato %d: ", i + 1);
            scanf("%s", agenda[i].telefone);
    }
    if opcoes == 2:
        printf("Contatos:\n");

        for (int i = 0; i < num_contatos; i++) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
    }
    if opcoes == 3: 
    if opcoes == 4: 

    return 0;
}