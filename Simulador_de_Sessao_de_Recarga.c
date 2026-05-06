#include <stdio.h>
//iniciando o menu do posto de carregamento rapido
void menu(void){ // uso de void para função que não devolve resultados
    //produção do menu
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
    int opcao = 0, porcentagem_atual = 0, porcentagem_desejada = 0, capacidade, potencia = 50; // Indicando o tipo e o valor das variaveis
     float valor = 0, tempo = 0;

    while(opcao != 6){ //iniciando a estrutura de reptição while


        menu();


        if (scanf("%d", &opcao) != 1){ //Iniciando o uso de estrutura condicional  if para possivel resposta invalida, junto a entra de dados
            printf("ERRO! Digite apenas numeros\n");
            return 1;
        }


        switch (opcao){ // Estrura condicional switch para o desenvolvimento do menu  


        case 1:// Iniciando o --caso 1-- do menu
            printf("Digite a capacidade maxima da bateria:\n");


            if (scanf("%d", &capacidade) != 1){// inserindo a entrada de dados da capaciade maxima da bateria junto a estrutura cindicional if --caso 1--
                printf("ERRO! Digite apenas numeros\n");//exibir para possivel resposta invalida
                return 1;
            }


            if (capacidade < 1 || capacidade > 120){// Estrutura if se a capacidade for maior que 120 ou menor que 1 --caso 1--
                printf("ERRO! Valor invalido\n");// Se verdadeiro exibir respota invalida. --caso 1--
            }
            break;//Encerrando o --caso 1-- e retornando as escolhas no menu
            


        case 2://Iniciando o --caso 2-- do menu
            printf("Digite a porcentagem atual:\n");


            if (scanf("%d", &porcentagem_atual) != 1){// Estrutura if junto a entrada de dados e  verificação do valor invalido, sendo diferente de ou igual a 1 --caso 2--
                printf("ERRO! Digite apenas numeros\n");//se verdadeiro exibir. --caso 2 --
                return 1;
            }


            if (porcentagem_atual < 0 || porcentagem_atual > 100){// Estrutura if para  identificão de valor invalido --caso 2--
                printf("ERRO! Valor invalido\n"); // se verdade exibir --caso 2--
            }
            break; //Encerrando o --caso 2-- e retornando as escolhas do menu


        case 3://Inicializando a escolha do --caso 3--
            printf("Digite a porcentagem desejada:\n");//Informar ao usuário --case 3--


            if (scanf("%d", &porcentagem_desejada) != 1){ //Estrutura if para identificão de valor invalido --caso 3--
                printf("ERRO! Digite apenas numeros\n");//Se verdadeiro exibir --caso 3--
                return 1;
            }


            if (porcentagem_desejada < 0 || porcentagem_desejada > 100){ //Etrutura if para indentificação de valor invalido --case 3--
                printf("ERRO! Valor invalido\n");//Se verdadeiro exibir --caso 3--
            } else if (porcentagem_desejada < porcentagem_atual){//Estrututa else if para identificação do valor invalido --case 3--
                printf("ERRO! Deve ser maior que a atual\n");//Se verdadeiro exibir --case 3--
            }
            break;//Encerrando o --caso 3-- e retornando as escolhas do menu


        case 4: {//Inicializando a escolha do --caso 4--
            if(capacidade == 0 || porcentagem_desejada == 0){
                printf("Preencha os dados primeiro\n");
            break;
            }

            int diferenca = porcentagem_desejada - porcentagem_atual;//indicando tipo e calculando o valor da variavel  --caso 4--
            float energia = capacidade * (diferenca / 100.0);//indicando tipo e calculando o valor da variavel --caso 4--
            valor = energia * 4.00;//indicando tipo e calculando o valor da variavel --caso 4--
            tempo = (energia / potencia)* 60;//indicando tipo e calculando o valor da variavel --caso 4--
            printf("valor a pagar e de R$ %.2f\n", valor);//Exibindo o resultado do valor a ser pago da variavel --caso 4--
            printf("O tempos estimado e de %f minutos\n", tempo);//Exibindo o resultado do tempo que levara para o carregamento completo --caso 4--




        break;//Encerrando o --caso 4-- e retornando as escolhas do menu
        }


        case 5://Iniciando a escolha do --caso 5--
       
            if(valor == 0 || tempo == 0){//Estrutura if para identificação do valor invalido --caso 5--
                printf("Informações não enseridas");//Se verdadeiro exibir  --caso 5--
                }else{//Estrura else para outros valores  --caso 5--
                    printf("Carregamento em andamento...\n");//Exibir --caso 5--
                }
            
        break;//Encerrando o --caso 5-- e retornando as escolhas do menu


        case 6://Iniciando a escolha do --caso 6--
            printf("Encerrando...\n");//Exibir o encerramento do laço de repetição switch case
            break;//Encerrando o --caso 6--


        default: //Default para valores que são maiores ou diferentes de 6
            printf("Opcao invalida\n");//Exibir opção invalida  
        }
    }


    return 0;
}
