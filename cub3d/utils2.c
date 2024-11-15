#include "cub3d.h"

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int print_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (2);
}

void	print_2d_array(char **argv)
{
	int	i;

	i = 0;
	while(argv[i])
	{
		printf("%s", argv[i]);
		i++;
	}
	printf("\n");
}

int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return(i);
}

void	ft_exit()
{
	exit(1);
}
