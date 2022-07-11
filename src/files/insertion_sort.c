#include "../../inc/push_swap.h"

int ft_findlast(p_list **list)
{
    int size;
    p_list *head;

    size = ft_size(list);
    head = *list;
    if (size == 0)
        return (-1);
    if (size > 1)
    {
        while (head->next)
            head = head->next;
        return (head->value);
    }
    return (head->value);
}

int ft_findpos(p_list **list, int i, int low, int high)
{
    int count;
    p_list *head;

    count = 0;
    head = *list;
    if (i < low)
        i = low;
    else if (i > high)
        i = high;
    while (head->next)
    {
        if ((i > head->value))
            return (count);
        head = head->next;
        count++;
    }
    return (count);
}

void ft_preinsert(p_list **stka, p_list **stkb, p_list *seqlist)
{
    int n;
    int size;
    int mid;
    int bottom;

    n = 0;
    size = ft_size(stka);
    mid = ft_findmid(&seqlist, 0, ft_size(&seqlist) / 2);
    bottom = ft_findlast(stka);
    while (size > 3 && ft_checksort(stka, 1) != 0)
    {
        if ((*stka)->value > bottom)
        {
            bottom = (*stka)->value;
            if (ft_size(stkb) > 1 && (*stkb)->value > mid)
                ft_drotate(stka, stkb);
            else
                ft_rotate(stka, 'a', 1);
        }
        else
        {
            size -= ft_push(stka, stkb, 'b');
            if ((*stkb)->value > ft_findlast(stkb))
                ft_rotate(stkb, 'b', 1);
            else if (ft_size(stkb) > 1 && (*stkb)->value > (*stkb)->next->value)
            {
                if (ft_size(stkb) > 1 && (*stkb)->value > (*stkb)->next->value)
                    ft_dswap(stka, stkb);
                else
                    ft_swap(stkb, 'b', 1);
            }
        }
    }

    ft_small3(stka, 'a');

    int i;
    int low;
    int high;
    low = (*stka)->value;
    high = ft_findlast(stka);
    i = 0;
    size = ft_size(stkb);
    while (size > 0)
    {
        if ((*stkb)->value < (*stka)->value && (*stkb)->value > bottom)
            size -= ft_push(stkb, stka, 'a');
        else if ((*stkb)->value < low && (*stka)->value == low)
        {
            size -= ft_push(stkb, stka, 'a');
            low = (*stka)->value;
        }
        else
        {
            i = ft_findpos(stka, (*stkb)->value, low, high);
            if (i < (ft_size(stka) / 2))
            {
                bottom = (*stka)->value;
                ft_rotate(stka, 'a', 1);
            }
            else
            {
                ft_rrotate(stka, 'a', 1);
                bottom = ft_findlast(stka);
            }
        }
    }
    if (ft_findlowest(stka, ft_size(stka) / 2) > mid)
    {
        while ((*stka)->value != low)
            ft_rrotate(stka, 'a', 1);
    }
    else
    {
        while ((*stka)->value != low)
            ft_rotate(stka, 'a', 1);
    }
}