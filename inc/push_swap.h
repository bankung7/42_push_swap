#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft/libft.h"
#include "../libft/includes/ft_printf.h"

typedef struct ps_list
{
    int value;
    int seq;
    struct ps_list *next;
} p_list;

// main.c
void ft_atob(p_list **stka, p_list **stkb, int size);

// parsing.c
void ft_parsing(p_list **list, p_list **seqlist, int argc, char **argv);

// exit.c
void ft_freelist(p_list **list);
void ft_freearr(char **arr);
void ft_exit(char *str, p_list **list, char **arr);

// structure.c
int ft_size(p_list **list);
void ft_addlast(p_list **list, p_list *node);
void ft_addfront(p_list **list, p_list *node);
p_list *ft_new(char *str);
p_list *ft_newseq(int n);

// util.c
void ft_read(p_list **list, char *str, char c);
void ft_setseq(p_list **list, int n);
int ft_getmid(p_list **list, int i);

// sort.c
int ft_issort(p_list **list, int type);
int ft_csort(p_list **list);
int ft_seqlist(p_list **list, p_list **seqlist);
int ft_findmid(p_list **seqlist, int p);

// operations.c
int ft_push(p_list **from, p_list **to, char c);
int ft_swap(p_list **list, char c);
int ft_rotate(p_list **list, char c);
int ft_rrotate(p_list **list, char c);

// check.c
int ft_nonnum(char *str);
int ft_numerror(char *str, int n);

#endif
