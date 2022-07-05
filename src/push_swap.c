#include "../inc/push_swap.h"

void ft_small2(p_list **list, char t, int i)
{
    if (i == 1 && (*list)->value > (*list)->next->value)
        ft_swap(list, t);
    else if (i == -1 && (*list)->value < (*list)->next->value)
        ft_swap(list, t);
}

void ft_small3(p_list **list, char t)
{
    int a;
    int b;
    int c;

    a = (*list)->value;
    b = (*list)->next->value;
    c = (*list)->next->next->value;
    if (a > b || b > c || a > c)
    {
        if (a > b && a > c)
            ft_rotate(list, t);
        else if (a < b && b > c)
            ft_rrotate(list, t);
        else if (a > b && b < c && a < c)
            ft_swap(list, t);
        ft_small3(list, t);
    }
}

void ft_small5(p_list **stka, p_list **stkb, p_list *seqlist)
{
    int i;
    int mid;
    p_list *head;

    i = 0;
    head = seqlist;
    while (i < 2)
    {
        head = head->next;
        i++;
    }
    mid = head->value;
    head = *stka;
    while (i > 0)
    {
        if (head->value < mid)
            i -= ft_push(stka, stkb, 'b');
        else
            ft_rotate(stka, 'a');
        head = *stka;
    }
    ft_small3(stka, 'a');
    ft_small2(stkb, 'b', -1);
    ft_push(stkb, stka, 'a');
    ft_push(stkb, stka, 'a');
}

void ft_btoa(p_list **stka, p_list **stkb, int size)
{
    int i;
    int n;
    int a;
    int mid;

    i = 0;
    n = 0;
    a = 0;
    if (size % 2 == 1)
        a = 1;
    if (size == 1)
        ft_push(stkb, stka, 'a');
    else if (size == 2)
    {
        if ((*stkb)->value < (*stkb)->next->value)
            ft_swap(stkb, 'b');
        ft_push(stkb, stka, 'a');
        ft_push(stkb, stka, 'a');
    }
    else if (size > 2)
    {
        ft_setseq(stkb, ft_size(stkb));
        if (ft_issort(stkb, -1) > 0)
        {
            ft_issort(stkb, 1);
            mid = ft_getmid(stkb, (ft_size(stkb) - size) + (size / 2));
            while (i < (size / 2) + a)
            {
                if ((*stkb)->value >= mid)
                    i += ft_push(stkb, stka, 'a');
                else
                    n += ft_rotate(stkb, 'b');
            }
            while (size < ft_size(stkb) && n > 0)
                n -= ft_rrotate(stkb, 'b');
            ft_atob(stka, stkb, i);
            ft_btoa(stka, stkb, size - i);
        }
        else
        {
            while (size > 0)
                size -= ft_push(stkb, stka, 'a');
        }
    }
}

void ft_atob(p_list **stka, p_list **stkb, int size)
{
    int i;
    int n;
    int mid;

    i = 0;
    n = 0;
    ft_setseq(stka, ft_size(stka));
    if (size == 2)
        ft_small2(stka, 'a', 1);
    else if (size > 2)
    {
        if (ft_issort(stka, 1) > 0)
        {
            mid = ft_getmid(stka, (size / 2));
            while (i < (size / 2))
            {
                if ((*stka)->value < mid)
                    i += ft_push(stka, stkb, 'b');
                else
                    n += ft_rotate(stka, 'a');
            }
            while (size < ft_size(stka) && n > 0)
                n -= ft_rrotate(stka, 'a');
            ft_atob(stka, stkb, size - i);
        }
        ft_btoa(stka, stkb, i);
    }
}

void ft_pushswap(p_list **list, p_list **seqlist)
{
    int size;
    p_list *stka;
    p_list *stkb;

    stka = *list;
    stkb = 0;
    size = ft_size(list);
    if (size <= 1)
        ft_exit("", list, 0);
    else if (size == 2)
        ft_small2(&stka, 'a', 1);
    else if (size == 3)
        ft_small3(&stka, 'a');
    else if (size == 5)
        ft_small5(&stka, &stkb, *seqlist);
    else if (ft_issort(&stka, 1) > 0)
        ft_atob(&stka, &stkb, size);
    *list = stka;
    ft_freelist(list);
}

int main(int argc, char **argv)
{
    int i;
    char **arr;
    p_list *list;
    p_list *seqlist;

    i = 0;
    arr = 0;
    list = 0;
    seqlist = 0;
    // No parameter passing in -> Display nothing
    if (argc == 1 || argv[1] == 0)
        ft_exit("", 0, 0);
    ft_parsing(&list, &seqlist, argc, argv);
    ft_pushswap(&list, &seqlist);
    ft_freelist(&seqlist);
}