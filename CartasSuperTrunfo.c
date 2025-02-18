#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ESTADOS 8
#define CIDADES 4
#define TOTAL_CARTAS (ESTADOS * CIDADES)

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

void cadastrarCartas(Carta cartas[]) {
    char estados[] = "ABCDEFGH";
    int contador = 0;

    for (int i = 0; i < ESTADOS; i++) {
        for (int j = 1; j <= CIDADES; j++) {
            sprintf(cartas[contador].codigo, "%c%02d", estados[i], j);
            printf("\nCadastro da cidade %s:\n", cartas[contador].codigo);

            printf("População: ");
            scanf("%d", &cartas[contador].populacao);

            printf("Área (km²): ");
            scanf("%f", &cartas[contador].area);

            printf("PIB (em bilhões): ");
            scanf("%f", &cartas[contador].pib);

            printf("Número de pontos turísticos: ");
            scanf("%d", &cartas[contador].pontos_turisticos);

            contador++;
        }
    }
}

void exibirCartas(Carta cartas[]) {
    printf("\n--- Cartas Cadastradas ---\n");
    for (int i = 0; i < TOTAL_CARTAS; i++) {
        printf("\nCódigo: %s\n", cartas[i].codigo);
        printf("População: %d\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões\n", cartas[i].pib);
        printf("Pontos Turísticos: %d\n", cartas[i].pontos_turisticos);
    }
}

int main() {
    Carta cartas[TOTAL_CARTAS];

    printf("=== Cadastro de Cartas do Jogo Super Trunfo - Países ===\n");
    cadastrarCartas(cartas);
    exibirCartas(cartas);

    return 0;
}
