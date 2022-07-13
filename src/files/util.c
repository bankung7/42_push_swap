/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:25:12 by vnilprap          #+#    #+#             */
/*   Updated: 2022/07/13 11:27:20 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_read(t_stk **list, char *str, char t)
{
	t_stk	*head;

	head = *list;
	ft_printf("%s => ", str);
	while (head)
	{
		if (t == 'i')
			ft_printf("%s -> ", head->inst);
		else
			ft_printf("%d -> ", head->value);
		head = head->next;
	}
	ft_printf("\n");
}

int	ft_size(t_stk **list)
{
	int		i;
	t_stk	*head;

	i = 0;
	head = *list;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

// non-numeric check
// check if any string in input
int	ft_nonnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == 0)
		return (-1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (i);
}

// number error check
// check if double sign or only sign no digit
// or exceed MAXINT
int	ft_numerror(char *str, int n)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == 0)
		return (-1);
	if (n == 0)
	{
		while (str[i])
		{
			if (str[i] != '0')
				return (-1);
			i++;
		}
	}
	else if (n == 1)
	{
		while (str[i] == '0')
			i++;
		if (str[i] != '1')
			return (-1);
	}
	return (i);
}
