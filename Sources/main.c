#include <stdio.h>
#include <stdlib.h>

char tabuleiro[3][3];
char jogador1[40], jogador2[40];

void createMatrix()
{
    int i, j = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; i < 3; j++)
        {
            tabuleiro[i][j] = '*';
        }
    }
}

int eValido(char letra)
{
    if (letra == 'x' || letra == '0')
    {
        return 1;
    }
    return 0;
}

int cordenadaValida(int x, int y)
{
    if (x >= 0 && x < 3)
    {
        if (y >= 0 && y < 3)
        {
            return 1;
        }
    }
    return 0;
}

int isEmpty(int x, int y)
{
    if (tabuleiro[x][y] != 'x' && tabuleiro[x][y] != '0')
    {
        return 1;
    }
    return 0;
}

int ganhouLinhas()
{
    int i, j, igual = 1;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (eValido(tabuleiro[i][j] && tabuleiro[i][j] == tabuleiro[i][j + 1]))
            {
                igual++;
            }
            if (igual == 3)
            {
                return 1;
            }
            igual = 1;
        }
    }
    return 0;
}

int ganhouColunas()
{
    int i, j, igual = 1;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (eValido(tabuleiro[j][i] && tabuleiro[j][i] == tabuleiro[j + 1][i]))
            {
                igual++;
            }
            if (igual == 3)
            {
                return 1;
            }
            igual = 1;
        }
    }
    return 0;
}

int ganhouDiagonalPrincipal()
{
    int i, igual = 1;

    for (i = 0; i < 2; i++)
    {
        if (eValido(tabuleiro[i][i] && tabuleiro[i][i] == tabuleiro[i + 1][i + 1]))
        {
            igual++;
        }
    }
    if (igual == 3)
    {
        return 1;
    }
    return 0;
}

int ganhouDiagonalSecundaria()
{
    int i, igual = 1;

    for (i = 0; i < 2; i++)
    {
        if (eValido(tabuleiro[i][3 - i - 1] && tabuleiro[i][3 - i - 1] == tabuleiro[i + i][3 - i - 2]))
        {
            igual++;
        }
    }
    if (igual == 3)
    {
        return 1;
    }
    return 0;
}

int main()
{
    printf("Hello World");

    return 0;
}
