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

int coordenadaValida(int x, int y)
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

//Funcao responsavel por imprimir a matriz que representará o jogo da velha (tabuleiro)
void imprimirTabuleiro()
{
    int lin, col; //Variaveis para controlar a linha e a coluna

    printf("\t  0    1      2\n\n");
    for (lin = 0; lin < 3; lin++)
    { //Imprimindo o índice da linha
        printf("\t%i ", lin);
        for (col = 0; col < 3; col++)
        {
            if (eValido(tabuleiro[lin][col]))
            { //Verificar qual caracter será impresso
                printf("  %c |", tabuleiro[lin][col]);
            }
            else
            {
                printf("   |");
            }
        }
        printf("\n\t----------------\n");
    }
}

void realizarJogada()
{
    int x, y;
    int validaCoord = 0;
    int verifJogador = 1;
    int venceu = 0;
    int contJog = 0;

    //Enquanto ela for diferente de 2, significa que a posicao estavazia
    //portanto pode realizar a jogada.
    do
    {
        do
        {
            imprimirTabuleiro();
            printf("Digite a linha: ");
            scanf("%i", &x);
            printf("Digite a coluna: ");
            scanf("%i", &y);
            validaCoord = coordenadaValida(x, y); //Verifica se a coordenada digitada é valida
            if (validaCoord == 1)
            {
                validaCoord += isEmpty(x, y); //Verifica se a coordenada digitada esta vazia
            }
        } while (validaCoord != 2);
        //Verifica qual jogador está jogando
        //Se for o jogador 1 insere o X se nao insere o 0
        if (verifJogador == 1)
        {
            tabuleiro[x][y] = 'x';
        }
        else
        {
            tabuleiro[x][y] = '0';
        }
        contJog++;      //Contador para o numero de jogadas
        verifJogador++; //Passa a vez do jogador
        //Joga novamente para o jogador 1, ja que tem apenas 2 jogadores
        if (verifJogador == 3)
        {
            verifJogador = 1;
        }
        //Verifica em qual das possibilidades o jogador venceu
        venceu += ganhouLinhas();
        venceu += ganhouColunas();
        venceu += ganhouDiagonalPrincipal();
        venceu += ganhouDiagonalSecundaria();
    } while (venceu == 0 && contJog < 9); //Executa o codigo ate que algum jogador ganhe ou o numero de jogadas seja esgotado

    if (venceu != 0)
    {
        //Verifica qual o foi o jogador que venceu.
        //Como o contador do jogador chegara ate 3, o verifi-1 anula essa possibilidade
        if (verifJogador - 1 != 0)
        {
            printf("Parabens! Voce venceu %s", jogador1);
        }
        else
        {
            printf("Parabens! Voce venceu %s", jogador2);
        }
    }
}

int main()
{

    printf("Primeiro jogador, digite seu nome:");
    fgets(jogador1, 40, stdin);
    printf("Segundo jogador, digite seu nome:");
    fgets(jogador2, 40, stdin);

    realizarJogada();

    return 0;
}
