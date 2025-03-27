#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0}; // 1. Inicializa o tabuleiro com 0 (água)

    // 2. Define os navios
    int navio1[3] = {3, 3, 3}; // Navio horizontal
    int navio2[3] = {3, 3, 3}; // Navio vertical

    // Posição inicial dos navios
    int linha1 = 0, coluna1 = 0; // Navio horizontal
    int linha2 = 7, coluna2 = 9; // Navio vertical

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

    printf("\n*** TABULEIRO BATALHA NAVAL ***\n");

    // 5. Exibir letras no topo
    printf("\n   "); // Espaço para alinhar com os números à esquerda
    for (int colunaTopo = 0; colunaTopo < 10; colunaTopo++) {
        printf(" %c", 'A' + colunaTopo); // Letras de A a J
    }
    printf("\n");

    // 6. Exibir números ao lado
    for (int linha = 0; linha < 10; linha++) {
        printf("%2d ", linha); // Imprime o número da linha
        for (int coluna = 0; coluna < 10; coluna++) {
            printf(" %d", tabuleiro[linha][coluna]); // 7. Imprime o tabuleiro
        }
        printf("\n");
    }

    return 0;
}