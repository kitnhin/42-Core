#include "so_long.h"

int main()
{
	t_wall	walls;
	t_key	keys;
	t_game	game;
	char *steps;
	int fd = open("./maps/map3.ber", O_RDWR);

	if  (read(fd, NULL, 0) < 0)
	{
		ft_printf("cant read file lol\n");
		return 0;
	}
	init_structs(&walls, &keys, &game);
	map_setup(&game, fd);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.map_width * 100, game.map_height * 100, "Hello world!");
	handle_image(&walls, &game, game.map_width, game.map_height, &keys);
	game.total_keys = total_keys(game.map);
	find_player_start(&game);
	print_player(&game);
	mlx_hook(game.window, 2, 1L<<0, handle_keypress, &game);
	mlx_hook(game.window, 17, 0, &close_window, &game);
	mlx_loop(game.mlx);
}