#include <stdio.h>
#include <stdio.h>

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

int main()
{
    printf("Hello World");

    return 0;
}
