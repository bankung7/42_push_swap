#include "../inc/push_swap.h"

int ft_arrsize(char *arr)
{
    int i;

    i = 0;
    if (!arr)
        return (0);
    while (arr[i])
        i++;
    return (i);
}

void ft_read(p_list **list, char *str)
{
    p_list *head;

    head = *list;
    ft_printf("%s => ", str);
    while (head)
    {
        ft_printf("%d -> ", head->value);
        head = head->next;
    }
    printf("\n");
}

int ft_size(p_list **list)
{
    int i;
    p_list *head;

    i = 0;
    head = *list;
    while (head)
    {
        head = head->next;
        i++;
    }
    return (i);
}