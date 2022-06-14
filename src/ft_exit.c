#include <stdlib.h>
#include <unistd.h>
#include "../libft/includes/ft_printf.h"
#include "../libft/libft/libft.h"

void	ft_exit(char *str)
{
	ft_printf("%s", str);
	write(1, "\n", 1);
	exit(0);
}
