#include <stdio.h>
#include <stdlib.h>

/*
    Alunos: Icaro Peretti e Eduardo Rampon
*/

// Declaração de todas as váriaveis de escopo global.

char tabuleiro[3][3];
char jogador1[40], jogador2[40];

//Funcao responsavel por criar a matriz e colocar * em todas as posições
// O "*" representará um espaço que ainda não foi jogado

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

//Valida se a entrada são caracteres válidos ( X ou 0)
int eValido(char letra)
{
//Retorna 1 se a entrada é X ou 0
    if (letra == 'x' || letra == '0')
    {
        return 1;
    }
    return 0;
}

//Funcao responsavel por verificar se a coordenada solicitada é valida, ou seja, está nos limites da matriz.
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

//Funcao responsavel por verificar se a coordenada ainda não foi jogada.
int isEmpty(int x, int y)
{
    //Retorna 1 se foi encontrado X ou 0 na posição solicitada
    if (tabuleiro[x][y] != 'x' && tabuleiro[x][y] != '0')
    {
        return 1;
    }
    return 0;
}

//Funcao responsavel por verificar se alguém ganhou nas linhas.
int ganhouLinhas(){
    int i, j, igual = 1;
    //Passa por todas as linhas e verifica se existe uma em que tem um caractere válido 3 vezes seguidas
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (eValido(tabuleiro[i][j]) && tabuleiro[i][j] == tabuleiro[i][j + 1])
            {
                igual++;
            }
        }
        if (igual == 3)
        {
            return 1;
        }
        igual = 1;
    }
    return 0;
}

//Funcao responsavel por verificar se alguém ganhou nas colunas.
int ganhouColunas()
{
    int i, j, igual = 1;
    //Percorre por todas as colunas e verifica se possui uma em que aparece um caractere válido seguido por 3 vezes
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (eValido(tabuleiro[j][i]) && tabuleiro[j][i] == tabuleiro[j + 1][i]){
                igual++;
            }
        }
        if (igual == 3)
        {
            return 1;
        }
        igual = 1;
    }
    return 0;
}

//Funcao responsavel por verificar se alguém ganhou na diagonal principal.
int ganhouDiagonalPrincipal()
{
    int i, igual = 1;
    // Percorre a diagonal pricipal e depois verifica se foram encontrado 3 caracteres iguais.
     for(i = 0; i < 2; i++) {
        if(eValido(tabuleiro[i][i]) && tabuleiro[i][i] == tabuleiro[i+1][i+1]){
            igual++;
        }
    }
    if (igual == 3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Funcao responsavel por verificar se alguém ganhou na diagonal secundária.
int ganhouDiagonalSecundaria() 
{
    int i, igual = 1;
    // Percorre a diagonal secundária e depois verifica se foram encontrado 3 caracteres iguais.
    for(i = 0; i < 2; i++) {
        if(eValido(tabuleiro[i][3-i-1]) && tabuleiro[i][3-i-1] == tabuleiro[i+1][3-i-2])
		{
        	igual++;
		}     
    }
    if(igual == 3)
	{
    	return 1;
	} 
    else
	{
      return 0;	
	}
    
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
    int verifJogador = 0;
    int venceu = 0;
    int contJog = 0;

    //Enquanto ela for diferente de 2, significa que a posicao estavazia
    //portanto pode realizar a jogada.
    while (venceu == 0 && contJog < 9)
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
        if (verifJogador % 2 == 0)
        {
            tabuleiro[x][y] = 'x';
        }
        else
        {
            tabuleiro[x][y] = '0';
        }
        verifJogador++;
        contJog++;      //Contador para o numero de jogadas
        printf("Passei aqui\n");

        //Verifica em qual das possibilidades o jogador venceu
        venceu += ganhouLinhas();
        venceu += ganhouColunas();
        venceu += ganhouDiagonalPrincipal();
        venceu += ganhouDiagonalSecundaria();
    } //Executa o codigo ate que algum jogador ganhe ou o numero de jogadas seja esgotado

    if (venceu != 0)
    {
        //Verifica qual o foi o jogador que venceu.
        //Se o resto da divisão do numero do jogador for = 1 significa que o primeiro jogador vence, se não foi o segundo
        if (verifJogador % 2 == 1)
        {
            printf("Parabens voce venceu %s", jogador1);
        }
        else
        {
            printf("Parabens voce venceu %s", jogador2);
        }
    }
}


int main()
{   
    int op;
    printf("Primeiro jogador, digite seu nome:");
    fgets(jogador1, 40, stdin);
    printf("Segundo jogador, digite seu nome:");
    fgets(jogador2, 40, stdin);
    
    realizarJogada();

    //Pergunta se o usuario quer jogar novamente
    printf("Deseja jogar novamente?\n1 - Sim\n2 - Nao\n");
    scanf("%d",&op);
    
    //Se a resposta for 1, o jogo inicia novamente
    //Se não finaliza o programa
    if(op == 1){
        realizarJogada();
    }else{
        printf("Finalizando...");
        exit(0);
    }
    return 0;
}
