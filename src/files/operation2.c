/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:10:14 by vnilprap          #+#    #+#             */
/*   Updated: 2022/07/13 11:10:16 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_dswap(t_stk **stka, t_stk **stkb, int p)
{
	if (ft_size(stka) > 1 && ft_size(stkb) > 1)
	{
		ft_swap(stka, 'a', 0);
		ft_swap(stkb, 'b', 0);
		if (p == 1)
			ft_printf("ss\n");
		return (1);
	}
	return (0);
}

int	ft_drotate(t_stk **stka, t_stk **stkb, int p)
{
	if (ft_size(stka) > 1 && ft_size(stkb) > 1)
	{
		ft_rotate(stka, 'a', 0);
		ft_rotate(stkb, 'b', 0);
		if (p == 1)
			ft_printf("rr\n");
		return (1);
	}
	return (0);
}

int	ft_drrotate(t_stk **stka, t_stk **stkb, int p)
{
	if (ft_size(stka) > 1 && ft_size(stkb) > 1)
	{
		ft_rrotate(stka, 'a', 0);
		ft_rrotate(stkb, 'b', 0);
		if (p == 1)
			ft_printf("rrr\n");
		return (1);
	}
	return (0);
}
