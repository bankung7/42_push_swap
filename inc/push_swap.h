#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

void	ft_free(char **arr);
void	ft_exit(char *str);
char	**ft_insplit(char *str);
char	**ft_build(int n, char **argv);
void	ft_printarr(char **arr);
int	ft_checkin(char **arr);
int	ft_checknum(char *str);

# endif
