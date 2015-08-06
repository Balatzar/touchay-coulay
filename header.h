#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
    struct s_list *next;
    char *data;
} t_list;

char **ft_initGrid(void);
char **ft_generateBoats(void);
void ft_beginGame(void);
void ft_printGrid(char **grid);
int ft_checkBomb(t_list *elem, char *bomb);
int ft_checkList(t_list *elem, char *cmp);
int ft_checkHit(char **boat, char *bomb);
char **ft_hit(char **grid, char *bomb);
char **ft_miss(char **grid, char *bomb);
void ft_putError(char *str);
t_list *ft_beginList(char *data);
t_list *ft_addElem(t_list *elem, char *data);

#endif // HEADER_H
