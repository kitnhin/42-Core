#include "cub3d.h"

void	init_game_data(t_game *game)
{
	game->filedata = NULL;
	game->map = NULL;
	game->textures.ceilingcolor = malloc(sizeof(int) * 3);
	game->textures.floorcolor = malloc(sizeof(int) * 3);
	game->screen.img_ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->screen.img_data = (int*)mlx_get_data_addr(game->screen.img_ptr, &game->screen.bitsperpixel, &game->screen.linesize, &game->screen.endian);
	game->player.curr_dir = 0;
	game->player.curr_tileX = 0;
	game->player.curr_tileY = 0;
	game->player.dirX = 0;
	game->player.dirY = 0;
	game->player.planeX = 0;
	game->player.planeY = 0;
	game->player.posX = 0;
	game->player.posY = 0;
	game->movement.back = false;
	game->movement.front = false;
	game->movement.left = false;
	game->movement.right = false;
	game->movement.rot_left = false;
	game->movement.rot_right = false;
}

void	init_texs(t_game *game)
{
	// Load North texture
	game->n_tex.img_ptr = mlx_xpm_file_to_image(game->mlx, game->textures.north_texture, &game->n_tex.img_width, &game->n_tex.img_height);
	game->n_tex.img_data = (int*)mlx_get_data_addr(game->n_tex.img_ptr, &game->n_tex.bitsperpixel, &game->n_tex.linesize, &game->n_tex.endian);

	// Load South texture
	game->s_tex.img_ptr = mlx_xpm_file_to_image(game->mlx, game->textures.south_texture, &game->s_tex.img_width, &game->s_tex.img_height);
	game->s_tex.img_data = (int*)mlx_get_data_addr(game->s_tex.img_ptr, &game->s_tex.bitsperpixel, &game->s_tex.linesize, &game->s_tex.endian);

	// Load East texture
	game->e_tex.img_ptr = mlx_xpm_file_to_image(game->mlx, game->textures.east_texture, &game->e_tex.img_width, &game->e_tex.img_height);
	game->e_tex.img_data = (int*)mlx_get_data_addr(game->e_tex.img_ptr, &game->e_tex.bitsperpixel, &game->e_tex.linesize, &game->e_tex.endian);

	// Load West texture
	game->w_tex.img_ptr = mlx_xpm_file_to_image(game->mlx, game->textures.west_texture, &game->w_tex.img_width, &game->w_tex.img_height);
	game->w_tex.img_data = (int*)mlx_get_data_addr(game->w_tex.img_ptr, &game->w_tex.bitsperpixel, &game->w_tex.linesize, &game->w_tex.endian);
}

int	main_helper(char **argv, t_game *game)
{
	int			fd;
	int			len;

	len = ft_strlen(argv[1]);
	if(argv[1][len - 1] != 'b' || argv[1][len - 2] != 'u' || argv[1][len - 3] != 'c' || argv[1][len - 4] != '.')
		return (print_error("file need to have .cub at the back\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return(print_error("Error: invalid file\n"));
	init_game_data(game);
	game->filedata = readfile(fd);
	get_game_data(game);
	if (check_map(game) != 0)
		ft_exit();
	init_player_struct(game, &game->player);
	print_textures(game);
	print_player_stats(&game->player);
	init_texs(game);
	// castRay(game, game->player.posX, game->player.posY, game->player.curr_dir);
	return(0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	ft_exit();
	return (0);
}

void	print_key(int keycode)
{
	if (keycode == UP)
		printf("up arrow key pressed\n");
	if (keycode == DOWN)
		printf("down arrow key pressed\n");
	if (keycode == LEFT)
		printf("left arrow key pressed\n");
	if (keycode == RIGHT)
		printf("right arrow key pressed\n");
	if (keycode == WKEY)
		printf("W key pressed\n");
	if (keycode == AKEY)
		printf("A key pressed\n");
	if (keycode == SKEY)
		printf("S key pressed\n");
	if (keycode == DKEY)
		printf("D key pressed\n");
}

void	change_movement_status(t_game *game, int keycode, int status)
{
	if (keycode == RIGHT && status == 1)
		game->movement.rot_right = true;
	else if (keycode == RIGHT && status == 0)
		game->movement.rot_right = false;
	else if (keycode == LEFT && status == 1)
		game->movement.rot_left = true;
	else if (keycode == LEFT && status == 0)
		game->movement.rot_left = false;
	else if (keycode == WKEY && status == 1)
		game->movement.front = true;
	else if (keycode == WKEY && status == 0)
		game->movement.front = false;
	else if (keycode == SKEY && status == 1)
		game->movement.back = true;
	else if (keycode == SKEY && status == 0)
		game->movement.back = false;
	else if (keycode == AKEY && status == 1)
		game->movement.left = true;
	else if (keycode == AKEY && status == 0)
		game->movement.left = false;
	else if (keycode == DKEY && status == 1)
		game->movement.right = true;
	else if (keycode == DKEY && status == 0)
		game->movement.right = false;
}

int	handle_keypress(int keycode, t_game *game)
{
	int	i;

	i = 0;
	if (keycode == RIGHT || keycode == LEFT
		|| keycode == WKEY || keycode == AKEY
		|| keycode == SKEY || keycode == DKEY)
		change_movement_status(game, keycode, 1);
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

int	handle_keyrelease(int keycode, t_game *game)
{
	change_movement_status(game, keycode, 0);
	return (0);
}

int	loop_handle(t_game *game)
{
	move_player(game);
	rotate_player(game);
	render_screen(game);
	return (1);
}

int main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (print_error("Syntax incorrect\n"));
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, WIN_HEIGHT, WIN_WIDTH, "cub3d");
	if(main_helper(argv, &game) != 0)
		return (1);
	mlx_hook(game.window, KEY_PRESS, 1L << 0, handle_keypress, &game);
	mlx_hook(game.window, KEY_RELEASE, 1L << 1, handle_keyrelease, &game);
	mlx_loop_hook(game.mlx, &loop_handle, &game);
	mlx_hook(game.window, 17, 0, &close_window, &game);
	mlx_loop(game.mlx);
	return 0;
}
