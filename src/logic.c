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

int ft_findq(ps_list **list, int q)
{
    int size;
    ps_list *head;

    head = *list;
    size = ft_listsize(*list) * q / 100;
    while (size > 0)
    {
        head = head->next;
        size--;
    }
    return (head->seq);
}

void ft_pushswap(ps_list **list)
{
    ps_list *head;
    ps_list *stka;
    ps_list *stkb;
    int i;

    stka = *list;
    head = *list;
    stkb = 0;
    i = ft_findq(list, 50);
    head = stka;
    while (head->next)
    {
        if (head->value < 5)
        {
            ft_push(&stka, &stkb);
            head = stka;
        }
        else
        {
            ft_rotate(&stka, 'a');
            head = stka;
        }
        head = head->next;
        ft_readlist(stka);
        ft_readlist(stkb);
        write(1, "\n", 1);
    }

    *list = stka;
    if (stkb != 0)
        ft_freelist(stkb);
}