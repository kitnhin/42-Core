#include "cub3d.h"

void	init_game_data(t_game *game)
{
	game->filedata = NULL;
	game->map = NULL;
	game->textures.ceilingcolor = malloc(sizeof(int) * 3);
	game->textures.floorcolor = malloc(sizeof(int) * 3);
	game->textures.north_texture = NULL;
	game->textures.south_texture = NULL;
	game->textures.east_texture = NULL;
	game->textures.west_texture = NULL;
}

int	main_helper(char **argv, t_game *game)
{
	int		fd;
	int		len;

	len = ft_strlen(argv[1]);
	if(argv[1][len - 1] != 'b' || argv[1][len - 2] != 'u' || argv[1][len - 3] != 'c' || argv[1][len - 4] != '.')
		return (print_error("file need to have .cub at the back\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return(print_error("Error: invalid file\n"));
	init_game_data(game);
	game->filedata = readfile(fd);
	// print_2d_array(game.filedata);
	printf("--------------------------------------------\n");
	get_game_data(game);
	if (check_map(game) != 0)
		return (1);
	print_textures(game);
	return(0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
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
	t_game game;
	int n;
	if(argc != 2)
		return(print_error("Syntax incorrect\n"));
	n = main_helper(argv, &game);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 1000, 1000, "cub3d");
	img_main_control_function(&game);
	mlx_hook(game.window, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.window, 17, 0, &close_window, &game);
	mlx_loop(game.mlx);
	return n;
}
