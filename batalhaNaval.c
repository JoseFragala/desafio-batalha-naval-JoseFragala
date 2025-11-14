#include <stdio.h>
#include <stdlib.h>

/*
  BATALHA NAVAL - Nível Novato
  - Tabuleiro 10x10 (matriz)
  - 0 = água
  - 3 = parte do navio
  - Dois navios tamanho 3: um horizontal e outro vertical
  - Coordenadas dos navios definidas diretamente no código
  - Valida: dentro dos limites e sem sobreposição
*/

int main(void) {
    /* 1) Criando e inicializando o tabuleiro (10x10) com zeros */
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }

    /* 2) Definindo tamanho dos navios */
    const int TAM_NAVIO = 3;

    /* 3) Definindo posições iniciais (você pode alterar estes valores)
       - navio_horizontal: linha_h, coluna_h (coluna_h é a posição inicial mais à esquerda)
       - navio_vertical: linha_v, coluna_v (linha_v é a posição inicial mais ao topo)
       Atenção: índices vão de 0 a 9 nas duas dimensões.
    */
    int linha_h = 2;   /* linha do navio horizontal (0..9) */
    int coluna_h = 3;  /* coluna inicial do navio horizontal (0..9) */

    int linha_v = 6;   /* linha inicial do navio vertical (0..9) */
    int coluna_v = 7;  /* coluna do navio vertical (0..9) */

    /* 4) Validando limites para o navio horizontal */
    if (coluna_h < 0 || coluna_h + TAM_NAVIO - 1 > 9 || linha_h < 0 || linha_h > 9) {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    /* 5) Validando limites para o navio vertical */
    if (linha_v < 0 || linha_v + TAM_NAVIO - 1 > 9 || coluna_v < 0 || coluna_v > 9) {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    /* 6) Verificar sobreposição: Checar cada célula que será ocupada */
    int sobreposicao = 0;
    /* Checar horizontal */
    for (int k = 0; k < TAM_NAVIO; k++) {
        int r = linha_h;
        int c = coluna_h + k;
        if (tabuleiro[r][c] != 0) sobreposicao = 1;
    }
    /* Checar vertical */
    for (int k = 0; k < TAM_NAVIO; k++) {
        int r = linha_v + k;
        int c = coluna_v;
        if (tabuleiro[r][c] != 0) sobreposicao = 1;
    }

    if (sobreposicao) {
        printf("Erro: navios se sobrepõem. Escolha posições diferentes.\n");
        return 1;
    }

    /* 7) Posicionar navio horizontal (marca com 3) */
    for (int k = 0; k < TAM_NAVIO; k++) {
        tabuleiro[linha_h][coluna_h + k] = 3;
    }

    /* 8) Posicionar navio vertical (marca com 3) */
    for (int k = 0; k < TAM_NAVIO; k++) {
        tabuleiro[linha_v + k][coluna_v] = 3;
    }

    /* 9) Exibindo o tabuleiro com cabeçalho das colunas (A..J) */
    char colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};
    printf("\n   TABULEIRO BATALHA NAVAL\n\n");
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf(" %c", colunas[j]);      // Cabeçalho de colunas
    }
    printf("\n");

    /* Imprime cada linha: número da linha + valores separados por espaço */
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i);               // Número da linha (0..9)
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = água, 3 = parte do navio\n\n");
    return 0;
}
