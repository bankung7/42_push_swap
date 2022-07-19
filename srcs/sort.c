/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:16:11 by vnilprap          #+#    #+#             */
/*   Updated: 2022/07/15 09:15:45 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
