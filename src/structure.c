#include "../inc/push_swap.h"

int ft_size(p_list **list)
{
    int i;
    p_list *head;

    i = 0;
    head = *list;
    while (head)
    {
        head = head->next;
        i++;
    }
    return (i);
}

p_list *ft_new(char *str)
{
    p_list *node;

    node = malloc(sizeof(p_list));
    if (!node)
        return (0);
    node->value = ft_atoi(str);
    node->seq = node->value;
    node->next = 0;
    return (node);
}

void ft_addlast(p_list **list, p_list *node)
{
    p_list *head;

    head = *list;
    if (*list == 0)
        *list = node;
    else
    {
        while (head->next)
            head = head->next;
        head->next = node;
    }
}

void ft_addfront(p_list **list, p_list *node)
{
    if (*list == 0)
        *list = node;
    else
    {
        node->next = *list;
        *list = node;
    }
}