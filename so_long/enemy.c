/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:56:21 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/17 12:57:56 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	total_bats(char **map)
{
	int	i;
	int	j;
	int	count;

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
	int		x;
	int		y;
	t_bat	*bat;

	bat = malloc(sizeof(t_key) * game->total_bats);
	x = 0;
	y = 0;
	while (game->map[y])
	{
		if (game->map[y][x] == 'B')
			bat_anim(game, x, y);
		if (game->map[y][x] == 0)
		{
			y++;
			x = 0;
		}
		x++;
	}
	free(bat);
}

// void	move_bat_right(t_game *game)
// {
// 	int x;
// 	int y;

// 	x = 0;
// 	y = 0;
// 	while(game->map[y])
// 	{
// 		if(game->map[y][x] == 'B')
// 		{
// 			game->map[y][x] = '0';
// 			x++;
// 			game->map[y][x] = 'B';
// 		}
// 		if(game->map[y][x] == 0)
// 		{
// 			y++;
// 			x = 0;
// 		}
// 		x++;
// 	}
// }

// void	move_bat_left(t_game *game)
// {
// 	int x;
// 	int y;

// 	x = 0;
// 	y = 0;
// 	while(game->map[y])
// 	{
// 		if(game->map[y][x] == 'B')
// 		{
// 			game->map[y][x] = '0';
// 			x--;
// 			game->map[y][x] = 'B';
// 			x++;
// 		}
// 		if(game->map[y][x] == 0)
// 		{
// 			y++;
// 			x = 0;
// 		}
// 		x++;
// 	}
// }
