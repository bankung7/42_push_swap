/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:27:44 by vnilprap          #+#    #+#             */
/*   Updated: 2022/07/13 11:29:18 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_small2(t_stk **list, char t, int i)
{
	if (i == 1 && (*list)->value > (*list)->next->value)
		ft_swap(list, t, 1);
	else if (i == -1 && (*list)->value < (*list)->next->value)
		ft_swap(list, t, 1);
}

void	ft_small3(t_stk **list, char t)
{
	int	a;
	int	b;
	int	c;

	a = (*list)->value;
	b = (*list)->next->value;
	c = (*list)->next->next->value;
	if (a > b || b > c || a > c)
	{
		if (a > b && a > c)
			ft_rotate(list, t, 1);
		else if (a < b && b > c)
			ft_rrotate(list, t, 1);
		else if (a > b && b < c && a < c)
			ft_swap(list, t, 1);
		ft_small3(list, t);
	}
}

void	ft_small5(t_stk **stka, t_stk **stkb, t_stk **seqlist)
{
	int		i;
	int		mid;
	t_stk	*head;

	i = 2;
	mid = ft_findmid(seqlist, ft_findlowest(stka, 5), 2);
	head = *stka;
	while (i > 0)
	{
		if (head->value < mid)
			i -= ft_push(stka, stkb, 'b', 1);
		else
			ft_rotate(stka, 'a', 1);
		head = *stka;
	}
	ft_small3(stka, 'a');
	ft_small2(stkb, 'b', -1);
	ft_push(stkb, stka, 'a', 1);
	ft_push(stkb, stka, 'a', 1);
}

void	ft_minisort(t_stk **stka, t_stk **stkb, int size)
{
	int	low;
	int	rot;

	rot = 0;
	low = (*stka)->value;
	while (size > 0)
	{
		if ((*stkb)->value < low)
		{
			while (rot > 0)
				rot -= ft_rrotate(stka, 'a', 1);
			low = (*stkb)->value;
		}
		else if ((*stka)->value > (*stkb)->value)
			while (rot > 0 && ft_findlast(stka) > (*stkb)->value)
				rot -= ft_rrotate(stka, 'a', 1);
		else if ((*stka)->value < (*stkb)->value)
			while ((*stka)->value < (*stkb)->value)
				rot += ft_rotate(stka, 'a', 1);
		size -= ft_push(stkb, stka, 'a', 1);
	}
	while (rot > 0)
			rot -= ft_rrotate(stka, 'a', 1);
}
