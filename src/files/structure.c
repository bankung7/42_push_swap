/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:29:36 by vnilprap          #+#    #+#             */
/*   Updated: 2022/07/13 11:32:15 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// create new instruction for checker
t_stk	*ft_newinst(char *str)
{
	t_stk	*node;

	node = malloc(sizeof(t_stk));
	if (!node)
		return (0);
	node->value = 0;
	node->inst = str;
	node->next = 0;
	return (node);
}

// create new seqlist node
t_stk	*ft_newseq(int n)
{
	t_stk	*node;

	node = malloc(sizeof(t_stk));
	if (!node)
		return (0);
	node->value = n;
	node->inst = 0;
	node->next = 0;
	return (node);
}

// create new node 
t_stk	*ft_new(char *str)
{
	int		n;
	t_stk	*node;

	if (ft_nonnum(str) == -1)
		return (0);
	node = malloc(sizeof(t_stk));
	if (!node)
		return (0);
	n = ft_atoi(str);
	if ((n == 0 && ft_numerror(str, 0) == -1)
		|| (n == -1 && ft_numerror(str, 1) == -1))
	{
		free(node);
		return (0);
	}
	node->value = n;
	node->inst = 0;
	node->next = 0;
	return (node);
}

void	ft_addlast(t_stk **list, t_stk *node, t_stk **seqlist, char **arr)
{
	t_stk	*head;

	head = *list;
	if (node == 0)
	{
		if (arr != 0)
			ft_freearr(arr);
		ft_exit(2, "Error\n", list, seqlist);
	}
	if (*list == 0)
		*list = node;
	else
	{
		while (head->next)
			head = head->next;
		head->next = node;
	}
}
