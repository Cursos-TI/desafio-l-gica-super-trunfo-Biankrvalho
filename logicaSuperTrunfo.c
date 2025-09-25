#include <stdio.h>

/*
  Super Trunfo – Países (cidades)
  Tema 2 – Comparação das Cartas

  Cartas:
    - São Paulo (SP)
    - Rio de Janeiro (RJ)

  Atributos:
    Estado, Código, Cidade, População, Área (km²), PIB (bi R$), Pontos turísticos
  Derivados:
    Densidade (hab/km²) = População / Área
    PIB per capita (R$) = (PIB em R$) / População

  Regra:
    - Em todos os atributos, MAIOR vence
    - EXCETO em DENSIDADE, onde o MENOR vence
*/

int main(void) {
    /* ===== Carta 1 – São Paulo ===== */
    char estado1[]  = "SP";
    char codigo1[]  = "A1";
    char cidade1[]  = "Sao Paulo";
    int   populacao1 = 12300000;  // ~12,3 mi
    float area1      = 1521.0f;   // km²
    float pib1       = 750.0f;    // bilhões de R$
    int   pontos1    = 25;

    /* ===== Carta 2 – Rio de Janeiro ===== */
    char estado2[]  = "RJ";
    char codigo2[]  = "B2";
    char cidade2[]  = "Rio de Janeiro";
    int   populacao2 = 6710000;   // ~6,71 mi
    float area2      = 1200.0f;   // km²
    float pib2       = 360.0f;    // bilhões de R$
    int   pontos2    = 20;

    /* ===== Derivados ===== */
    float densidade1     = (area1  > 0.0f) ? ( (float)populacao1 / area1 ) : 0.0f;
    float densidade2     = (area2  > 0.0f) ? ( (float)populacao2 / area2 ) : 0.0f;
    float pibPerCapita1  = (populacao1 > 0) ? ( (pib1 * 1e9f) / (float)populacao1 ) : 0.0f;
    float pibPerCapita2  = (populacao2 > 0) ? ( (pib2 * 1e9f) / (float)populacao2 ) : 0.0f;

    /* ===== Exibição organizada ===== */
    printf("========== CARTAS CADASTRADAS ==========\n");

    printf("\nCarta 1 — %s (%s) | Cod: %s\n", cidade1, estado1, codigo1);
    printf("Populacao: %d hab\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de R$\n", pib1);
    printf("Pontos turisticos: %d\n", pontos1);
    printf("Densidade: %.2f hab/km²\n", densidade1);
    printf("PIB per capita: R$ %.2f\n", pibPerCapita1);

    printf("\nCarta 2 — %s (%s) | Cod: %s\n", cidade2, estado2, codigo2);
    printf("Populacao: %d hab\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de R$\n", pib2);
    printf("Pontos turisticos: %d\n", pontos2);
    printf("Densidade: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: R$ %.2f\n", pibPerCapita2);

    /* ===== Comparação =====
       1 = População       (maior vence)
       2 = Área            (maior vence)
       3 = PIB             (maior vence)
       4 = Densidade       (MENOR vence)
       5 = PIB per capita  (maior vence)
    */
    const int ATRIBUTO = 1;  

    int vencedora = 0; // 0=empate, 1=carta1, 2=carta2

    printf("\n========== COMPARACAO ==========\nAtributo: ");
    if (ATRIBUTO == 1) {
        printf("Populacao\n");
        printf("%s: %d | %s: %d\n", cidade1, populacao1, cidade2, populacao2);
        if (populacao1 > populacao2) vencedora = 1;
        else if (populacao2 > populacao1) vencedora = 2;
    } else if (ATRIBUTO == 2) {
        printf("Area\n");
        printf("%s: %.2f km² | %s: %.2f km²\n", cidade1, area1, cidade2, area2);
        if (area1 > area2) vencedora = 1;
        else if (area2 > area1) vencedora = 2;
    } else if (ATRIBUTO == 3) {
        printf("PIB\n");
        printf("%s: %.2f bi R$ | %s: %.2f bi R$\n", cidade1, pib1, cidade2, pib2);
        if (pib1 > pib2) vencedora = 1;
        else if (pib2 > pib1) vencedora = 2;
    } else if (ATRIBUTO == 4) {
        printf("Densidade Populacional\n");
        printf("%s: %.2f hab/km² | %s: %.2f hab/km²\n", cidade1, densidade1, cidade2, densidade2);
        if (densidade1 < densidade2) vencedora = 1;     // menor vence
        else if (densidade2 < densidade1) vencedora = 2;
    } else if (ATRIBUTO == 5) {
        printf("PIB per capita\n");
        printf("%s: R$ %.2f | %s: R$ %.2f\n", cidade1, pibPerCapita1, cidade2, pibPerCapita2);
        if (pibPerCapita1 > pibPerCapita2) vencedora = 1;
        else if (pibPerCapita2 > pibPerCapita1) vencedora = 2;
    } else {
        printf("(atributo invalido)\n");
        return 0;
    }

    /* ===== Resultado ===== */
    if (vencedora == 1) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (vencedora == 2) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}

             


