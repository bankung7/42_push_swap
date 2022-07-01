#include "../inc/push_swap.h"

void ft_read(p_list **list, char *str, char c)
{
    p_list *head;

    head = *list;
    ft_printf("%s => ", str);
    while (head)
    {
        if (c == 'v')
            ft_printf("%d -> ", head->value);
        else
            ft_printf("%d -> ", head->seq);
        head = head->next;
    }
    printf("\n");
}

void ft_setseq(p_list **list, int n)
{
    p_list *head;

    head = *list;
    if (head != 0)
    {
        while (head && n > 0)
        {
            head->seq = head->value;
            head = head->next;
            n--;
        }
    }
}

int ft_getmid(p_list **list, int i)
{
    p_list *head;

    head = *list;
    if (list == 0)
        return (0);
    while (i > 0)
    {
        head = head->next;
        i--;
    }
    return (head->seq);
}