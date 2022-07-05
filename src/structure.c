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

// create new seq node
p_list *ft_newseq(int n)
{
    p_list *node;

    node = malloc(sizeof(p_list));
    if (!node)
        return (0);
    node->value = n;
    node->next = 0;
    return (node);
}

p_list *ft_new(char *str)
{
    int n;
    p_list *node;

    // Check non-numeric input
    if (ft_nonnum(str) == -1)
        return (0);
    node = malloc(sizeof(p_list));
    if (!node)
        return (0);
    n = ft_atoi(str);
    if ((n == 0 && ft_numerror(str, 0) == -1) || (n == -1 && ft_numerror(str, 1) == -1))
    {
        free(node);
        return (0);
    }
    node->value = n;
    node->seq = node->value;
    node->next = 0;
    return (node);
}

void ft_addlast(p_list **list, p_list *node)
{
    p_list *head;

    head = *list;
    if (node == 0)
        ft_exit("Error\n", list, 0);
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