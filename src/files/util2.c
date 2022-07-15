/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:14:42 by vnilprap          #+#    #+#             */
/*   Updated: 2022/07/15 09:15:31 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_findlast(t_stk **list)
{
	t_stk	*head;

	head = *list;
	while (head->next)
		head = head->next;
	return (head->value);
}

int	ft_findmid(t_stk **seqlist, int start, int p)
{
	t_stk	*head;

	head = *seqlist;
	if (head == 0)
		return (-1);
	while (head->next && head->value != start)
		head = head->next;
	while (head->next && p > 0)
	{
		head = head->next;
		p--;
	}
	return (head->value);
}

int	ft_findlowest(t_stk **list, int size)
{
	int		i;
	t_stk	*head;

	head = *list;
	i = head->value;
	while (size > 0)
	{
		if (i > head->value)
			i = head->value;
		head = head->next;
		size--;
	}
	return (i);
}
