#include "cub3d.h"

int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}