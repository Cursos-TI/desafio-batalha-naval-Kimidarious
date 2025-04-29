#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Tamanho do tabuleiro e dos navios(fixos)
    int tamanhoTabuleiro = 10;
    int tamanhoNavio = 3;

    // matriz 10x10 representando o tabuleiro
    int tabuleiro[10][10];

    // Inicializa o tabuleiro com água(0)
    int linha, coluna;
    for (linha = 0; linha < tamanhoTabuleiro; linha++)
    {
        for (coluna = 0; coluna < tamanhoTabuleiro; coluna++)
        {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Coordenadas iniciais dos navios
    int linhaNavioH = 2;  // linha do Navio horizontal
    int colunaNavioH = 4; // Coluna inicial do navio horizontal

    int linhaNavioV = 5;  // linha inicial do Navio vertical
    int colunaNavioV = 7; // Coluna do navio vertical

    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaNavioH + tamanhoNavio <= tamanhoTabuleiro)
    {
        // Preenche o navio horizontal na matriz(valor 3)
        for (int i = 0; i < tamanhoNavio; i++)
        {
            tabuleiro[linhaNavioH][colunaNavioH + i] = 3;
        }
    }
    else
    {
        printf("Navio horizontal está fora dos limites!\n");
    }

    // verifica se o navio vertical cabe no tabuleiro
    if (linhaNavioV + tamanhoNavio <= tamanhoTabuleiro)
    {
        // Verifica se há sobreposição com o navio horizontal
        int podeColocar = 1; // 1 = pode colocar, 0 = nao pode colocar
        for (int i = 0; i < tamanhoNavio; i++)
        {
            if (tabuleiro[linhaNavioV + i][colunaNavioV] == 3)
            {
                podeColocar = 0;
            }
        }

        if (podeColocar == 1)
        {
            for (int i = 0; i < tamanhoNavio; i++)
            {
                tabuleiro[linhaNavioV + i][colunaNavioV] = 3;
            }
        }
        else
        {
            printf("Navio vertical sobrepõe outro navio!\n");
        }
    }
    else
    {
        printf("Navio vertical está fora dos limites!\n");
    }

    // Exibe o tabuleiro
    printf("Tabuleiro:\n");
    for (linha = 0; linha < tamanhoTabuleiro; linha++)
    {
        for (coluna = 0; coluna < tamanhoTabuleiro; coluna++)
        {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
