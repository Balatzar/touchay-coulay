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
    boats = ft_generateBoats(); // genère aléatoirement les positions des bateaux
    ft_beginGame(); // affiche les règles
    ft_printGrid(grid);

   for (i = 1; i <= 24; ++i)
   {
        bomb = (char*)malloc(sizeof(char) * 3);
        do
        {
            if (error == 0)
                ft_putError("\nVeuillez inscrire une position correcte et appuyer sur Entrée (ex : A1)\n");
            printf("\nQuelle position voulez-vous bombarder ?\n");
            scanf("%2s", bomb);
            bomb[2] = '\0';
            error = ft_checkBomb(bomb);// vérifie si la position donnée est valide, retourne 1 si bon
        }
        while (error != 1);
        if (ft_checkHit(boats, bomb)) // renvoit un si le tir touche un navire
        {
            ++hits;
            printf("%i\n", hits);
            grid = ft_hit(grid, bomb); // update la grid avec un touché et affiche un message indiquant le coup réussi
        }
        else
            grid = ft_miss(grid, bomb); // update la grid avec un manqué et affiche un message indiquant le coup manqué
        if (hits == 9)
            i = 24;
        ++coups;
        free(bomb);
        printf("\nIl vous reste %i coups.\n", 24 - coups);
        ft_printGrid(grid); // imprime la grille
   }
   if (hits == 9)
        printf("\nBravo c'est gagné ! Et en seulement %i coups !\n", coups);
    else
        printf("\nDommage c'est raté :/\n");
    ft_printGrid(grid);
    return 0;
}
