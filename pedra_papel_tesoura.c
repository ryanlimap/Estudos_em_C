#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    srand(time(NULL));

    printf("Bem-vindo ao Pedra, Papel e Tesoura!\n");

    int escolha_usuario, escolha_computador;

    printf("Escolha uma opcao:\n");
    printf("0 - Pedra\n");
    printf("1 - Papel\n");
    printf("2 - Tesoura\n");
    printf("Escolha: ");
    scanf("%d", &escolha_usuario);

    escolha_computador = rand() % 3;

    char opcoes[][10] = {"Pedra", "Papel", "Tesoura"};

    if (escolha_usuario >= 3) {
        printf("Escolha invalida");
    }

    else {
        printf("Usuario escolheu: %s\n", opcoes[escolha_usuario]);
        printf("Computador escolheu: %s\n", opcoes[escolha_computador]);
    

        char vencedor[20];
        
        if (escolha_usuario == escolha_computador) {
            strcpy(vencedor, "Empate");
        } else if ((escolha_usuario == 0 && escolha_computador == 2) ||
                (escolha_usuario == 1 && escolha_computador == 0) ||
                (escolha_usuario == 2 && escolha_computador == 1)) {
            strcpy(vencedor, "Usuario");
        } else {
            strcpy(vencedor, "Computador");
        }

        if (strcmp(vencedor, "Empate") == 0) {
            printf("Empate! Ninguem ganhou.\n");
        } else {
            printf("O ganhador foi o: %s\n", vencedor);
        }
    }

    return 0;
}
