#include <stdio.h>

int main() {
    int opcao, valorInicial;
    
    printf("Escolha uma das opções abaixo:\n");
    printf("1. Sacar\n");
    printf("2. Depositar\n");
    printf("3. Verificar Saldo\n");
    printf("4. Sair\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao);
    
    valorInicial = 0;

    while (opcao > 1 || opcao <= 4) {
        
        if (opcao==4){
        printf("Até a próxima!\n");
                break;
        }
        else{ 
            int a;
            printf("Digite o valor desejado (somente notas de R$ 5, 10, 20, 50 e 100): ");
            scanf("%d", &a);

            switch (opcao) {
                case 1:
                    if (valorInicial<a){
                        printf("Vôce não tem saldo suficiente\n");
                    }
                    else{
                        valorInicial = valorInicial-a;
                        printf("Você sacou: R$ %d\n", a);
                        printf("Seu novo saldo é: R$ %d\n", valorInicial);
                    }
                    break;
                case 2:
                    valorInicial = valorInicial+a; 
                    printf("Seu novo saldo é: R$ %d\n", valorInicial);
                    break;
                case 3:
                    printf("Seu saldo atual é: R$ %d\n", valorInicial);
                    break;
                default:
                    printf("Opção inválida.\n");
                    break;
            }
        }
        printf("Escolha uma das opções abaixo:\n");
        printf("1. Sacar\n");
        printf("2. Depositar\n");
        printf("3. Verificar Saldo\n");
        printf("4. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &opcao);
    }

  
    printf("FINALIZANDO A OPERAÇÃO...\n");


    return 0;
