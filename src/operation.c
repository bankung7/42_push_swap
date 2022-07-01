#include "../inc/push_swap.h"

int ft_push(p_list **from, p_list **to, char c)
{
    p_list *head;

    if (ft_size(from) > 0)
    {
        head = *from;
        *from = (*from)->next;
        head->next = *to;
        *to = head;
        ft_printf("p%c\n", c);
        return (1);
    }
    return (0);
}

int ft_swap(p_list **list, char c)
{
    int i;
    p_list *head;

    if (ft_size(list) > 1)
    {
        head = *list;
        i = head->value;
        head->value = head->next->value;
        head->next->value = i;
        ft_printf("s%c\n", c);
        return (1);
    }
    return (0);
}

int ft_rotate(p_list **list, char c)
{
    p_list *n;
    p_list *head;

    if (ft_size(list) > 1)
    {
        head = *list;
        n = *list;
        while (head->next)
            head = head->next;
        *list = (*list)->next;
        head->next = n;
        n->next = 0;
        ft_printf("r%c\n", c);
        return (1);
    }
    return (0);
}

int ft_rrotate(p_list **list, char c)
{
    p_list *head;
    p_list *n;

    if (ft_size(list) > 1)
    {
        head = *list;
        n = *list;
        while (head->next->next)
            head = head->next;
        *list = head->next;
        head->next = 0;
        (*list)->next = n;
        ft_printf("rr%c\n", c);
        return (1);
    }
    return (0);
}