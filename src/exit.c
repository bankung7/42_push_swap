#include "../inc/push_swap.h"

void ft_freelist(p_list **list)
{
    int i;
    p_list *head;

    i = 0;
    head = *list;
    if (*list)
    {
        while (*list)
        {
            head = *list;
            *list = (*list)->next;
            free(head);
            i++;
        }
    }
    //printf("done free %d node\n", i);
}

void ft_freearr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}

void ft_exit(char *str)
{
    ft_printf("%s", str);
    exit(0);
}