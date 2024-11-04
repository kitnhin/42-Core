#include "cub3d.h"

void	print_textures(t_game *game)
{
	if(game->textures.north_texture && game->textures.south_texture && game->textures.east_texture && game->textures.west_texture)
	{
		printf("NORTH TEXTURE = %s\n", game->textures.north_texture);
		printf("SOUTH TEXTURE = %s\n", game->textures.south_texture);
		printf("WEST  TEXTURE = %s\n", game->textures.west_texture);
		printf("EAST  TEXTURE = %s\n", game->textures.east_texture);
		printf("FLOOR   = %d, %d, %d\n", game->textures.floorcolor[0], game->textures.floorcolor[1], game->textures.floorcolor[1]);
		printf("CEILING = %d, %d, %d\n", game->textures.ceilingcolor[0], game->textures.ceilingcolor[1], game->textures.ceilingcolor[2]);
	}
	else
	{
		// printf("smth wrong wif textures\n");
		return ;
	}
	if(game->map)
	{
		printf("========MAP=========\n");
		print_2d_array(game->map);
	}
	else
		// printf("smth wrong wif map\n");
	return ;
}

int	get_map_height_for_malloc(t_game *game, int i)
{
	int j;

	j = i;
	while (game->filedata[j])
		j++;
	return(j - i);
}

char	**readfile(int fd)
{
	char	**res;
	int		j;

	j = 0;
	res = (char **)malloc(sizeof(char *) * 10000);
	if (!res)
		return (NULL);
	res[0] = get_next_line(fd);
	while (res[j++] != NULL)
		res[j] = get_next_line(fd);
	if (res[0] == NULL)
	{
		ft_printf("Error: file contains nth bruh\n");
		free(res);
		exit(1);
	}
	res[j] = NULL;
	return (res);
}
