#include "../inc/push_swap.h"

void ft_sort(ps_list **list)
{
    ps_list *n;

    while ((*list)->next)
    {
        if ((*list)->value > (*list)->next->value)
        {
            n = *list;
            *list = n->next;
            n->next = (*list)->next;
            (*list)->next = n;
        }
    }
}