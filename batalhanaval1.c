/* usar arrays unidimencionais para representar um tabuleiro
    de batalha naval: posicionando um navio na vertical e outro
     na horizontal */

// utilize uma matriz 10x10 para representar o tabuleiro
// inicialize todas as posições do tabuleiro com 0 valor 0.
// 0 representa a água.

//posicione os navios: declare e inicialize dois arrays 
// unidimensionais para representar os navios
// cada navio ocupa 3 posições no tabuleiro
// represente os valores com o número 3
// escolher as coordenadas iniciais dos navios
// garantir que estegam dentro dos limites do tabuleiro
// o posicionamente do navio pode ser feito copiando o valor 3
// para as posições apropriadas do tabuleiro

// exiba o tabuleiro na tela: utilizando loops aninhados
// mostre a matriz completa, com 0s (água) e 3s (navios)
// A saída deve ser clara e organizada, permitindo visualizar
// a posição dos navios no tabuleiro.
// imprima um espaço ou outro caractere separado entre os elementos
// para melhorar a legibilidade.
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

    // posicionar navio horizontal (linha 2, colunas 2..4)
    int rH = 2, cH = 2;
    for (int k = 0; k < 3; k++) tabuleiro[rH][cH + k] = navioH[k];

    // posicionar navio vertical (linha 5..7, coluna 6)
    int rV = 5, cV = 6;
    for (int k = 0; k < 3; k++) tabuleiro[rV + k][cV] = navioV[k];

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