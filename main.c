#include "header.h"

int main()
{
    char *bomb;
    char **grid;
    char **boats;
    int hits = 0;
    int coups = 0;
    int i = 0;
    int error = 1;

    grid = ft_initGrid(); // initialise la grille vide
    boats = ft_generateBoats(); // gen�re al�atoirement les positions des bateaux
    ft_beginGame(); // affiche les r�gles
    ft_printGrid(grid);

   for (i = 1; i <= 24; ++i)
   {
        bomb = (char*)malloc(sizeof(char) * 3);
        do
        {
            if (error == 0)
                ft_putError("\nVeuillez inscrire une position correcte et appuyer sur Entr�e (ex : A1)\n");
            printf("\nQuelle position voulez-vous bombarder ?\n");
            scanf("%2s", bomb);
            bomb[2] = '\0';
            error = ft_checkBomb(bomb);// v�rifie si la position donn�e est valide, retourne 1 si bon
        }
        while (error != 1);
        if (ft_checkHit(boats, bomb)) // renvoit un si le tir touche un navire
        {
            ++hits;
            printf("%i\n", hits);
            grid = ft_hit(grid, bomb); // update la grid avec un touch� et affiche un message indiquant le coup r�ussi
        }
        else
            grid = ft_miss(grid, bomb); // update la grid avec un manqu� et affiche un message indiquant le coup manqu�
        if (hits == 9)
            i = 24;
        ++coups;
        free(bomb);
        printf("\nIl vous reste %i coups.\n", 24 - coups);
        ft_printGrid(grid); // imprime la grille
   }
   if (hits == 9)
        printf("\nBravo c'est gagn� ! Et en seulement %i coups !\n", coups);
    else
        printf("\nDommage c'est rat� :/\n");
    ft_printGrid(grid);
    return 0;
}
