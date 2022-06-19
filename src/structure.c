#include "../inc/push_swap.h"

t_list  *ft_build(char **argv)
{
    int     i;
    t_list  *list;
    t_list  *node;

    i = 1;
    list = 0;
    node = 0;
    while (argv[i])
    {
        node = ft_lstnew((void *)argv[i]);
        ft_lstadd_back(&list, node);
        i++;
    }
    return (list);
}

void    ft_readnode(t_list *list)
{
    while (list != 0)
    {
        ft_printf("%s ", list->content);
        write(1, "\n", 1);
        list = list->next;
    }
    ft_printf("read completed");
    write(1, "\n", 1);
}

void    ft_freenode(t_list  *list)
{
    t_list  *node;

    while (list != 0)
    {
        node = list->next;
        free(list);
        list = node;
    }
    ft_printf("free completed");
}