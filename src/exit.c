#include "../inc/push_swap.h"

void    ft_exit(char *str, ps_list *list, char **arr)
{
    if (list != 0)
        ft_freelist(list);
    if (arr != 0)
        ft_freearr(arr);
    ft_printf("%s", str);
    exit(0);
}