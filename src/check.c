#include "../inc/push_swap.h"

// non-numeric check
// check if any string in input
int ft_nonnum(char *str)
{
    int i;

    i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (str[i] == 0)
        return (-1);
    while (str[i])
    {
        if (ft_isdigit(str[i]) == 0)
            return (-1);
        i++;
    }
    return (i);
}

// number error check
// check if double sign or only sign no digit
// or exceed MAXINT
int ft_numerror(char *str, int n)
{
    int i;

    i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (str[i] == 0)
        return (-1);
    if (n == 0)
    {
        while (str[i])
        {
            if (str[i] != '0')
                return (-1);
            i++;
        }
    }
    else if (n == 1)
    {
        while (str[i] == '0')
            i++;
        if (str[i] != '1')
            return (-1);
    }
    return (i);
}