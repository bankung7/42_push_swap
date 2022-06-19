#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft/libft.h"
#include "../libft/includes/ft_printf.h"

typedef struct  p_node
{
    int     value;
    struct  p_node  *next;
}   ps_node;

void    ft_exit(char *str);
t_list *ft_build(char **argv);
void    ft_readnode(t_list *list);
void    ft_freenode(t_list  *list);

# endif