/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:16:11 by vnilprap          #+#    #+#             */
/*   Updated: 2022/07/13 11:19:10 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_issort(t_stk **list, int i)
{
	t_stk	*head;

	head = *list;
	while (head->next)
	{
		if ((i == 1 && head->value > head->next->value)
			|| (i == -1 && head->value < head->next->value))
			return (-1);
		head = head->next;
	}
	return (0);
}

int	ft_csort(t_stk **list)
{
	int		i;
	t_stk	*head;

	i = 0;
	head = *list;
	while (head->next)
	{
		if (head->value > head->next->value)
		{
			i = head->value;
			head->value = head->next->value;
			head->next->value = i;
			head = *list;
		}
		else if (head->value == head->next->value)
			return (-1);
		else
			head = head->next;
	}
	return (0);
}

int	ft_seqlist(t_stk **list, t_stk **seqlist)
{
	t_stk	*head;

	head = *list;
	while (head)
	{
		ft_addlast(seqlist, ft_newseq(head->value), seqlist, 0);
		head = head->next;
	}
	if (ft_csort(seqlist) == -1)
		return (-1);
	return (0);
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

	i = -1;
	head = *list;
	while (size > 0)
	{
		if (i == -1)
			i = head->value;
		else if (i > head->value)
			i = head->value;
		head = head->next;
		size--;
	}
	return (i);
}
