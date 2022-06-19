#include "../inc/push_swap.h"

int     main(int argc, char **argv)
{
    int     i;
    t_list  *list;

    i = 1;
    list = 0;
    if (argc == 1)
        ft_exit("Not any number input");
    else
    {
        list = ft_build(argv);
        ft_readnode(list);
        ft_freenode(list);
    }
    return (0);
}