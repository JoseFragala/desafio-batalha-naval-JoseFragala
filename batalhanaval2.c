//adicionando complexidade de navios posicionados na diagnal
// tabuleiro 10x10
// todas valor 0   
//posicionar 4 navios: 1 horizontal, 1 vertical, 2 diagonais
/* considere que um navio diagonal opcupa posições onde a linha
e a coluna aumentam ou diminuem simultaneamente em 1 unidade
por exemplo, tabuleiro[i][i] ou tabuleiro[i][9-i] para um tabuleiro 10x10*/
// as posições dos navios serão definidas pelo numero 3
// as posições devem estar dentro dos limites do tabuleiro
// exibir o tabuleiro utilizando loops aninhados e comando printf
// saida deve mostrar 10x10, com 0s e 3s, bem formatada
// utilize espaços para alinhar a saída e facilitar a leitura

#include <stdio.h>
int main() {
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};

    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // inicializa com água
        }
    }

    // navios unidimensionais (cada um com 3 partes)
    int navioH[3] = {3, 3, 3}; // horizontal
    int navioV[3] = {3, 3, 3}; // vertical
    int navioD1[3] = {3, 3, 3}; // diagonal principal
    int navioD2[3] = {3, 3, 3};

    // posicionar navio horizontal (linha 3, colunas 2..4)
    int rH = 3, cH = 2;
    for (int k = 0; k < 3; k++) tabuleiro[rH][cH + k] = navioH[k];

    // posicionar navio vertical (linha 5..7, coluna 6)
    int rV = 5, cV = 6;
    for (int k = 0; k < 3; k++) tabuleiro[rV + k][cV] = navioV[k];

    // posicionar navio diagonal principal (linha 0..2, colunas 0..2)
    int rD1 = 0, cD1 = 0;
    for (int k = 0; k < 3; k++) tabuleiro[rD1 + k][cD1 + k] = navioD1[k];
    // posicionar navio diagonal secundária (linha 7..9, colunas 2..0)
    int rD2 = 7, cD2 = 2;
    for (int k = 0; k < 3; k++) tabuleiro[rD2 + k][cD2 - k] = navioD2[k];
    // imprimir cabeçalho das colunas
    printf("   ");
    for (int j = 0; j < 10; j++) printf("%2c ", linha[j]);
    printf("\n");

    // imprimir tabuleiro
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i);
        for (int j = 0; j < 10; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}