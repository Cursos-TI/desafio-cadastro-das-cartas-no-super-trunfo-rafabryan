#include <stdio.h>

// Estrutura para representar uma carta
typedef struct {
    char estado;
    int codigo;
    char nome[50];
    unsigned long int populacao;
    float area;
    double pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular os atributos derivados
void calcular_atributos(Carta *c) {
    c->densidade_populacional = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
    c->super_poder = c->populacao + c->area + c->pib + c->pontos_turisticos + c->pib_per_capita + (1 / c->densidade_populacional);
}

// Função para ler os dados de uma carta
void ler_carta(Carta *c) {
    printf("\nDigite o estado (A-H): ");
    scanf(" %c", &c->estado);
    printf("Digite o código da cidade: ");
    scanf("%d", &c->codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %[^"]s", c->nome);
    printf("Digite a população: ");
    scanf("%lu", &c->populacao);
    printf("Digite a área: ");
    scanf("%f", &c->area);
    printf("Digite o PIB: ");
    scanf("%lf", &c->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c->pontos_turisticos);
    
    calcular_atributos(c);
}

// Função para comparar e exibir os resultados
void comparar_cartas(Carta c1, Carta c2) {
    printf("\nComparação de Cartas:\n");
    printf("População: Carta %d venceu (%d)\n", c1.populacao > c2.populacao ? 1 : 2, c1.populacao > c2.populacao);
    printf("Área: Carta %d venceu (%d)\n", c1.area > c2.area ? 1 : 2, c1.area > c2.area);
    printf("PIB: Carta %d venceu (%d)\n", c1.pib > c2.pib ? 1 : 2, c1.pib > c2.pib);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", c1.pontos_turisticos > c2.pontos_turisticos ? 1 : 2, c1.pontos_turisticos > c2.pontos_turisticos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", c1.densidade_populacional < c2.densidade_populacional ? 1 : 2, c1.densidade_populacional < c2.densidade_populacional);
    printf("PIB per Capita: Carta %d venceu (%d)\n", c1.pib_per_capita > c2.pib_per_capita ? 1 : 2, c1.pib_per_capita > c2.pib_per_capita);
    printf("Super Poder: Carta %d venceu (%d)\n", c1.super_poder > c2.super_poder ? 1 : 2, c1.super_poder > c2.super_poder);
}

int main() {
    Carta carta1, carta2;
    
    printf("Cadastro da Carta 1:\n");
    ler_carta(&carta1);
    printf("\nCadastro da Carta 2:\n");
    ler_carta(&carta2);
    
    comparar_cartas(carta1, carta2);
    
    return 0;
}
