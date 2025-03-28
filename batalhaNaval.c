#include <stdio.h>

// 1. FUNÇÃO PARA APLICAR HABILIDADE

void aplicarHab(int tabuleiro[10][10], int habilidade[5][5], int linhaOrigem, int colunaOrigem, int tamanhoHab) {

    for (int linhaHab = 0; linhaHab < tamanhoHab; linhaHab++) {

        for (int colunaHab = 0; colunaHab < tamanhoHab; colunaHab++) {

            if (habilidade[linhaHab][colunaHab] == 1) {

                int linha = linhaOrigem + linhaHab - tamanhoHab / 2;
                int coluna = colunaOrigem + colunaHab - tamanhoHab / 2;
                // VERIFICA SE A POSIÇÃO ESTÁ DENTRO DO TABULEIRO
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {

                    tabuleiro[linha][coluna] = 5; // MARCA A ÁREA AFETADA PELA HABILIDADE
                }
            }
        }
    }
}

int main() {
    int tabuleiro[10][10] = {0}; // 2. INICIALIZA O TABULEIRO COM ÁGUA (0)

    // 3. DEFININDO AS MATRIZES DE HABILIDADES (CONE, CRUZ, OCTAEDRO)
    
    int cone[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };

    int cruz[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // 4. POSIÇÕES DE ORIGEM DAS HABILIDADES NO TABULEIRO

    int origemCone[2] = {2, 2};
    int origemCruz[2] = {6, 2};
    int origemOctaedro[2] = {7, 7};

    // 5. APLICANDO AS HABILIDADES NO TABULEIRO

    aplicarHab(tabuleiro, cone, origemCone[0], origemCone[1], 5);
    aplicarHab(tabuleiro, cruz, origemCruz[0], origemCruz[1], 5);
    aplicarHab(tabuleiro, octaedro, origemOctaedro[0], origemOctaedro[1], 5);

    // 6. DEFININDO OS NAVIOS

    int navio1[3] = {3, 3, 3}; // Navio horizontal
    int navio2[3] = {3, 3, 3}; // Navio vertical
    int navio3[3] = {3, 3, 3}; // Navio na diagonal (canto superior esquerdo para o inferior direito)
    int navio4[3] = {3, 3, 3}; // Navio na diagonal (canto superior direito para o inferior esquerdo)

    // 7. POSIÇÃO INICIAL DOS NAVIOS

    int linha1 = 0, coluna1 = 3;
    int linha2 = 5, coluna2 = 9;
    int linhaDiagonal1 = 2, colunaDiagonal1 = 2;
    int linhaDiagonal2 = 0, colunaDiagonal2 = 9;

    // 8. VERIFICA SE O NAVIO 1 CABE NO TABULEIRO E NÃO SE SOBREPÕE

    if (coluna1 + 2 < 10) {

        int podePosicionar = 1;

        for (int posicaoNavio1 = 0; posicaoNavio1 < 3; posicaoNavio1++) {
            
            if (tabuleiro[linha1][coluna1 + posicaoNavio1] != 0) {
                podePosicionar = 0; // JÁ OCUPADO
                break;
            }
        }
        if (podePosicionar) {

            for (int posicaoNavio1 = 0; posicaoNavio1 < 3; posicaoNavio1++) {
                tabuleiro[linha1][coluna1 + posicaoNavio1] = navio1[posicaoNavio1]; // POSICIONA HORIZONTALMENTE
            }
        }
    }

    // 9. VERIFICA SE O NAVIO 2 CABE NO TABULEIRO E NÃO SE SOBREPÕE

    if (linha2 + 2 < 10) {

        int podePosicionar = 1;

        for (int posicaoNavio2 = 0; posicaoNavio2 < 3; posicaoNavio2++) {

            if (tabuleiro[linha2 + posicaoNavio2][coluna2] != 0) {
                podePosicionar = 0; // JÁ OCUPADO
                break;
            }
        }
        if (podePosicionar) {

            for (int posicaoNavio2 = 0; posicaoNavio2 < 3; posicaoNavio2++) {
                tabuleiro[linha2 + posicaoNavio2][coluna2] = navio2[posicaoNavio2]; // POSICIONA VERTICALMENTE
            }
        }
    }

    // 10. VERIFICA SE O NAVIO 3 CABE NO TABULEIRO E NÃO SE SOBREPÕE

    if (linhaDiagonal1 + 2 < 10 && colunaDiagonal1 + 2 < 10) {

        int podePosicionar = 1;

        for (int posicaoDiagonal1 = 0; posicaoDiagonal1 < 3; posicaoDiagonal1++) {

            if (tabuleiro[linhaDiagonal1 + posicaoDiagonal1][colunaDiagonal1 + posicaoDiagonal1] != 0) {
                podePosicionar = 0; // JÁ OCUPADO
                break;
            }
        }
        if (podePosicionar) {

            for (int posicaoDiagonal1 = 0; posicaoDiagonal1 < 3; posicaoDiagonal1++) {
                tabuleiro[linhaDiagonal1 + posicaoDiagonal1][colunaDiagonal1 + posicaoDiagonal1] = navio3[posicaoDiagonal1]; // POSICIONA DIAGONALMENTE
            }
        }
    }

    // 11. VERIFICA SE O NAVIO 4 CABE NO TABULEIRO E NÃO SE SOBREPÕE

    if (linhaDiagonal2 + 2 < 10 && colunaDiagonal2 - 2 >= 0) {

        int podePosicionar = 1;

        for (int posicaoDiagonal2 = 0; posicaoDiagonal2 < 3; posicaoDiagonal2++) {

            if (tabuleiro[linhaDiagonal2 + posicaoDiagonal2][colunaDiagonal2 - posicaoDiagonal2] != 0) {
                podePosicionar = 0; // JÁ OCUPADO
                break;
            }
        }
        if (podePosicionar) {

            for (int posicaoDiagonal2 = 0; posicaoDiagonal2 < 3; posicaoDiagonal2++) {
                tabuleiro[linhaDiagonal2 + posicaoDiagonal2][colunaDiagonal2 - posicaoDiagonal2] = navio4[posicaoDiagonal2]; // POSICIONA DIAGONALMENTE
            }
        }
    }

    // 12. EXIBINDO O TABULEIRO

    printf("\n*** TABULEIRO BATALHA NAVAL ***\n");

    // 13. EXIBIR LETRAS NO TOPO

    printf("\n   ");

    for (int colunaTopo = 0; colunaTopo < 10; colunaTopo++) {

        printf(" %c", 'A' + colunaTopo); // Letras de A a J
    }
    printf("\n");

    // 14. EXIBIR NÚMEROS AO LADO

    for (int linha = 0; linha < 10; linha++) {

        printf("%2d ", linha); // Imprime o número da linha

        for (int coluna = 0; coluna < 10; coluna++) {

            if (tabuleiro[linha][coluna] == 0)
                printf(" 0"); // Água
            else if (tabuleiro[linha][coluna] == 3)
                printf(" 3"); // Navio
            else if (tabuleiro[linha][coluna] == 5)
                printf(" 1"); // 15. ÁREA AFETADA PELA HABILIDADE
        }
        printf("\n");
    }

    return 0;
}
