#include <stdlib.h>
#include <unistd.h>
#include "../libft/includes/ft_printf.h"
#include "../libft/libft/libft.h"

void	ft_free(char **arr)
{
	int	i;
	
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
