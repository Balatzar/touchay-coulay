#include "header.h"
/*
int main()
{
    char *bomb;
    char **grid;
    char **boats;
    int hits = 0;
    int coups = 0;
    int i = 0;

    grid = ft_initGrid(); // initialise la grille vide
    boats = ft_generateBoats(); // genere al�atoirement les positions des bateaux
    ft_beginGame(); // affiche les regles
    ft_printGrid(grid);

   for (i = 1; i <= 24; ++i)
   {
        bomb = (char*)malloc(sizeof(char) * 3);
        do
        {
            printf("Quelle position voulez-vous bombarder ?\n");
            scanf("%2s", bomb);
            bomb[2] = '\0';
        }
        while (ft_checkBomb(bomb) != 1); // v�rifie si la position donn�e est valide et la convertit en char majuscules
        if (ft_checkHit(boats, bomb)) // renvoit un si le tir touche un navire
        {
            ++hits;
            grid = ft_hit(grid, bomb); // update la grid avec un touch� et affiche un message indiquant le coup r�ussi
        }
        else
            grid = ft_miss(grid, bomb); // update la grid avec un manqu� et affiche un message indiquant le coup manqu�
        if (hits == 9)
            i = 24;
        coups++;
        free(bomb);
        printf("Il vous reste %i coups.\n", 24 - j);
        ft_printGrid(grid); // imprime la grille
   }
   if (hits == 9)
        printf("Bravo c'est gagn� ! Et en seulement %i coups !\n", coups);
    else
        printf("Dommage c'est rat� :/\n");
    ft_printGrid(grid);
    return 0;
}
*/

int main()
{
    char **grid;

    grid = ft_initGrid();
    ft_printGrid(grid);
    return (0);
}
