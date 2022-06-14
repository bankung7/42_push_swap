#include <stdlib.h>
#include <unistd.h>
#include "../inc/push_swap.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/libft/libft.h"

int	ft_checknum(char *str)
{
	int 	i;
	
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkin(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (ft_atoi(arr[i]) == 0)
		{
			if (ft_checknum(arr[i]) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_insplit(char *str)
{
	char 	**arr;

	arr = ft_split(str, ' ');
	return (arr);
}

char	**ft_build(int n, char **argv)
{
	int		i;
	char	**arr;
	
	i = 1;
	arr = malloc(sizeof(char*) * n);
	while (i < n)
	{
		arr[i - 1] = ft_strdup(argv[i]);
		i++;
	}
	arr[i - 1] = "\0";
	return (arr);
}
