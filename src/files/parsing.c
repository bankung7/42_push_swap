/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:27:37 by vnilprap          #+#    #+#             */
/*   Updated: 2022/07/13 11:27:39 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_parsing(t_stk **list, t_stk **seqlist, int argc, char **argv)
{
	int		i;
	char	**arr;

	i = 0;
	arr = 0;
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		while (arr[i])
			ft_addlast(list, ft_new(arr[i++]), seqlist, arr);
		ft_freearr(arr);
	}
	else
		while (argv[i + 1])
			ft_addlast(list, ft_new(argv[i++ + 1]), seqlist, arr);
	if (ft_size(list) > 1 && ft_seqlist(list, seqlist) == -1)
		ft_exit(2, "Error\n", seqlist, list);
}
