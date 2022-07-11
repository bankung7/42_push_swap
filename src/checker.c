#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
    int i;
    char **arr;
    p_list *list;
    p_list *seqlist;

    i = 0;
    arr = 0;
    list = 0;
    seqlist = 0;
    // No parameter passing in -> Display nothing
    if (argc == 1 || argv[1] == 0)
        ft_exit("", 0, 0);
    ft_parsing(&list, argc, argv);
    ft_freelist(&list);
}