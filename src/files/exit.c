/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:42:07 by vnilprap          #+#    #+#             */
/*   Updated: 2022/07/13 10:45:32 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_freelist(p_list **list)
{
	int		i;
	p_list	*head;

	i = 0;
	head = *list;
	if (*list)
	{
		while (*list)
		{
			head = *list;
			*list = (*list)->next;
			if (head->inst != 0)
				free(head->inst);
			free(head);
			i++;
		}
	}
}

void	ft_freearr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_exit(int fd, char *str, p_list **list, p_list **list2)
{
	if (list != 0)
		ft_freelist(list);
	if (list2 != 0)
		ft_freelist(list2);
	ft_putstr_fd(str, fd);
	exit(0);
}
