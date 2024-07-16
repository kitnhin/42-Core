/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:52:35 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/16 23:12:02 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	ft_animate(t_game *game)
{
	game->frames++;
	if (game->frames > 10000)
	{
		char_anim(game);
		print_key(game);
		print_bat(game);
		game->frames = 0;
	}
	game->frames++;
	return (0);
}

void	char_anim(t_game *game)
{
	static int	i = 0;
	char		**frames;
	char		*path;

	frames = (char **)malloc(8 * sizeof(char *));
	frames[0] = "./textures/player/player.xpm";
	frames[1] = "./textures/player/player3.xpm";
	frames[2] = "./textures/player/player2.xpm";
	frames[3] = "./textures/player/player3.xpm";
	frames[4] = "./textures/player/player.xpm";
	frames[5] = "./textures/player/player5.xpm";
	frames[6] = "./textures/player/player4.xpm";
	frames[7] = "./textures/player/player5.xpm";
	path = frames[i];
	display_image(game, path, game->player_pos_x * 100,
		game->player_pos_y * 100);
	i = (i + 1) % 8;
	free(frames);
}

void	key_anim(t_game *game, t_key *keys)
{
	static int	i = 0;
	int			j;
	char		*path;
	char		**frames;

	j = 0;
	frames = (char **)malloc(6 * sizeof(char *));
	frames[0] = "./textures/keys/key1.xpm";
	frames[1] = "./textures/keys/key2.xpm";
	frames[2] = "./textures/keys/key3.xpm";
	frames[3] = "./textures/keys/key4.xpm";
	frames[4] = "./textures/keys/key5.xpm";
	frames[5] = "./textures/keys/key6.xpm";
	path = frames[i];
	while (j < game->total_keys)
	{
		display_image(game, path, keys[j].x * 100, keys[j].y * 100);
		j++;
	}
	i = (i + 1) % 6;
	free(frames);
}

void	bat_anim(t_game *game, int x, int y)
{
	static int	i = 0;
	char		*path;
	char		**frames;

	frames = (char **)malloc(11 * sizeof(char *));
	frames[0] = "./textures/bats/bat1.xpm";
	frames[1] = "./textures/bats/bat1.xpm";
	frames[2] = "./textures/bats/bat2.xpm";
	frames[3] = "./textures/bats/bat2.xpm";
	frames[4] = "./textures/bats/bat3.xpm";
	frames[5] = "./textures/bats/bat3.xpm";
	frames[6] = "./textures/bats/bat4.xpm";
	frames[7] = "./textures/bats/bat2.xpm";
	frames[8] = "./textures/bats/bat2.xpm";
	frames[9] = "./textures/bats/bat1.xpm";
	frames[10] = "./textures/bats/bat1.xpm";
	path = frames[i];
	display_image(game, path, x * 100, y * 100);
	i = (i + 1) % 11;
	free(frames);
}

// int	move_bat(t_game *game)
// {
// 	static int a;

// 	a = 0;
// 	if (a == 0)
// 	{
// 		move_bat_right(game);
// 		a = 1;
// 	}
// 	else if (a == 1)
// 	{
// 		move_bat_left(game);
// 		a = 0;
// 	}
// 	return 0;
// }