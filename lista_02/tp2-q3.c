#include <stdio.h>

int main() {
    int opcao, cd1, cd2, cd3;
    
    printf("Escolha um dos candidatos:\n");
    printf("1. Harry Potter\n");
    printf("2. Hermione Granger\n");
    printf("3. Ron Weasley\n");
    printf("0. Sair do sistema de votação\n");
    printf("Digite sua escolha:\n");
    scanf("%d", &opcao);
    
    cd1 = 0;
    cd2 = 0;
    cd3 = 0;

    while (opcao > 0 || opcao <= 3) {
        if (opcao == 0) {
            break;
        }
        else{
            switch (opcao) {
                case 1:
                    cd1 ++;
                    printf("Vôce votou em Harry Potter\n");
                    break;
                case 2:
                    cd2++;
                    printf("Vôce votou em Hermione Granger\n");
                    break;
                case 3:
                    cd3++;
                    printf("Vôce votou em Ron Weasley\n");
                    break;
                default:
                    printf("Opção inválida.\n");
                    break;
                }
            }
        printf("Escolha um dos candidatos:\n");
        printf("1. Harry Potter\n");
        printf("2. Hermione Granger\n");
        printf("3. Ron Weasley\n");
        printf("0. Sair do sistema de votação\n");
        printf("Digite sua escolha:\n");
        scanf("%d", &opcao);
    }
    printf("Votos em Harry:%d\n", cd1);
    printf("Votos em Hermione:%d\n", cd2);
    printf("Votos em Rony:%d\n", cd3);
    printf("Encerrando o programa...\n");

    return 0;
}
