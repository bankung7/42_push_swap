#include "../inc/push_swap.h"

void ft_pushswap(p_list **list, p_list **seqlist)
{
    int size;
    p_list *stka;
    p_list *stkb;

    stka = *list;
    stkb = 0;
    size = ft_size(list);
    if (size <= 1)
        ft_exit(1, "", list, 0);
    else if (size == 2)
        ft_small2(&stka, 'a', 1);
    else if (size == 3)
        ft_small3(&stka, 'a');
    else if (size == 5)
        ft_small5(&stka, &stkb, *seqlist);
    else if (ft_issort(&stka, 1) == -1)
        ft_atob(&stka, &stkb, seqlist, size);
    *list = stka;
}

int main(int argc, char **argv)
{
    int i;
    char **arr;
    p_list *list;
    p_list *seqlist;

    i = 0;
    arr = 0;
    list = 0;
<<<<<<< HEAD
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

	ft_printf("n = %d", ft_lstsize(&list));
    write(1, "\n", 1);

    ft_printf("=== before sorting ===");
    write(1, "\n", 1);
    ft_blogic(&list);
    ft_readlist(list);

    ft_freelist(list);
    return (0);
}
=======
    seqlist = 0;
    // No parameter passing in -> Display nothing
    if (argc == 1 || argv[1] == 0)
        ft_exit(1, "", 0, 0);
    ft_parsing(&list, &seqlist, argc, argv);
    ft_pushswap(&list, &seqlist);
    ft_freelist(&list);
    ft_freelist(&seqlist);
    exit(0);
}
>>>>>>> 3b5b754e20d20868df6687d1de7e501f7364fcb0
