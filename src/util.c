#include "../inc/push_swap.h"

int     ft_checkinput(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if(ft_isdigit(str[i]) == 1)
            i++;
        else
            return (0);
    }
    return (1);
}