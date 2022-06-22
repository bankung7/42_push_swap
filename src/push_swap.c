#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
    int i;
    char **arr;
    ps_list *list;

    i = 1;
    list = 0;
    if (argc == 1)
        ft_exit("=== Not any number input ===", 0, 0);
    if (argc == 2)
    {
        arr = ft_split(argv[1], ' ');
        ft_printf("=== spliting arr ===");
        write(1, "\n", 1);
        list = ft_build(arr, 0);
        ft_freearr(arr);
    }
    else
        list = ft_build(argv, 1);
    ft_printf("=== before sorting ===");
    write(1, "\n", 1);
    ft_readlist(list);

    ft_printf("=== after sorting ===");
    write(1, "\n", 1);
    ft_sort(&list);
    ft_readlist(list);

    ft_printf("=== qualtile at 50 is %d", ft_findq(&list, 50));
    write(1, "\n", 1);

    ft_pushswap(&list);
    ft_readlist(list);

    ft_freelist(list);
    return (0);
}
