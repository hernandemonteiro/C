#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int game();

int main() {
    printf("\nBem vindo ao jogo da forca!\n");
    printf("A palavra é uma fruta.\n\n");

    while (1) {
        game();
    }
    return 0;
}

int game() {
    srand(time(NULL));

    const char *palavrasSecretas[] = {"ABACATE", "MELANCIA", "MELAO",
                                      "LARANJA", "UVA", "MORANGO", "BANANA",
                                      "PERA", "MANGA", "GOIABA"};

    const int totalPalavras = sizeof(palavrasSecretas) / sizeof(char *);
    const int indice = rand() % totalPalavras;

    char palavraSecreta[20];
    strcpy(palavraSecreta, palavrasSecretas[indice]);
    size_t tamanho = strlen(palavraSecreta);

    printf("\nA palavra secreta tem %ld letras.\n\n", tamanho);

    char *palavraDescoberta = malloc(tamanho + 1);

    if (palavraDescoberta == NULL) {
        perror("Erro ao alocar memória");
        return 1;
    }

    for (size_t i = 0; i < tamanho; i++) {
        palavraDescoberta[i] = '_';
    }

    palavraDescoberta[tamanho] = '\0';

    int erros = 10;

    while (erros > 0) {
        char letra;
        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        letra = toupper(letra);

        if (strchr(palavraDescoberta, letra) != NULL) {
            printf("\nVocê já digitou essa letra!\n\n");
            continue;
        }

        bool acertou = false;

        for (int i = 0; i < tamanho; i++) {
            if (palavraSecreta[i] == letra) {
                printf("A letra %c existe na posição %d\n", letra, i);
                palavraDescoberta[i] = letra;
                acertou = true;
            }
        }

        if (!acertou) {
            erros--;
            printf("\nA letra %c não está na palavra secreta. Você tem %d tentativas restantes.\n", letra, erros);
        } else {
            printf("\nBoa! Você acertou uma letra!\n");
        }

        printf("\nPalavra: %s\n\n", palavraDescoberta);

        if (strcmp(palavraDescoberta, palavraSecreta) == 0) {
            printf("Parabéns, você acertou a palavra secreta!\n");
            printf("A palavra secreta era: %s\n", palavraSecreta);
            break;
        }
    }

    if (erros == 0) {
        printf("Você perdeu! A palavra secreta era: %s\n", palavraSecreta);
    }

    free(palavraDescoberta);

    return 0;
}