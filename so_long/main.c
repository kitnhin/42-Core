#include "so_long.h"

void init_structs(t_wall *walls, t_key *keys, t_game *game)
{
    walls->top_left_wall = "./textures/walls/top_left_wall.xpm";
    walls->up_wall = "./textures/walls/up_wall.xpm";
    walls->down_wall = "./textures/walls/down_wall.xpm";
    walls->right_wall = "./textures/walls/right_wall.xpm";
    walls->up_left_wall = "./textures/walls/up_left_wall.xpm";
    walls->up_right_wall = "./textures/walls/up_right_wall.xpm";
    walls->left_wall = "./textures/walls/left_wall.xpm";
    walls->floor = "./textures/floors/floor.xpm";
    walls->cross_wall = "./textures/walls/cross_wall.xpm";
    walls->down_left_wall = "./textures/walls/down_left_wall.xpm";
    walls->down_right_wall = "./textures/walls/down_right_wall.xpm";
	walls->exit = "./textures/walls/exit.xpm";
	keys->addr ="./textures/others/Key.xpm";
	game->player_addr = "./textures/others/Player_v2.xpm";
	game->player_pos_x = 0;
	game->player_pos_y = 0;
	game->map = NULL;
	game->steps = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->key_count = 0;
	game->total_keys = 0;
	game->exit_posx = 0;
	game->exit_posy = 0;
	game->total_bats = 0;
}

int main()
{
	t_wall	walls;
	t_key	keys;
	t_game	game;
	char *steps;
	int fd = open("./maps/map1.ber", O_RDWR);

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
	game.total_bats =  total_bats(game.map);
	find_player_start(&game);
	locate_e(game.map, &game.exit_posx, &game.exit_posy);
	mlx_loop_hook(game.mlx, &ft_animate, &game);
	mlx_hook(game.window, 2, 1L<<0, handle_keypress, &game);
	mlx_hook(game.window, 17, 0, &close_window, &game);
	mlx_loop(game.mlx);
}
