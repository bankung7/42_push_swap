#include "../inc/push_swap.h"

int ft_arrsize(char *arr)
{
    int i;

    i = 0;
    if (!arr)
        return (0);
    while (arr[i])
        i++;
    return (i);
}

void ft_parsing(p_list **list, p_list **seqlist, int argc, char **argv)
{
    int i;
    char **arr;

    i = 0;
    arr = 0;
    if (argc == 2)
    {
        arr = ft_split(argv[1], ' ');
        while (arr[i])
            ft_addlast(list, ft_new(arr[i++]));
        ft_freearr(arr);
    }
    else
        while (argv[i + 1])
            ft_addlast(list, ft_new(argv[i++ + 1]));
    // check if dupicated
    if (ft_size(list) > 1 && ft_seqlist(list, seqlist) == -1)
    {
        ft_freelist(list);
        ft_exit("Error\n", seqlist, 0);
    }
}