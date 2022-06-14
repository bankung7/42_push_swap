#include <stdlib.h>
#include <unistd.h>
#include "../inc/push_swap.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/libft/libft.h"

void	ft_printarr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		ft_printf("%s ", arr[i++]);
}

int	main(int argc, char **argv)
{
	char 	**arr;

	if (argc == 1)
		ft_exit("No input");
	if (argc == 2)
		arr = ft_insplit(argv[1]);
	if (argc > 2)
		arr = ft_build(argc, argv);
	if (ft_checkin(arr) == 1)
		ft_printf("Yes, all things good");
	else
		ft_printf("No, Something wrong in some input");
	free(arr);
}
