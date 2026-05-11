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
    printf("Escolha uma opcao: ");
}

int main (){
    int opcao = 0;
    int porcentagem_atual = -1;
    int porcentagem_desejada = -1;
    int capacidade = 0;
    int potencia = 50; // kW

    float valor = 0.0;
    float tempo = 0.0;
    float energia = 0.0;
    float tarifa = 4.00; // R$ por kWh

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
            }else {
                    printf("Porcentagem desejada registrada: %d%%.\n", porcentagem_desejada);
                }
            break;

        case 4: 
            if (capacidade == 0 || porcentagem_atual == -1 || porcentagem_desejada == -1) {
                    printf("Preencha todos os dados antes de calcular.\n");
                    break;
            }

            if (porcentagem_desejada <= porcentagem_atual) {
                    printf("ERRO! A porcentagem desejada deve ser maior que a atual.\n");
                    break;
            }

            int diferenca = porcentagem_desejada - porcentagem_atual;

            energia = capacidade * (diferenca / 100.0);
            valor = energia * tarifa;
            tempo = (energia / potencia) * 60;

            printf("\n=========== RELATORIO DA RECARGA ===========\n");
            printf("Capacidade da bateria: %d kWh\n", capacidade);
            printf("Bateria atual: %d%%\n", porcentagem_atual);
            printf("Bateria desejada: %d%%\n", porcentagem_desejada);
            printf("Energia necessaria: %.2f kWh\n", energia);
            printf("Valor a pagar: R$ %.2f\n", valor);
            printf("Tempo estimado: %.2f minutos\n", tempo);
            printf("============================================\n");
            

        break;
        

        case 5:
        
        if (valor == 0 || tempo == 0) {
            printf("Calcule o valor e o tempo antes de iniciar o carregamento.\n");
        } else {
            printf("\nCarregamento iniciado...\n");
            printf("Tempo estimado: %.2f minutos\n", tempo);
            printf("Valor previsto: R$ %.2f\n", valor);
            printf("Sistema monitorando consumo de energia em tempo real.\n");
        break;
        }
        

        case 6:
            printf("Encerrando...\n");
            break;

        default:
            printf("Opcao invalida\n");
        }
    }

    return 0;
}