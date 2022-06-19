#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
    int i;
    ps_list *list;

    i = 1;
    list = 0;
    if (argc == 1)
        ft_exit("Not any number input");
    list = ft_build(argv, 1);
    ft_readlist(list);
    ft_freelist(list);
    return (0);
}