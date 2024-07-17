/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:52:06 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/17 21:42:56 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_start(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y] != NULL && game->map[y][x] != 'P')
	{
		x++;
		if (game->map[y][x] == '\0')
		{
			x = 0;
			y++;
		}
	}
	if (game->map[y][x] == 'P')
	{
		game->player_pos_x = x;
		game->player_pos_y = y;
	}
}

void	print_steps(t_game *game)
{
	char	*str;

	str = ft_itoa(game->steps);
	display_image(game, "./textures/walls/up_wall.xpm", 100, 0);
	mlx_string_put(game->mlx, game->window, 130, 50, 0xFFFFFF, "steps: ");
	mlx_string_put(game->mlx, game->window, 170, 50, 0xFFFFFF, str);
	free(str);
}

void	move_player_ver(int keycode, t_game *game)
{
	char	*floor;

	floor = "./textures/floors/floor.xpm";
	if (keycode == UP || keycode == WKEY)
	{
		game->map[game->player_pos_y][game->player_pos_x] = '0';
		display_image(game, floor, game->player_pos_x * 100,
			game->player_pos_y * 100);
		game->player_pos_y -= 1;
		game->map[game->player_pos_y][game->player_pos_x] = 'P';
	}
	else if (keycode == DOWN || keycode == SKEY)
	{
		game->map[game->player_pos_y][game->player_pos_x] = '0';
		display_image(game, floor, game->player_pos_x * 100,
			game->player_pos_y * 100);
		game->player_pos_y += 1;
		game->map[game->player_pos_y][game->player_pos_x] = 'P';
	}
}

void	move_player_hori(int keycode, t_game *game)
{
	char	*floor;

	floor = "./textures/floors/floor.xpm";
	if (keycode == RIGHT || keycode == DKEY)
	{
		game->map[game->player_pos_y][game->player_pos_x] = '0';
		display_image(game, floor, game->player_pos_x * 100,
			game->player_pos_y * 100);
		game->player_pos_x += 1;
		game->map[game->player_pos_y][game->player_pos_x] = 'P';
	}
	if (keycode == LEFT || keycode == AKEY)
	{
		game->map[game->player_pos_y][game->player_pos_x] = '0';
		display_image(game, floor, game->player_pos_x * 100,
			game->player_pos_y * 100);
		game->player_pos_x -= 1;
		game->map[game->player_pos_y][game->player_pos_x] = 'P';
	}
}

void	move_player(int keycode, t_game *game)
{
	if (check_move_player(keycode, game) == 1)
	{
		game->steps++;
		print_steps(game);
		ft_printf("number of steps : %d\n", game->steps);
		if (game->total_keys == 0)
			display_image(game, "./textures/others/open_exit.xpm",
				game->exit_posx * 100, game->exit_posy * 100);
		if (keycode == UP || keycode == WKEY
			|| keycode == DOWN || keycode == SKEY)
			move_player_ver(keycode, game);
		else if (keycode == RIGHT || keycode == DKEY
			|| keycode == LEFT || keycode == AKEY)
			move_player_hori(keycode, game);
		display_image(game, "./textures/player/player.xpm",
			game->player_pos_x * 100, game->player_pos_y * 100);
	}
}

// void animate(char **frames, t_game *game, int pos_x, int pos_y)
// {
// 	 int i = 0;
// 	 int j = 0;
// 	 int a = 0;
// 	 char *path;
// 	 while(j < 1)
// 	 {
// 		path = frames[i];
// 		display_image(game, path, pos_x , pos_y);
// 		i = (i + 1)% 8;
// 		while (a < 130000000)
// 			a++;
// 		a = 0;
// 	 }
// }

// void	print_player(t_game *game)
// {
// 	int x = game->player_pos_x * 100;
// 	int y = game->player_pos_y * 100;
// 	int i = 0;
// 	char **frames = (char **)malloc(8 * sizeof(char *));
//     frames[0] = "./textures/player/player.xpm";
//     frames[1] = "./textures/player/player3.xpm";
//     frames[2] = "./textures/player/player2.xpm";
//     frames[3] = "./textures/player/player3.xpm";
//     frames[4] = "./textures/player/player.xpm";
// 	frames[5] = "./textures/player/player5.xpm";
// 	frames[6] = "./textures/player/player4.xpm";
// 	frames[7] = "./textures/player/player5.xpm";
// 	display_image(game, frames[i], x, y);
// 	i = (i + 1) % 8;
// }
// void	print_player(t_game *game)
// {
// 	int x = game->player_pos_x * 100;
// 	int y = game->player_pos_y * 100;
// 	display_image(game, game->player_addr, x, y);
// }

// int	main(void)
// {
// 	t_wall	walls;
// 	t_key	keys;
// 	t_game	game;
// 	int fd = open("./maps/map1.ber", O_RDWR);

// 	game.mlx = mlx_init();
// 	game.window = mlx_new_window(game.mlx, 1300, 500, "Hello world!");
// 	init_structs(&walls, &keys, &game);
// 	game.map = readmap(fd);
// 	handle_image(&walls,&game, 13, 5, &keys);
// 	mlx_loop(game.mlx);
// }