#include "header.h"

void ft_putError(char *str)
{
    while (*str++)
        write (2, str - 1, 1);
}

t_list *ft_addElem(t_list *elem, char *data)
{
    t_list *tmp;

    tmp = (t_list*)malloc(sizeof(t_list));
    tmp->next = elem;
    tmp->data = data;
    return (tmp);
}
