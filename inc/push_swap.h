#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft/libft.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/get_next_line.h"

typedef struct ps_list
{
    int value;
    char *inst;
    struct ps_list *next;
} p_list;

// parsing.c
void ft_parsing(p_list **list, p_list **seqlist, int argc, char **argv);

// exit.c
void ft_freelist(p_list **list);
void ft_freearr(char **arr);
void ft_exit(int fd, char *str, p_list **list, p_list **list2);

// structure.c
void ft_addlast(p_list **list, p_list *node, p_list **seqlist, char **arr);
p_list *ft_new(char *str);
p_list *ft_newseq(int n);
p_list *ft_newinst(char *str);

// small_sort.c
void ft_small2(p_list **list, char t, int i);
void ft_small3(p_list **list, char t);
void ft_small5(p_list **stka, p_list **stkb, p_list *seqlist);

// merge_sort.c
void ft_atob(p_list **stka, p_list **stkb, p_list **seqlist, int size);
void ft_btoa(p_list **stka, p_list **stkb, p_list **seqlist, int size);

// util.c
int ft_size(p_list **list);
void ft_read(p_list **list, char *str, char t);
int ft_nonnum(char *str);
int ft_numerror(char *str, int n);

// sort.c
int ft_issort(p_list **list, int i);
int ft_csort(p_list **list);
int ft_seqlist(p_list **list, p_list **seqlist);
int ft_findmid(p_list **seqlist, int start, int p);
int ft_findlowest(p_list **list, int size);

// operations.c
int ft_push(p_list **from, p_list **to, char c, int p);
int ft_swap(p_list **stka, char c, int p);
int ft_rotate(p_list **list, char c, int p);
int ft_rrotate(p_list **list, char c, int p);

// operations2.c
int ft_dswap(p_list **stka, p_list **stkb, int p);
int ft_drotate(p_list **stka, p_list **stkb, int p);
int ft_drrotate(p_list **stka, p_list **stkb, int p);
#endif