/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:39:36 by vnilprap          #+#    #+#             */
/*   Updated: 2022/07/13 10:39:38 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_pushswap(t_stk **list, t_stk **seqlist)
{
	int		size;
	t_stk	*stka;
	t_stk	*stkb;

	stka = *list;
	stkb = 0;
	size = ft_size(list);
	if (size <= 1 || ft_issort(list, 1) == 0)
		ft_exit(1, "", list, seqlist);
	else if (size == 2)
		ft_small2(&stka, 'a', 1);
	else if (size == 3)
		ft_small3(&stka, 'a');
	else if (size == 5)
		ft_small5(&stka, &stkb, seqlist);
	else if (ft_issort(&stka, 1) == -1)
		ft_atob(&stka, &stkb, seqlist, size);
	*list = stka;
}

int	main(int argc, char **argv)
{
	t_stk	*list;
	t_stk	*seqlist;

	list = 0;
	seqlist = 0;
	if (argc == 1 || argv[1] == 0)
		ft_exit(1, "", 0, 0);
	ft_parsing(&list, &seqlist, argc, argv);
	ft_pushswap(&list, &seqlist);
	ft_freelist(&list);
	ft_freelist(&seqlist);
	exit(0);
}
