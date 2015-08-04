#include "header.h"

void ft_printGrid(char **grid)
{
    int i = 0;

    while (i < 9)
    {
        printf(" %s", grid[i]);
        ++i;
    }
}

void ft_putError(char *str)
{
    while (*str++)
        write (2, str - 1, 1);
}

char **ft_initGrid(void)
{
    char **grid;
    int i = 1;
    int j = 1;
    char c = 'A';

    grid = (char**)malloc(sizeof(char*) * 9);
    grid[0] = (char*)malloc(sizeof(char) * 19);
    grid[0] = "  1 2 3 4 5 6 7 8\n\0";
    while (i <= 8)
    {
        grid[i] = (char*)malloc(sizeof(char) * 18);
        j = 1;
        grid[i][0] = c;
        while (j <= 16)
        {
            grid[i][j] = ' ';
            grid[i][j + 1] = '.';
            j += 2;
        }
        grid[i][17] = '\n';
        grid[i][18] = '\0';
        ++i;
        ++c;
    }
    return (grid);
}

void ft_beginGame(void)
{
    printf("Bonjour !\nLes règles sont simples, il y a trois bateaux à détruire et 24 coups pour le faire.\n");
    printf("Les bateaux sont de taille 2, 3 et 4 blocks.\nBonne chance !\n\n");
}

int ft_checkBomb(char *bomb)
{
    if (!((bomb[0] >= 'a' && bomb[0] <= 'h') || (bomb[0] >= 'A' && bomb[0] <= 'H'))) // si le premier char n'est PAS entre a et h ou A et H
        return(0);
    if (!(bomb[1] >= '1' && bomb[1] <= '8')) // si le deuxieme char n'est PAS entre 1 et 8
        return (0);
    return (1);
}

char **ft_generateBoats(void)
{
    // génération de positions fixes pour tester
    char **boats;

    boats = (char**)malloc(sizeof(char*) * 3);
    boats[0] = "2325\0";
    boats[1] = "425262\0";
    boats[2] = "74757677\0";
    return (boats);
}

int ft_checkHit(char **boats, char *bomb)
{

    int i = 0;
    int j = 0;

    if (bomb[0] >= 'a' && bomb[0] <= 'z')
        bomb[0] -= 48;
    else
        bomb[0] -= 16;
    while (i < 3)
    {
        while (boats[i][j - 1])
        {
            if ((boats[i][j] == bomb[0]) && (boats[i][j + 1] == bomb[1]))
                return (1);
            j += 2;
        }
        j = 0;
        ++i;
    }
    return (0);
}

char **ft_hit(char **grid, char *bomb)
{
    int i = 0;
    int j = 0;

    if (bomb[0] >= 'a' && bomb[0] <= 'z')
        i = bomb[0] - 96;
    else
        i = bomb[0] - 64;
    j = bomb[0] - '0';
    grid[i][j] = 'x';
    return (grid);
}

char **ft_miss(char **grid, char *bomb)
{
    int i = 0;
    int j = 0;

    if (bomb[0] >= 'a' && bomb[0] <= 'z')
        i = bomb[0] - 96;
    else
        i = bomb[0] - 64;
    j = bomb[0] - '0';
    grid[i][j] = 'o';
    return (grid);
}
