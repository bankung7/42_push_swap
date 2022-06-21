#include "../inc/push_swap.h"

void ft_blogic(ps_list **list)
{
    if ((*list)->value < (*list)->next->value && (*list)->next->value > (*list)->next->next->value)
    {
        ft_rrotate(list, 'a');
        if ((*list)->value > (*list)->next->value)
            ft_swap(list, 'a');
    }
    else if ((*list)->value > (*list)->next->value && (*list)->value > (*list)->next->next->value)
    {
        ft_rotate(list, 'a');
        if ((*list)->value > (*list)->next->value)
            ft_swap(list, 'a');
    }
    else if ((*list)->value > (*list)->next->value && (*list)->value < (*list)->next->next->value)
        ft_swap(list, 'a');
}