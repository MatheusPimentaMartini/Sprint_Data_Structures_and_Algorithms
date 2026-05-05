#include <stdio.h>

void menu(void){
    printf("======================================================\n");
    printf("============ POSTO DE CARREGAMENTO RAPIDO ============\n");
    printf("1 - CAPACIDADE TOTAL DA BATERIA\n");
    printf("2 - PORCENTAGEM DE BATERIA DO SEU VEICULO\n");
    printf("3 - PORCENTAGEM DE BATERIA QUE DESEJA CHEGAR\n");
    printf("4 - CALCULO DE VALOR E TEMPO\n");
    printf("5 - INICIAR CARREGAMENTO\n");
    printf("6 - ENCERRAR\n");
    printf("======================================================\n");
}

int main (){
    int opcao = 0, porcentagem_atual = 0, porcentagem_desejada = 0, capacidade, potencia = 50;

    while(opcao != 6){

        menu();

        if (scanf("%d", &opcao) != 1){
            printf("ERRO! Digite apenas numeros\n");
            return 1;
        }

        switch (opcao){

        case 1:
            printf("Digite a capacidade maxima da bateria:\n");

            if (scanf("%d", &capacidade) != 1){
                printf("ERRO! Digite apenas numeros\n");
                return 1;
            }

            if (capacidade < 1 || capacidade > 120){
                printf("ERRO! Valor invalido\n");
            }
            break;

        case 2:
            printf("Digite a porcentagem atual:\n");

            if (scanf("%d", &porcentagem_atual) != 1){
                printf("ERRO! Digite apenas numeros\n");
                return 1;
            }

            if (porcentagem_atual < 0 || porcentagem_atual > 100){
                printf("ERRO! Valor invalido\n");
            }
            break;

        case 3:
            printf("Digite a porcentagem desejada:\n");

            if (scanf("%d", &porcentagem_desejada) != 1){
                printf("ERRO! Digite apenas numeros\n");
                return 1;
            }

            if (porcentagem_desejada < 0 || porcentagem_desejada > 100){
                printf("ERRO! Valor invalido\n");
            } else if (porcentagem_desejada < porcentagem_atual){
                printf("ERRO! Deve ser maior que a atual\n");
            }
            break;

        case 4: {
            int diferenca = porcentagem_desejada - porcentagem_atual;
            float energia = capacidade * (diferenca / 100.0);
            float valor = energia * 4.00;
            float tempo = energia / potencia;
            printf("valor a pagar e de R$ %.2f\n", valor);
            printf("O tempos estimado e de %f minutos\n", tempo);


        break;
        }

        case 5:
        
        

        case 6:
            printf("Encerrando...\n");
            break;

        default:
            printf("Opcao invalida\n");
        }
    }

    return 0;
}