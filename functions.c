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
