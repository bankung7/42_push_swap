#include "../inc/push_swap.h"

void ft_sort(ps_list **list)
{
	int i;
	int n;
	ps_list *head;

	head = *list;
	n = 0;
	while (head->next)
	{
		if (head->seq > head->next->seq)
		{
			i = head->seq;
			head->seq = head->next->seq;
			head->next->seq = i;
			head = *list;
			n++;
		}
		else if (head->seq== head->next->seq)
			ft_exit("there is duplicated number", *list, 0);
		else
			head = head->next;
	}
	if (n == 0)
		ft_exit("This is sorted number", *list, 0);
}

void ft_rsort(ps_list **list)
{
	int i;
	ps_list *head;

	head = *list;
	while (head->next)
	{
		if (head->seq > head->next->seq)
		{
			i = head->value;
			head->value = head->next->value;
			head->next->value = i;
			i = head->seq;
			head->seq = head->next->seq;
			head->next->seq = i;
			head = *list;
		}
		else
			head = head->next;
	}
}
