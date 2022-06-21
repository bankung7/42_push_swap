#include "../inc/push_swap.h"

void ft_sort(ps_list **list)
{
	int	i;
	ps_list *head;

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
		{
			ft_freelist(*list);
			ft_exit("there is duplicated number");
		}
		else
			head = head->next;
	}
}
