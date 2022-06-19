#include "../inc/push_swap.h"

void    ft_freearr(char **arr)
{
    int     i;

    i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
    ft_printf("free %d arr completed", i);
    write(1, "\n", 1);
}

void    ft_freelist(ps_list *list)
{
    ps_list     *node;

    while (list != 0)
    {
        node = list->next;
        free(list);
        list = node;
    }
}