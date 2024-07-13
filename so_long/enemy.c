#include "so_long.h"

int total_bats(char **map)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (map[j])
	{
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'B')
				count++;
			i++;
		}
		j++;
		i = 0;
	}
	return (count);
}

void	print_bat(t_game *game)
{
	int	x;
	int	y;
	int i;
	t_bat *bat;

	bat = malloc(sizeof(t_key) * game->total_bats);
	x = 0;
	y = 0;
	i = 0;
	while(game->map[y])
	{
		if(game->map[y][x] == 'B')
		{
			bat[i].x = x;
			bat[i].y = y;
			i++;
		}
		if(game->map[y][x] == 0)
		{
			y++;
			x = 0;
		}
		x++;
	}
	bat_anim(game, bat);
}
