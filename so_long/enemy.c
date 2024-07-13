#include "so_long.h"

void	handle_bat(t_game *game)
{
	int	x;
	int	y;
	int i;
	t_bat *bat;

	bat = malloc(sizeof(t_key) * game->total_keys);
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
