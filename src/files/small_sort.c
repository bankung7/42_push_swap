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

#include "../../inc/push_swap.h"

void	ft_small2(p_list **list, char t, int i)
{
	if (i == 1 && (*list)->value > (*list)->next->value)
		ft_swap(list, t, 1);
	else if (i == -1 && (*list)->value < (*list)->next->value)
		ft_swap(list, t, 1);
}

void	ft_small3(p_list **list, char t)
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

void	ft_small5(p_list **stka, p_list **stkb, p_list *seqlist)
{
	int		i;
	int		mid;
	p_list	*head;

	i = 2;
	mid = ft_findmid(&seqlist, ft_findlowest(stka, 5), 2);
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
