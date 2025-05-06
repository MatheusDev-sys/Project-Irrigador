#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
    //Simula o tempo de espera
    void esperar(int segundos) {
        time_t inicio = time(NULL);
        while (time(NULL) - inicio < segundos);
    }
    //Contagem regressiva com delay
    void contagemRegressiva(int segundos) {
        for (int i = segundos; i > 0; i--) {
            printf("%d...\n", i);
            esperar(1);
        }
    }
     void  ler_sensores(int sensores[], int num_sensores);//Declaração
     void iniciar_irrigacao(int sensores[], int num_sensores) {
         float soma = 0; //Soma o valor dos sensores
         float media; //Armazena média calculada
        printf("\n[INICIANDO MONITORAMENTO DE UMIDADE...]\n");
        ler_sensores(sensores, num_sensores);
        for (int i = 0; i< num_sensores; i++){
            soma += sensores[i]; //Soma todos os valores de umidade
        }    
    media = soma / num_sensores; //Calcula a média dos sensores
        printf("Média da umidade: %.2f%%\n", media); //Mostra a média

    if (media == 100){ //Trava o sistema se a umidade for exatamente 100%
        printf("[ALERTA INTERMITENTE] Fluxo excessivo detectado! Sistema bloqueado.\n");
        return;
        }
     if (media > 80){ //Cancela irrigação se a média for maior que 80%
         printf("[BLOQUEIO] Umidade acima de 80%%. Irrigação cancelada.\n");
         return;
     }
    //Se passou pelos testes, seguiremos com a irrigação
        printf("\n[APITO] Irrigação iniciando em:\n");
        contagemRegressiva(30); //Contagem regressiva de 30 segundos
        printf("\n[INÍCIO] Iniciando a irrigação por 30 segundos...\n");
    for (int i = 1; i <= 30; i++) {
        printf("Regando... %d/30s\n", i); //Exibe a rega segundo por segundo
        esperar(1); //Pausa de 1 segundo por volta
    }
        printf("\n[APITO] Irrigação finalizada com sucesso!\n");
     }  
    //Liga o sistema
    void ligar_sistema(){
        printf("Sistema de irrigação ligado! \n"); //Esta parte anuncia o inicio do sistema.
    }
    //Desliga o sistema 
    void desligar_sistema(){
        printf("Sistema de irrigação encerrado!");
    }
    //Progamação de irrigação
    void programar_irrigacao(){
        printf("\n[INFO] Irrigação programada para acontecer a cada 50 minutos.\n");
        printf("[AVISO] Recurso ainda em desenvolvimento.\n");
    }
    //Lê os sensores
    void ler_sensores (int sensores[], int num_sensores) {
        printf("Lendo sensores de umidade...\n");
        //loop que gera valores aleatórios para os sensores.    
        for (int i = 0; i < num_sensores; i++) {
            sensores[i] = rand() % 101; //gera um valor de 0 a 100    
        //i+1 -> mostra "Sensor 1" ao invés de "Sensor 0"
        //Sensores[i] -> Valor da umidade daquele sensor          
        //%% -> Imprime o simbolo de porcentagem        
            printf("Sensor %d: %d%%\n", i + 1, sensores[i]);
        }
    }
int main() {
    int sensores[4]; //Vetor para armazenar os valores dos sensores
    int opcao;    
    while(1) {
    //Exibe o menu para o usuário 
        printf("\n -----Painel de controle-----\n");
        printf("Digite 1 para ligar o sistema\n");
        printf("Digite 2 para encerrar o sistema\n");
        printf("Digite 3 para programar a irrigação\n");
        printf("Digite 0 para Sair\n");
        printf("Escolha uma opção\n");
        scanf("%d", &opcao );
//Verifica a opção do usuário.
    if(opcao == 1 ) {
        ligar_sistema();
        iniciar_irrigacao(sensores,4);
    } else if (opcao == 2) {
        desligar_sistema();
    } else if(opcao == 3) {
        programar_irrigacao();
    } else if(opcao == 0) {
     printf("\nSaindo do sistema!");
    break;
    } else {
    printf("Opção inválida! Tente novamente.");
    }    
}
    return 0;
}

