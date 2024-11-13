#include "cub3d.h"

int	get_textures_1(t_game *game, int i)
{
	if(game->filedata && game->filedata[++i] && ft_strncmp(game->filedata[i], "NO ", 3) == 0)
		game->textures.north_texture = ft_substr(game->filedata[i], 3, ft_strlen(game->filedata[i]) - 4);
	else
		return(-2);
	if(game->filedata && game->filedata[++i] && ft_strncmp(game->filedata[i], "SO ", 3) == 0)
		game->textures.south_texture = ft_substr(game->filedata[i], 3, ft_strlen(game->filedata[i]) - 4);
	else
		return(-2);
	if(game->filedata && game->filedata[++i] && ft_strncmp(game->filedata[i], "WE ", 3) == 0)
		game->textures.west_texture = ft_substr(game->filedata[i], 3, ft_strlen(game->filedata[i]) - 4);
	else
		return(-2);
	if(game->filedata && game->filedata[++i] && ft_strncmp(game->filedata[i], "EA ", 3) == 0)
		game->textures.east_texture = ft_substr(game->filedata[i], 3, ft_strlen(game->filedata[i]) - 4);
	else
		return(-2);
	return (i + 1);
}

int	get_textures_2(t_game *game, int i)
{
	char	**temp;

	if (game->filedata[i] && ft_strncmp(game->filedata[i], "F ", 2) == 0)
	{
		temp = ft_split(game->filedata[i] + 2, ',');
		if (count_2d_arr(temp) != 3)
			return (-2);
		game->textures.floorcolor[0] = ft_atoi(temp[0]);
		game->textures.floorcolor[1] = ft_atoi(temp[1]);
		game->textures.floorcolor[2] = ft_atoi(temp[2]);
	}
	else
		return (-2);
	i++;
	free_2d_array(temp);
	if (game->filedata[i] && ft_strncmp(game->filedata[i], "C ", 2) == 0)
	{
		temp = ft_split(game->filedata[i] + 2, ',');
		if (count_2d_arr(temp) != 3)
			return (-2);
		game->textures.ceilingcolor[0] = ft_atoi(temp[0]);
		game->textures.ceilingcolor[1] = ft_atoi(temp[1]);
		game->textures.ceilingcolor[2] = ft_atoi(temp[2]);
	}
	else
		return(-2);
	free_2d_array(temp);
	return (i + 1);
}

void	get_map(t_game *game, int i)
{
	int	j;

	j = 0;
	game->map = malloc(sizeof(char *) * (get_map_height_for_malloc(game, i) + 1));
	while (game->filedata && game->filedata[i])
	{
		game->map[j] = ft_strdup(game->filedata[i]);
		i++;
		j++;
	}
	game->map[j] = NULL;
}
void	get_game_data(t_game *game)
{
	int	i;

	i = 0;
	while(game->filedata[i] == NULL || (game->filedata[i] && (game->filedata[i][0] == '\n' || game->filedata[i][0] == '\0')))
		i++;
	i = get_textures_1(game, i - 1);
	if(i == -2)
	{
		print_error("smth wrong about textures paths in .cub file\n");
		return ;
	}
	while(game->filedata[i] == NULL || (game->filedata[i] && (game->filedata[i][0] == '\n' || game->filedata[i][0] == '\0')))
		i++;
	i = get_textures_2(game, i);
	if(i == -2)
	{
		print_error("smth wrong about floor or ceiling colors in .cub file\n");
		ft_exit() ;
	}
	while(game->filedata[i] == NULL || (game->filedata[i] && (game->filedata[i][0] == '\n' || game->filedata[i][0] == '\0')))
		i++;
	get_map(game, i);
	free_2d_array(game->filedata);
}
