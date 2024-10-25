#include "core.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir_boas_vindas() {
    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");
}

void imprimir_tentativas_restantes(int tentativas) {
    if (tentativas == 1) {
        printf("Acabaram suas tentativas!\n");
    } else {
        printf("Você ainda tem %d tentativas!\n\n", tentativas - 1);
    }
}

void verificar_chute(int chute, int numerosecreto) {
    if (chute == numerosecreto) {
        printf("Parabéns! Você acertou, o número secreto é %d!\n", numerosecreto);
    } else if (chute > numerosecreto) {
        printf("\nSeu chute foi maior que o número secreto!\n");
    } else {
        printf("\nSeu chute foi menor que o número secreto!\n");
    }
}
