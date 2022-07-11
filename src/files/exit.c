#include "../../inc/push_swap.h"

void ft_print_fd(char *str, int fd)
{
    int i;

    i = 0;
    while (str[i])
        write(fd, &str[i++], 1);
}

void ft_freelist(p_list **list)
{
    int i;
    p_list *head;

    i = 0;
    head = *list;
    if (*list)
    {
        while (*list)
        {
            head = *list;
            *list = (*list)->next;
            free(head);
            i++;
        }
    }
    // printf("done free %d node\n", i);
}

void ft_freearr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}

void ft_exit(int fd, char *str, p_list **list, char **arr)
{
    if (list != 0)
        ft_freelist(list);
    if (arr != 0)
        ft_freearr(arr);
    ft_print_fd(str, fd);
    exit(0);
}