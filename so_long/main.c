/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:54:08 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/17 22:10:02 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_setup(t_game *game, char *file)
{
	int		fd;
	t_wall	walls;
	t_key	keys;
	t_game	test;
	int		map_error;

	map_error = 0;
	init_structs(&walls, &keys, &test);
	fd = open(file, O_RDWR);
	if (read(fd, NULL, 0) < 0)
	{
		ft_printf("Error\ncant read file lol\n");
		exit(1);
	}
	game->map = readmap(fd);
	game->map_width = width_map(game->map);
	game->map_height = height_map(game->map);
	map_error = check_map(game->map, game->map_width, game->map_height);
	if (map_error == 0)
	{
		ft_printf("Error\ninvalid map bruh\n");
		exit(1);
	}
}

void	display_image(t_game *game, char *img_path, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(game->mlx, img_path, &img_width, &img_height);
	if (img == NULL)
	{
		mlx_string_put(game->mlx, game->window, 140, 100, 0xFFFFFF, "invalid");
		return ;
	}
	mlx_put_image_to_window(game->mlx, game->window, img, x, y);
	mlx_destroy_image(game->mlx, img);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	int	i;

	i = 0;
	if (keycode == UP || keycode == DOWN
		|| keycode == RIGHT || keycode == LEFT
		|| keycode == WKEY || keycode == AKEY
		|| keycode == SKEY || keycode == DKEY)
		move_player(keycode, game);
	else if (keycode == ESC)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		close_window(game);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_wall	walls;
	t_key	keys;
	t_game	game;

	if (argc == 2)
	{
		init_structs(&walls, &keys, &game);
		map_setup(&game, argv[1]);
		game.mlx = mlx_init();
		game.window = mlx_new_window(game.mlx, game.map_width * 100,
				game.map_height * 100, "Hello world!");
		handle_image(&game);
		game.total_keys = total_keys(game.map);
		game.total_bats = total_bats(game.map);
		find_player_start(&game);
		locate_e(game.map, &game.exit_posx, &game.exit_posy);
		mlx_loop_hook(game.mlx, &ft_animate, &game);
		mlx_hook(game.window, 2, 1L << 0, handle_keypress, &game);
		mlx_hook(game.window, 17, 0, &close_window, &game);
		mlx_loop(game.mlx);
	}
	else
		ft_printf("Error\n follow the syntax: ./so_long maps/map.ber\n");
	return (0);
}
