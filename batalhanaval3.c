// adicionar um toque estratégico ao jogo de batalha naval
// habilidades especiais com areas de efeito distintas
// usar lógica para representar e exibir essas habilidades

// modiicar o programa em C para:
// definir o tabuleiro (manter 10x10)
// servira como base para visualizar as areas de efeito das habilidades especiais
// criar matrizes de habilidade
// 3 matrizes separadas, cada uma representando 
// uma area de efeito diferente para as habilidades especiais

// cone - uma matriz que represente uma area em forma de cone
// cruz - uma matriz que represente uma area em forma de cruz
// octaedro - uma matriz que represente uma area em forma de octaedro 
// assemelha a um losango 

// as matrizes de habilidade devem indicar quais posições sao afetadas
// pela habilidade com valor 1 e quais nao sao afetadas com valor 0
// definir um tamanho rezoável para cada matriz de habilidade
// 5x5 ou 7x7

// integrar habilidades ao tabuleiro
// definir ponto de origem para cada habilidade no tabuleiro
//crie a kógica para sobrepor a matriz de habilidade no tabuleiro
// centrando-a no ponto de origem
//as posições no tabuleiro que correspondem aos valores 1 na matriz de habilidade
// devem ser marcadas como afetadas visualmente
// utilize 0 e 3 para representar as posições afetadas pela habilidade
// por exemplo, o valor 5)

// Exibir o tabuleiro com habilidade
// utilize loops aninhados e o printf para exibir o tabuleiro atualizado
// mostrando areas afetadas pelas habilidades especiais

// agua = 0
// navio = 3
// area afetada pela habilidade = 5

// utilizer condicionais

#include <stdio.h>


int main() {
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};

    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // inicializa com água
        }
    }

 

    // definir matriz de habilidade em forma de cruz (5x5)
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };  
    // ponto de origem para habilidade em forma de cruz
    int origemCruzLinha = 4; // linha 4
    int origemCruzColuna = 4; // coluna 4
    // aplicar habilidade em forma de cruz no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int tabLinha = origemCruzLinha - 2 + i;
                int tabColuna = origemCruzColuna - 2 + j;
                // verificar limites do tabuleiro
                if (tabLinha >= 0 && tabLinha < 10 && tabColuna >= 0 && tabColuna < 10) {
                    tabuleiro[tabLinha][tabColuna] = 5; // marcar como área afetada
                }
            }
        }
    }
    // definir matriz de habilidade em forma de cone (5x5)
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    }; 
    // ponto de origem para habilidade em forma de cone
    int origemConeLinha = 2; // linha 2
    int origemConeColuna = 7; // coluna 7
    // aplicar habilidade em forma de cone no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                int tabLinha = origemConeLinha - 2 + i;
                int tabColuna = origemConeColuna - 2 + j;
                // verificar limites do tabuleiro
                if (tabLinha >= 0 && tabLinha < 10 && tabColuna >= 0 && tabColuna < 10) {
                    tabuleiro[tabLinha][tabColuna] = 5; // marcar como área afetada
                }
            }
        }
    }
    // definir matriz de habilidade em forma de octaedro (5x5)
    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    // ponto de origem para habilidade em forma de octaedro
    int origemOctaedroLinha = 7; // linha 7
    int origemOctaedroColuna = 2; // coluna 2
    // aplicar habilidade em forma de octaedro no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                int tabLinha = origemOctaedroLinha - 2 + i;
                int tabColuna = origemOctaedroColuna - 2 + j;
                // verificar limites do tabuleiro
                if (tabLinha >= 0 && tabLinha < 10 && tabColuna >= 0 && tabColuna < 10) {
                    tabuleiro[tabLinha][tabColuna] = 5; // marcar como área afetada
                }
            }
        }
    }
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
