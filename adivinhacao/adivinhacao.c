#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "src/core.h"

int main() {
    imprimir_boas_vindas();

    srand(time(NULL));
    int numerosecreto = rand() % 100;
    int chute = 0;
    int tentativas = 10;

    printf("Você tem %d tentativas para acertar o número secreto!\n\n", tentativas);

    while (chute != numerosecreto && tentativas != 0) {
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);

        verificar_chute(chute, numerosecreto);

        if (chute == numerosecreto) {
            break;
        }

        imprimir_tentativas_restantes(tentativas);
        tentativas--;
    }

    return 0;
}