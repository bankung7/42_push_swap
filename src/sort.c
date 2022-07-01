#include "../inc/push_swap.h"

int ft_issort(p_list **list, int n)
{
    int s;
    int i;
    p_list *head;

    s = 0;
    head = *list;
    while (head->next)
    {
        if ((n >= 0 && head->seq > head->next->seq) || (n < 0 && head->seq < head->next->seq))
        {
            i = head->seq;
            head->seq = head->next->seq;
            head->next->seq = i;
            head = *list;
            s++;
        }
        else
            head = head->next;
    }
    return (s);
}