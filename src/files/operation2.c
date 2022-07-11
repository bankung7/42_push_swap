#include "../../inc/push_swap.h"

int ft_dswap(p_list **stka, p_list **stkb)
{
    if (ft_size(stka) > 1 && ft_size(stkb) > 1)
    {
        ft_swap(stka, 'a', 0);
        ft_swap(stkb, 'b', 0);
        ft_printf("ss\n");
        return (1);
    }
    return (0);
}

int ft_drotate(p_list **stka, p_list **stkb)
{
    if (ft_size(stka) > 1 && ft_size(stkb) > 1)
    {
        ft_rotate(stka, 'a', 0);
        ft_rotate(stkb, 'b', 0);
        ft_printf("rr\n");
        return (1);
    }
    return (0);
}

int ft_drrotate(p_list **stka, p_list **stkb)
{
    if (ft_size(stka) > 1 && ft_size(stkb) > 1)
    {
        ft_rrotate(stka, 'a', 0);
        ft_rrotate(stkb, 'b', 0);
        ft_printf("rrr\n");
        return (1);
    }
    return (0);
}