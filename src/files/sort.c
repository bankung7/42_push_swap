#include "../../inc/push_swap.h"

int ft_issort(p_list **list, int i)
{
    p_list *head;

    head = *list;
    while (head->next)
    {
        if ((i == 1 && head->value > head->next->value) ||
            (i == -1 && head->value < head->next->value))
            return (-1);
        head = head->next;
    }
    return (0);
}

int ft_csort(p_list **list)
{
    int i;
    p_list *head;

    i = 0;
    head = *list;
    while (head->next)
    {
        if (head->value > head->next->value)
        {
            i = head->value;
            head->value = head->next->value;
            head->next->value = i;
            head = *list;
        }
        else if (head->value == head->next->value)
            return (-1);
        else
            head = head->next;
    }
    return (0);
}

// function which build a sorted list and use for finding mid
int ft_seqlist(p_list **list, p_list **seqlist)
{
    p_list *head;

    head = *list;
    while (head)
    {
        ft_addlast(seqlist, ft_newseq(head->value), seqlist, 0);
        head = head->next;
    }
    if (ft_csort(seqlist) == -1)
        return (-1);
    return (0);
}

int ft_findmid(p_list **seqlist, int start, int p)
{
    p_list *head;

    head = *seqlist;
    if (head == 0)
        return (-1);
    while (head->next && head->value != start)
        head = head->next;
    while (head->next && p > 0)
    {
        head = head->next;
        p--;
    }
    return (head->value);
}

int ft_findlowest(p_list **list, int size)
{
    int i;
    p_list *head;

    i = -1;
    head = *list;
    while (size > 0)
    {
        if (i == -1)
            i = head->value;
        else if (i > head->value)
            i = head->value;
        head = head->next;
        size--;
    }
    return (i);
}