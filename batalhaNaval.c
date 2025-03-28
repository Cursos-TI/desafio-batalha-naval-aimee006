#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0}; // 1. Inicializa o tabuleiro com 0 (água)

    // 2. Define os navios
    int navio1[3] = {3, 3, 3}; // Navio horizontal
    int navio2[3] = {3, 3, 3}; // Navio vertical
    int navio3[3] = {3, 3, 3}; // Navio na diagonal (canto superior esquerdo para o inferior direito)
    int navio4[3] = {3, 3, 3}; // Navio na diagonal (canto superior direito para o inferior esquerdo)

    // Posição inicial dos navios
    int linha1 = 0, coluna1 = 3; // Navio horizontal
    int linha2 = 5, coluna2 = 9; // Navio vertical
    int linhaDiagonal1 = 2, colunaDiagonal1 = 2; // Navio diagonal 1
    int linhaDiagonal2 = 0, colunaDiagonal2 = 9; // Navio diagonal 2

    // 3. Verifica se o navio 1 cabe no tabuleiro e não se sobrepõe
    if (coluna1 + 2 < 10) {
        int podePosicionar = 1;
        for (int posicaoNavio1 = 0; posicaoNavio1 < 3; posicaoNavio1++) {
            if (tabuleiro[linha1][coluna1 + posicaoNavio1] != 0) {
                podePosicionar = 0; // Já ocupado
                break;
            }
        }
        if (podePosicionar) {
            for (int posicaoNavio1 = 0; posicaoNavio1 < 3; posicaoNavio1++) {
                tabuleiro[linha1][coluna1 + posicaoNavio1] = navio1[posicaoNavio1]; // Posiciona horizontalmente
            }
        }
    }

    // 4. Verifica se o navio 2 cabe no tabuleiro e não se sobrepõe
    if (linha2 + 2 < 10) {
        int podePosicionar = 1;
        for (int posicaoNavio2 = 0; posicaoNavio2 < 3; posicaoNavio2++) {
            if (tabuleiro[linha2 + posicaoNavio2][coluna2] != 0) {
                podePosicionar = 0; // Já ocupado
                break;
            }
        }
        if (podePosicionar) {
            for (int posicaoNavio2 = 0; posicaoNavio2 < 3; posicaoNavio2++) {
                tabuleiro[linha2 + posicaoNavio2][coluna2] = navio2[posicaoNavio2]; // Posiciona verticalmente
            }
        }
    }

    
    // 5. Verifica se o navio 3 cabe no tabuleiro e não se sobrepõe
    if (linhaDiagonal1 + 2 < 10 && colunaDiagonal1 + 2 < 10) {
        int podePosicionar = 1;
        for (int posicaoDiagonal1 = 0; posicaoDiagonal1 < 3; posicaoDiagonal1++) {
            if (tabuleiro[linhaDiagonal1 + posicaoDiagonal1][colunaDiagonal1 + posicaoDiagonal1] != 0) {
                podePosicionar = 0; // Já ocupado
                break;
            }
        }
        if (podePosicionar) {
            for (int posicaoDiagonal1 = 0; posicaoDiagonal1 < 3; posicaoDiagonal1++) {
                tabuleiro[linhaDiagonal1 + posicaoDiagonal1][colunaDiagonal1 + posicaoDiagonal1] = navio3[posicaoDiagonal1]; // Posiciona diagonalmente
            }
        }
    }

    // 6. Verifica se o navio 4 cabe no tabuleiro e não se sobrepõe
    if (linhaDiagonal2 + 2 < 10 && colunaDiagonal2 - 2 >= 0) {
        int podePosicionar = 1;
        for (int posicaoDiagonal2 = 0; posicaoDiagonal2 < 3; posicaoDiagonal2++) {
            if (tabuleiro[linhaDiagonal2 + posicaoDiagonal2][colunaDiagonal2 - posicaoDiagonal2] != 0) {
                podePosicionar = 0; // Já ocupado
                break;
            }
        }
        if (podePosicionar) {
            for (int posicaoDiagonal2 = 0; posicaoDiagonal2 < 3; posicaoDiagonal2++) {
                tabuleiro[linhaDiagonal2 + posicaoDiagonal2][colunaDiagonal2 - posicaoDiagonal2] = navio4[posicaoDiagonal2]; // Posiciona diagonalmente
            }
        }
    }

    printf("\n*** TABULEIRO BATALHA NAVAL ***\n");

    // 7. Exibir letras no topo
    printf("\n   "); // Espaço para alinhar com os números à esquerda
    for (int colunaTopo = 0; colunaTopo < 10; colunaTopo++) {
        printf(" %c", 'A' + colunaTopo); // Letras de A a J
    }
    printf("\n");

    // 8. Exibir números ao lado
    for (int linha = 0; linha < 10; linha++) {
        printf("%2d ", linha); // Imprime o número da linha
        for (int coluna = 0; coluna < 10; coluna++) {
            printf(" %d", tabuleiro[linha][coluna]); // 9. Imprime o tabuleiro
        }
        printf("\n");
    }

    return 0;
}