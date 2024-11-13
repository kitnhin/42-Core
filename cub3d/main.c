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
int	handle_keypress(int keycode, t_game *game)
{
	int	i;

	i = 0;
	if (keycode == UP || keycode == DOWN
		|| keycode == RIGHT || keycode == LEFT
		|| keycode == WKEY || keycode == AKEY
		|| keycode == SKEY || keycode == DKEY)
		print_key(keycode);
	if(keycode == RIGHT || keycode == LEFT)
	{
		rotate_player(game, keycode);
		printf("curr dir: %f\n", game->player.curr_dir);
		// castRay(game, game->player.posX, game->player.posY, game->player.curr_dir);
	}
	if(keycode == WKEY || keycode == AKEY
		|| keycode == SKEY || keycode == DKEY)
	{
		move_player(game, keycode);
		print_player_stats(&game->player);
		// castRay(game, game->player.posX, game->player.posY, game->player.curr_dir);
	}
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

int main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (print_error("Syntax incorrect\n"));
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, WIN_HEIGHT, WIN_WIDTH, "cub3d");
	if(main_helper(argv, &game) != 0)
		return (1);
	mlx_hook(game.window, 2, 1L << 0, handle_keypress, &game);
	mlx_loop_hook(game.mlx, &render_screen, &game);
	mlx_hook(game.window, 17, 0, &close_window, &game);
	mlx_loop(game.mlx);
	return 0;
}
