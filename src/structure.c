#include "../inc/push_swap.h"

void    ft_readlist(ps_list *list)
{
    while (list != 0)
    {
        ft_printf("%d", list->value);
        write(1, "\n", 1);
        list = list->next;
    }
}

static int  ft_listsize(ps_list *list)
{
    int     i;

    i = 0;
    while (list != 0)
    {
        list = list->next;
        i++;
    }
    return (i);
}

static ps_list  *ft_newnode(char *str)
{
    ps_list *node;

    node = malloc(sizeof(ps_list));
    if (!node)
        return (0);
    node->next = 0;
    node->value = ft_atoi(str);
    return (node);
}

static void ft_listadd(ps_list **list, ps_list *new)
{
    ps_list *n;

    n = *list;
    if (*list)
    {
        while (n->next)
            n = n->next;
        n->next = new;
    }
    else
        *list = new;
}

ps_list     *ft_build(char **arr, int i)
{
    ps_list *list;

    list = 0;
    while (arr[i])
        ft_listadd(&list, ft_newnode(arr[i++]));
    ft_printf("total %d node in this list", ft_listsize(list));
    write(1, "\n", 1);
    return (list);
}