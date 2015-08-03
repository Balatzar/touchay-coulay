#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <stdlib.h>

char **ft_initGrid(void);
char **ft_generateBoats(void);
void ft_beginGame(void);
void ft_printGrid(char **grid);
int ft_checkBomb(char *bomb);
int ft_checkHit(char **boats, char *bomb);
char **ft_hit(char **grid, char *bomb);
char **ft_miss(char **grid, char *bomb);

#endif // HEADER_H
