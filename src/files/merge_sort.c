#include "../../inc/push_swap.h"

int ft_btoaswap(p_list **stka, p_list **stkb, p_list **seqlist, int size)
{
    int i;
    int n;
    int mid;
    int a;

    i = 0;
    n = 0;
    a = 0;
    mid = ft_findmid(seqlist, ft_findlowest(stkb, size), (size / 2));
    if (size % 2 == 1)
        a = 1;
    while (i < (size / 2) + a)
    {
        if ((*stkb)->value >= mid)
            i += ft_push(stkb, stka, 'a', 1);
        else
            n += ft_rotate(stkb, 'b', 1);
    }
    while (size < ft_size(stkb) && n > 0)
        n -= ft_rrotate(stkb, 'b', 1);
    return (i);
}

void ft_btoa(p_list **stka, p_list **stkb, p_list **seqlist, int size)
{
    int i;

    i = 0;
    if (size == 1)
        ft_push(stkb, stka, 'a', 1);
    else if (size == 2)
    {
        if ((*stka)->value > (*stka)->next->value)
            ft_dswap(stka, stkb, 1);
        else if ((*stkb)->value < (*stkb)->next->value)
            ft_swap(stkb, 'b', 1);
        ft_push(stkb, stka, 'a', 1);
        ft_push(stkb, stka, 'a', 1);
    }
    else if (size > 2)
    {
        if (ft_issort(stkb, -1) == -1)
        {
            i = ft_btoaswap(stka, stkb, seqlist, size);
            ft_atob(stka, stkb, seqlist, i);
            ft_btoa(stka, stkb, seqlist, size - i);
        }
        else
            while (size > 0)
                size -= ft_push(stkb, stka, 'a', 1);
    }
}

int ft_atobswap(p_list **stka, p_list **stkb, p_list **seqlist, int size)
{
    int i;
    int n;
    int mid;

    i = 0;
    n = 0;
    mid = ft_findmid(seqlist, ft_findlowest(stka, size), (size / 2));
    while (i < (size / 2))
    {
        if ((*stka)->value < mid)
            i += ft_push(stka, stkb, 'b', 1);
        else
            n += ft_rotate(stka, 'a', 1);
    }
    while (size < ft_size(stka) && n > 0)
        n -= ft_rrotate(stka, 'a', 1);
    return (i);
}

void ft_atob(p_list **stka, p_list **stkb, p_list **seqlist, int size)
{
    int i;

    i = 0;
    if (size == 2)
        ft_small2(stka, 'a', 1);
    else if (size > 2)
    {
        if (ft_issort(stka, 1) == -1)
        {
            i = ft_atobswap(stka, stkb, seqlist, size);
            ft_atob(stka, stkb, seqlist, size - i);
        }
        ft_btoa(stka, stkb, seqlist, i);
    }
}
