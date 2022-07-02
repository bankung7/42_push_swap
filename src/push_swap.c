#include "../inc/push_swap.h"

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
    {
        if ((*stka)->value > (*stka)->next->value)
            ft_swap(stka, 'a');
    }
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

void ft_pushswap(p_list **list)
{
    int size;
    p_list *stka;
    p_list *stkb;

    stka = *list;
    stkb = 0;
    size = ft_size(list);
    if (size > 1)
    {
        // ft_setseq(&stka, ft_size(&stka));
        if (ft_issort(&stka, 1) > 0)
            ft_atob(&stka, &stkb, size);
        *list = stka;
    }
    // else if (size <= 3)
    //     ft_small(stka, stkb));
    ft_freelist(list);
}

int main(int argc, char **argv)
{
    int i;
    char **arr;
    p_list *list;

    i = 0;
    arr = 0;
    list = 0;
    if (argc <= 1)
        ft_exit("\n");
    if (argc == 2)
    {
        arr = ft_split(argv[1], ' ');
        while (arr[i])
            ft_addlast(&list, ft_new(arr[i++]));
        ft_freearr(arr);
    }
    else
        while (argv[i + 1])
            ft_addlast(&list, ft_new(argv[i++ + 1]));
    ft_pushswap(&list);
}