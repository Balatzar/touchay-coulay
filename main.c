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
    t_list *elem; // liste pour contenir les coups joués

    elem = (t_list*)malloc(sizeof(t_list));
    elem = NULL;

    grid = ft_initGrid(); // initialise la grille vide
    boats = ft_generateBoats(); // genère aléatoirement les positions des bateaux
    ft_beginGame(); // affiche les règles
    ft_printGrid(grid);

   for (i = 1; i <= 24; ++i)
   {

        printf("%s\n", elem->data);
        bomb = (char*)malloc(sizeof(char) * 3);
        do
        {
            if (error == 0)
                ft_putError("\nVeuillez inscrire une position correcte et appuyer sur Entrée (ex : A1)\n");
            printf("\nQuelle position voulez-vous bombarder ?\n\n");
            scanf("%2s", bomb);
            bomb[2] = '\0';
            error = ft_checkBomb(elem, bomb);// vérifie si la position donnée est valide, retourne 1 si bon
        }
        while (error != 1);
        elem = ft_addElem(elem, bomb);
        if (ft_checkHit(boats, bomb)) // renvoit 1 si le tir touche un navire
        {
            ++hits;
            grid = ft_hit(grid, bomb); // update la grid avec un touché et affiche un message indiquant le coup réussi
            printf("\nTouché !\n");
        }
        else
        {
            printf("\nRaté !\n");
            grid = ft_miss(grid, bomb); // update la grid avec un manqué et affiche un message indiquant le coup manqué
        }
        if (hits == 9)
            i = 24;
        ++coups;
        free(bomb);
        printf("\nIl vous reste %i coups.\n\n", 24 - coups);
        ft_printGrid(grid); // imprime la grille
   }
   if (hits == 9)
        printf("\nBravo c'est gagné ! Et en seulement %i coups !\n\n", coups);
    else
        printf("\nDommage c'est raté :/\n\n");
    ft_printGrid(grid);
    return 0;
}
