#include "../inc/push_swap.h"

void	ft_swap(ps_list **list, char c)
{
	ps_list	*n;

	n = (*list)->next;
	(*list)->next = n->next;
	n->next = (*list);
	(*list) = n;
	ft_printf("s%c", c);
	write(1, "\n", 1);	
}

void	ft_rotate(ps_list **list, char c)
{
	ps_list	*n;
	ps_list	*head;

	n = *list;
	head = (*list)->next;
	while ((*list)->next)
		(*list) = (*list)->next;
	n->next = 0;
	(*list)->next = n;
	(*list) = head;
	ft_printf("r%c", c);
	write(1, "\n", 1);	
}

void	ft_rrotate(ps_list **list, char c)
{
	ps_list	*n;
	ps_list *head;

	n = *list;
	while (n->next->next)
		n = n->next;
	head = n->next;
	head->next = *list;
	n->next = 0;
	(*list) = head;
	ft_printf("rr%c", c);
	write(1, "\n", 1);	
}

void	ft_push(ps_list **from, ps_list **to)
{
	ps_list	*n;

	n = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = n;
	ft_printf("pb");
	write(1, "\n", 1);	
}
