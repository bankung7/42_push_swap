/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:13:47 by vnilprap          #+#    #+#             */
/*   Updated: 2022/07/15 09:21:12 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_btoaswap(t_stk **stka, t_stk **stkb, t_stk **seqlist, int size)
{
	int	i;
	int	n;
	int	mid;
	int	a;

	i = 0;
	n = 0;
	a = 0;
	mid = ft_findmid(seqlist, ft_findlowest(stkb, size), (size / 2));
	if (size % 2 == 1)
		a = 1;
	while (i < (size / 2) + a)
	{
		if ((*stkb)->value >= mid)
			i += ft_push(stkb, stka, 'a', 1);
		else
			n += ft_rotate(stkb, 'b', 1);
	}
	while (size < ft_size(stkb) && n > 0)
		n -= ft_rrotate(stkb, 'b', 1);
	return (i);
}

void	ft_btoa(t_stk **stka, t_stk **stkb, t_stk **seqlist, int size)
{
	int	i;

	i = 0;
	if (size == 1)
		ft_push(stkb, stka, 'a', 1);
	else if (size == 2)
	{
		ft_push(stkb, stka, 'a', 1);
		ft_push(stkb, stka, 'a', 1);
		ft_small2(stka, 'a', 1);
	}
	else if (size >= 3 && size <= 13)
		ft_minisort(stka, stkb, size);
	else if (size > 2)
	{
		if (ft_issort(stkb, -1) == -1)
		{
			i = ft_btoaswap(stka, stkb, seqlist, size);
			ft_atob(stka, stkb, seqlist, i);
			ft_btoa(stka, stkb, seqlist, size - i);
		}
		else
			while (size > 0)
				size -= ft_push(stkb, stka, 'a', 1);
	}
}

int	ft_atobswap(t_stk **stka, t_stk **stkb, t_stk **seqlist, int size)
{
	int	i;
	int	n;
	int	mid;
	int	sizeb;

	i = 0;
	n = 0;
	mid = ft_findmid(seqlist, ft_findlowest(stka, size), (size / 2));
	sizeb = ft_size(stkb);
	while (i < (size / 2))
	{
		if ((*stka)->value < mid)
			i += ft_push(stka, stkb, 'b', 1);
		else
		{
			if (sizeb == 0 && ft_size(stkb) > 1 && (*stkb)->value
				< ft_findmid(seqlist, ft_findlowest(seqlist, size), (size / 4)))
				ft_drotate(stka, stkb, 1);
			else
				n += ft_rotate(stka, 'a', 1);
		}
	}
	while (size < ft_size(stka) && n > 0)
		n -= ft_rrotate(stka, 'a', 1);
	return (i);
}

void	ft_atob(t_stk **stka, t_stk **stkb, t_stk **seqlist, int size)
{
	int	i;

	i = 0;
	if (size == 2)
		ft_small2(stka, 'a', 1);
	else if (ft_size(stka) == 3)
		ft_small3(stka, 'a');
	else if (size > 2)
	{
		if (ft_issort(stka, 1) == -1)
		{
			i = ft_atobswap(stka, stkb, seqlist, size);
			ft_atob(stka, stkb, seqlist, size - i);
		}
		ft_btoa(stka, stkb, seqlist, i);
	}
}
