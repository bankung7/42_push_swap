#include "../inc/push_swap.h"

void ft_sort(ps_list **list)
{
	int	i;
    int n;
	ps_list *head;

	head = *list;
    n = 0;
	while (head->next)
	{
		if (head->value > head->next->value)
		{
			i = head->value;
			head->value = head->next->value;
			head->next->value = i;	
			head = *list;
            n++;
		}
		else if (head->value == head->next->value)
			ft_exit("there is duplicated number", *list, 0);
		else
			head = head->next;
	}
    if (n == 0)
        ft_exit("This is sorted number", *list, 0);
}
