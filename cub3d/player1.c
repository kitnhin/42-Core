#include "cub3d.h"

int	locate_player_row(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < get_map_height(map))
	{
		j = 0;
		while (j < (int)ft_strlen(map[i]))
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
				return(i);
			j++;
		}
		i++;
	}
	return(-1);
}

int	locate_player_col(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < get_map_height(map))
	{
		j = 0;
		while (j < (int)ft_strlen(map[i]))
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
				return(j);
			j++;
		}
		i++;
	}
	return(-1);
}

char get_player_start_dir(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < get_map_height(map))
	{
		j = 0;
		while (j < (int)ft_strlen(map[i]))
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
				return(map[i][j]);
			j++;
		}
		i++;
	}
	return('\0');
}

void	init_player_struct(t_game* game, t_player *player)
{
	player->curr_tileX = locate_player_col(game->map);
	player->curr_tileY = locate_player_row(game->map);
	player->posX = player->curr_tileX * TILE_SIZE + (TILE_SIZE / 2);
	player->posY = player->curr_tileY * TILE_SIZE + (TILE_SIZE / 2);
	if (get_player_start_dir(game->map) == 'E')
	{
		game->player.dirX = 1;
		game->player.planeY = 0.66;
	}
	else if (get_player_start_dir(game->map) == 'N')
	{
		game->player.dirY = -1;
		game->player.planeX = 0.66;
	}
	else if (get_player_start_dir(game->map) == 'W')
	{
		game->player.dirX = -1;
		game->player.planeY = -0.66;
	}
	else
	{
		game->player.dirY = 1;
		game->player.planeX = -0.66;
	}
	game->player.curr_dir = 0;
}

void	rotate_player(t_game *game)
{
	double	temp;
	if (game->movement.rot_left == true)
	{
		temp = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(deg_to_rad(-ROT_SPEED)) - game->player.dirY * sin(deg_to_rad(-ROT_SPEED));
		game->player.dirY = game->player.dirY * cos(deg_to_rad(-ROT_SPEED)) + temp * sin(deg_to_rad(-ROT_SPEED));
		temp = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(deg_to_rad(-ROT_SPEED)) - game->player.planeY * sin(deg_to_rad(-ROT_SPEED));
		game->player.planeY = game->player.planeY * cos(deg_to_rad(-ROT_SPEED)) + temp * sin(deg_to_rad(-ROT_SPEED));
	}
	if (game->movement.rot_right == true)
	{
		temp = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(deg_to_rad(ROT_SPEED)) - game->player.dirY * sin(deg_to_rad(ROT_SPEED));
		game->player.dirY = game->player.dirY * cos(deg_to_rad(ROT_SPEED)) + temp * sin(deg_to_rad(ROT_SPEED));
		temp = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(deg_to_rad(ROT_SPEED)) - game->player.planeY * sin(deg_to_rad(ROT_SPEED));
		game->player.planeY = game->player.planeY * cos(deg_to_rad(ROT_SPEED)) + temp * sin(deg_to_rad(ROT_SPEED));
	}
}

void	move_player(t_game *game)
{
	if (game->movement.front == true)
		move_front(game);
	else if (game->movement.back == true)
		move_back(game);
	else if (game->movement.left == true)
		move_left(game);
	else if (game->movement.right == true)
		move_right(game);
	game->player.curr_tileX = (int)game->player.posX / TILE_SIZE;
	game->player.curr_tileY = (int)game->player.posY / TILE_SIZE;
}

