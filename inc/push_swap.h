/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:15:50 by vnilprap          #+#    #+#             */
/*   Updated: 2022/07/15 09:02:35 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

typedef struct s_stack
{
	int				value;
	char			*inst;
	struct s_stack	*next;
}			t_stk;

// parsing.c
void	ft_parsing(t_stk **list, t_stk **seqlist, int argc, char **argv);

// exit.c
void	ft_freelist(t_stk **list);
void	ft_freearr(char **arr);
void	ft_exit(int fd, char *str, t_stk **list, t_stk **list2);

// structure.c
void	ft_addlast(t_stk **list, t_stk *node, t_stk **seqlist, char **arr);
t_stk	*ft_new(char *str);
t_stk	*ft_newseq(int n);
t_stk	*ft_newinst(char *str);

// small_sort.c
void	ft_small2(t_stk **list, char t, int i);
void	ft_small3(t_stk **list, char t);
void	ft_small5(t_stk **stka, t_stk **stkb, t_stk *seqlist);
void	ft_minisort(t_stk **stka, t_stk **stkb, int size);

// merge_sort.c
void	ft_atob(t_stk **stka, t_stk **stkb, t_stk **seqlist, int size);
void	ft_btoa(t_stk **stka, t_stk **stkb, t_stk **seqlist, int size);

// util.c
int		ft_size(t_stk **list);
int		ft_nonnum(char *str);
int		ft_numerror(char *str, int n);
void	ft_read(t_stk **list, char *str, char t);

// util2.c
int		ft_findlast(t_stk **list);
int		ft_findmid(t_stk **seqlist, int start, int p);
int		ft_findlowest(t_stk **list, int size);

// sort.c
int		ft_issort(t_stk **list, int i);
int		ft_csort(t_stk **list);
int		ft_seqlist(t_stk **list, t_stk **seqlist);

// operations.c
int		ft_push(t_stk **from, t_stk **to, char c, int p);
int		ft_swap(t_stk **stka, char c, int p);
int		ft_rotate(t_stk **list, char c, int p);
int		ft_rrotate(t_stk **list, char c, int p);

// operations2.c
int		ft_dswap(t_stk **stka, t_stk **stkb, int p);
int		ft_drotate(t_stk **stka, t_stk **stkb, int p);
int		ft_drrotate(t_stk **stka, t_stk **stkb, int p);
#endif
