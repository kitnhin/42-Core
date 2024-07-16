#include "so_long.h"

void	display_image(t_game *game, char *img_path, int x, int y)
{
	void *img;
	int img_width;
	int img_height;

	img = mlx_xpm_file_to_image(game->mlx, img_path, &img_width, &img_height);
	if (img == NULL)
	{
		mlx_string_put(game->mlx, game->window, 140, 100, 0xFFFFFF, "invalid");
		return;
	}
	mlx_put_image_to_window(game->mlx, game->window, img, x, y);
	mlx_destroy_image(game->mlx, img);
}
int close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	return (0);
}

int main(int argc, char *argv[])
{
	t_wall	walls;
	t_key	keys;
	t_game	game;
	// char *path = "./maps/map1.ber";
	// int fd = open("./maps/map1.ber", O_RDWR);
	if (argc == 2)
	{
		init_structs(&walls, &keys, &game);
		map_setup(&game, argv[1]);
		game.mlx = mlx_init();
		game.window = mlx_new_window(game.mlx, game.map_width * 100, game.map_height * 100, "Hello world!");
		handle_image(&game);
		game.total_keys = total_keys(game.map);
		game.total_bats =  total_bats(game.map);
		find_player_start(&game);
		locate_e(game.map, &game.exit_posx, &game.exit_posy);
		mlx_loop_hook(game.mlx, &ft_animate, &game);
		mlx_hook(game.window, 2, 1L<<0, handle_keypress, &game);
		mlx_hook(game.window, 17, 0, &close_window, &game);
		mlx_loop(game.mlx);
		mlx_destroy_window(game.mlx, game.window);
		mlx_destroy_display(game.mlx);
		return 0;
	}
	else
	{
		ft_printf("error, follow the syntax ./so_long ./maps/map\n");
		return 0;
	}
}
