/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:14:22 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/17 21:45:11 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'E' && game->total_keys != 0)
		return (0);
	if (game->map[y][x] == 'C')
	{
		game->total_keys--;
		game->map[y][x] = '0';
	}
	if (game->map[y][x] == 'E' && game->total_keys == 0)
	{
		ft_printf("u won in here but unfortunately life says otherwise lol\n");
		close_window(game);
		exit(0);
	}
	if (game->map[y][x] == 'B')
	{
		ft_printf("how tf did u lose u actually suck\n");
		close_window(game);
		exit(0);
	}
	return (1);
}

int	check_move_player(int keycode, t_game *game)
{
	int	x;
	int	y;
	int	n;

	n = 0;
	x = game->player_pos_x;
	y = game->player_pos_y;
	if (keycode == UP || keycode == WKEY)
		y--;
	else if (keycode == DOWN || keycode == SKEY)
		y++;
	else if (keycode == RIGHT || keycode == DKEY)
		x++;
	else if (keycode == LEFT || keycode == AKEY)
		x--;
	n = check_move(game, x, y);
	return (n);
}
