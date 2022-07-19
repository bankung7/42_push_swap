/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:09:40 by vnilprap          #+#    #+#             */
/*   Updated: 2022/07/13 11:10:10 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_push(t_stk **from, t_stk **to, char c, int p)
{
	t_stk	*head;

	if (ft_size(from) > 0)
	{
		head = *from;
		*from = (*from)->next;
		head->next = *to;
		*to = head;
		if (p == 1)
			ft_printf("p%c\n", c);
		return (1);
	}
	return (0);
}

int	ft_swap(t_stk **list, char c, int p)
{
	int		i;
	t_stk	*head;

	if (ft_size(list) > 1)
	{
		head = *list;
		i = head->value;
		head->value = head->next->value;
		head->next->value = i;
		if (p == 1)
			ft_printf("s%c\n", c);
		return (1);
	}
	return (0);
}

int	ft_rotate(t_stk **list, char c, int p)
{
	t_stk	*n;
	t_stk	*head;

	if (ft_size(list) > 1)
	{
		head = *list;
		n = *list;
		while (head->next)
			head = head->next;
		*list = (*list)->next;
		head->next = n;
		n->next = 0;
		if (p == 1)
			ft_printf("r%c\n", c);
		return (1);
	}
	return (0);
}

int	ft_rrotate(t_stk **list, char c, int p)
{
	t_stk	*head;
	t_stk	*n;

	if (ft_size(list) > 1)
	{
		head = *list;
		n = *list;
		while (head->next->next)
			head = head->next;
		*list = head->next;
		head->next = 0;
		(*list)->next = n;
		if (p == 1)
			ft_printf("rr%c\n", c);
		return (1);
	}
	return (0);
}
