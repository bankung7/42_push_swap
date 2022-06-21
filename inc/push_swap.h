#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft/libft.h"
#include "../libft/includes/ft_printf.h"

typedef struct  p_list
{
    int     value;
    struct  p_list  *next;
}   ps_list;

ps_list     *ft_build(char **arr, int i);
void    ft_exit(char *str, ps_list *list, char **arr);
void    ft_readlist(ps_list *list);
void    ft_freelist(ps_list *list);
void    ft_freearr(char **arr);
int     ft_checkinput(char *str);
void    ft_sort(ps_list **list);
void	ft_swap(ps_list **list, char c);
void	ft_rotate(ps_list **list, char c);
void	ft_rrotate(ps_list **list, char c);
void    ft_blogic(ps_list **list);


# endif
