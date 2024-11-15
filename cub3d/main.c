#include "cub3d.h"

void	init_game_data(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIN_HEIGHT, WIN_WIDTH, "cub3d");
	game->filedata = NULL;
	game->map = NULL;
	game->textures.ceilingcolor = malloc(sizeof(int) * 3);
	game->textures.floorcolor = malloc(sizeof(int) * 3);
	game->screen.img_ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->screen.img_data = (int*)mlx_get_data_addr(game->screen.img_ptr, &game->screen.bitsperpixel, &game->screen.linesize, &game->screen.endian);
	game->filedata = NULL;
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
	game->n_tex.img_ptr = mlx_xpm_file_to_image(game->mlx, game->textures.north_texture, &game->n_tex.img_width, &game->n_tex.img_height);
	game->n_tex.img_data = (int*)mlx_get_data_addr(game->n_tex.img_ptr, &game->n_tex.bitsperpixel, &game->n_tex.linesize, &game->n_tex.endian);
	game->s_tex.img_ptr = mlx_xpm_file_to_image(game->mlx, game->textures.south_texture, &game->s_tex.img_width, &game->s_tex.img_height);
	game->s_tex.img_data = (int*)mlx_get_data_addr(game->s_tex.img_ptr, &game->s_tex.bitsperpixel, &game->s_tex.linesize, &game->s_tex.endian);
	game->e_tex.img_ptr = mlx_xpm_file_to_image(game->mlx, game->textures.east_texture, &game->e_tex.img_width, &game->e_tex.img_height);
	game->e_tex.img_data = (int*)mlx_get_data_addr(game->e_tex.img_ptr, &game->e_tex.bitsperpixel, &game->e_tex.linesize, &game->e_tex.endian);
	game->w_tex.img_ptr = mlx_xpm_file_to_image(game->mlx, game->textures.west_texture, &game->w_tex.img_width, &game->w_tex.img_height);
	game->w_tex.img_data = (int*)mlx_get_data_addr(game->w_tex.img_ptr, &game->w_tex.bitsperpixel, &game->w_tex.linesize, &game->w_tex.endian);
}

void	check_argv(char **argv)
{
	int			len;

	len = ft_strlen(argv[1]);
	if(argv[1][len - 1] != 'b' || argv[1][len - 2] != 'u' || argv[1][len - 3] != 'c' || argv[1][len - 4] != '.')
	{
		print_error("file need to have .cub at the back\n");
		ft_exit();
	}
}

void	import_data(t_game *game, char **argv)
{
	int			fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error("Error: invalid file\n");
		ft_exit();
	}
	game->filedata = readfile(fd);
	get_game_data(game);
}

int	main_helper(char **argv, t_game *game)
{
	check_argv(argv);
	init_game_data(game);
	import_data(game, argv);
	if (check_map(game) != 0)
		ft_exit();
	init_player_struct(game, &game->player);
	init_texs(game);
	return(0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	ft_exit();
	return (0);
}

int main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (print_error("Syntax incorrect\n"));
	if(main_helper(argv, &game) != 0)
		return (1);
	mlx_hook(game.window, KEY_PRESS, 1L << 0, handle_keypress, &game);
	mlx_hook(game.window, KEY_RELEASE, 1L << 1, handle_keyrelease, &game);
	mlx_loop_hook(game.mlx, &loop_handle, &game);
	mlx_hook(game.window, 17, 0, &close_window, &game);
	mlx_loop(game.mlx);
	return 0;
}
