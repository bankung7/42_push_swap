/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:24:18 by vnilprap          #+#    #+#             */
/*   Updated: 2022/07/13 12:05:44 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_runinst2(p_list **stka, p_list **stkb, char *inst)
{
	if (ft_strncmp("ss", inst, 2) == 0)
		ft_dswap(stka, stkb, 0);
	else if (ft_strncmp("sa", inst, 2) == 0)
		ft_swap(stka, 'a', 0);
	else if (ft_strncmp("sb", inst, 2) == 0)
		ft_swap(stkb, 'b', 0);
	else if (ft_strncmp("pa", inst, 2) == 0)
		ft_push(stkb, stka, 'a', 0);
	else if (ft_strncmp("pb", inst, 2) == 0)
		ft_push(stka, stkb, 'b', 0);
	else if (ft_strncmp("rr", inst, 2) == 0)
		ft_drotate(stka, stkb, 0);
	else if (ft_strncmp("ra", inst, 2) == 0)
		ft_rotate(stka, 'a', 0);
	else if (ft_strncmp("rb", inst, 2) == 0)
		ft_rotate(stkb, 'b', 0);
}

void	ft_runinst(p_list **stka, p_list **stkb, p_list **seqlist)
{
	p_list	*head;

	while (*seqlist)
	{
		head = *seqlist;
		*seqlist = (*seqlist)->next;
		if (ft_strlen(head->inst) == 2)
			ft_runinst2(stka, stkb, head->inst);
		else if (ft_strncmp("rrr", head->inst, 3) == 0)
			ft_drrotate(stka, stkb, 0);
		else if (ft_strncmp("rra", head->inst, 3) == 0)
			ft_rrotate(stka, 'a', 0);
		else if (ft_strncmp("rrb", head->inst, 3) == 0)
			ft_rrotate(stkb, 'b', 0);
		free(head->inst);
		free(head);
	}
	if (ft_size(stkb) > 0 || ft_issort(stka, 1) == -1)
		ft_exit(1, "KO\n", stka, stkb);
	else
		ft_exit(1, "OK\n", stka, stkb);
}

void	ft_checkinst(p_list **list, p_list **seqlist, char *bf)
{
	int	n;

	n = ft_strlen(bf);
	if (n > 4 || ft_strchr(bf, '\n') == 0)
	{
		free(bf);
		ft_exit(2, "Error\n", list, seqlist);
	}
	if (n == 3 && bf[0] == 's'
		&& (bf[1] == 'a' || bf[1] == 'b' || bf[1] == 's'))
		ft_addlast(seqlist, ft_newinst(ft_substr(bf, 0, 2)), list, 0);
	else if (n == 3
		&& bf[0] == 'r' && (bf[1] == 'a' || bf[1] == 'b' || bf[1] == 'r'))
		ft_addlast(seqlist, ft_newinst(ft_substr(bf, 0, 2)), list, 0);
	else if (n == 3 && bf[0] == 'p' && (bf[1] == 'a' || bf[1] == 'b'))
		ft_addlast(seqlist, ft_newinst(ft_substr(bf, 0, 2)), list, 0);
	else if (n == 4 && bf[0] == 'r' && bf[1] == 'r'
		&& (bf[2] == 'a' || bf[2] == 'b' || bf[2] == 'r'))
		ft_addlast(seqlist, ft_newinst(ft_substr(bf, 0, 3)), list, 0);
	else
	{
		free(bf);
		ft_exit(2, "Error\n", list, seqlist);
	}
}

void	ft_checker(p_list **list, p_list **seqlist)
{
	char	*s;
	p_list	*stkb;

	stkb = 0;
    if (ft_issort(list, 1) == 0)
        ft_exit(1, "OK\n", list, seqlist);
	s = get_next_line(0);
	while (s != 0)
	{
		ft_checkinst(list, seqlist, s);
		free(s);
		s = get_next_line(0);
		if (s == 0)
			ft_runinst(list, &stkb, seqlist);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	**arr;
	p_list	*list;
	p_list	*seqlist;

	i = 0;
	arr = 0;
	list = 0;
	seqlist = 0;
	if (argc == 1 || argv[1] == 0)
		ft_exit(1, "", 0, 0);
	ft_parsing(&list, &seqlist, argc, argv);
	ft_freelist(&seqlist);
	seqlist = 0;
	ft_checker(&list, &seqlist);
	ft_freelist(&list);
}
