#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define TAM_H 5

// Função que sobrepõe qualquer habilidade ao tabuleiro
void sobreporHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_H][TAM_H], int origemI, int origemJ) {
    int raio = TAM_H / 2;
    for (int i = 0; i < TAM_H; i++) {
        for (int j = 0; j < TAM_H; j++) {
            int ti = origemI + (i - raio);
            int tj = origemJ + (j - raio);
            if (ti >= 0 && ti < TAM &&
                tj >= 0 && tj < TAM &&
                habilidade[i][j] == 1 &&
                tabuleiro[ti][tj] != 3) {
                tabuleiro[ti][tj] = 5;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};
    int linha[TAM]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char coluna[TAM] = {'A','B','C','D','E','F','G','H','I','J'};

    // =====================
    // NAVIOS
    // =====================

    for (int j = 2; j < 5; j++)  tabuleiro[4][j] = 3;  // horizontal C5-E5
    for (int i = 6; i < 9; i++)  tabuleiro[i][8] = 3;  // vertical   I7-I9
    for (int i = 0; i < 3; i++)  tabuleiro[i][i] = 3;  // diagonal principal
    for (int i = 0; i < 3; i++)  tabuleiro[i][9-i] = 3; // diagonal secundária

    // =====================
    // HABILIDADES
    // =====================

    int cone[TAM_H][TAM_H]     = {0};
    int cruz[TAM_H][TAM_H]     = {0};
    int octaedro[TAM_H][TAM_H] = {0};

    for (int i = 0; i < TAM_H; i++) {
        for (int j = 0; j < TAM_H; j++) {
            // Cone: expande a partir do topo
            if (j >= (TAM_H/2 - i) && j <= (TAM_H/2 + i))
                cone[i][j] = 1;
            // Cruz: linha e coluna do meio
            if (i == TAM_H/2 || j == TAM_H/2)
                cruz[i][j] = 1;
            // Octaedro: distância de Manhattan <= raio
            if (abs(i - TAM_H/2) + abs(j - TAM_H/2) <= TAM_H/2)
                octaedro[i][j] = 1;
        }
    }

    // Sobrepõe as 3 habilidades com 1 função
    sobreporHabilidade(tabuleiro, cone,     2, 4);  // E3
    sobreporHabilidade(tabuleiro, cruz,     7, 4);  // E8
    sobreporHabilidade(tabuleiro, octaedro, 4, 7);  // H5

    // =====================
    // EXIBIR TABULEIRO
    // =====================

    printf("TABULEIRO BATALHA NAVAL\n\n");
    printf("   ");
    for (int i = 0; i < TAM; i++) printf("%c ", coluna[i]);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", linha[i]);
        for (int j = 0; j < TAM; j++) {
            if      (tabuleiro[i][j] == 3) printf("3 ");
            else if (tabuleiro[i][j] == 5) printf("5 ");
            else                           printf("0 ");
        }
        printf("\n");
    }

    printf("\nLegenda:  0 agua  |  3 navio  |  5 habilidade\n");

    return 0;
}