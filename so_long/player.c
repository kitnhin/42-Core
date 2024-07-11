#include "so_long.h"

// void init_structs(t_wall *walls, t_key *keys, t_game *game)
// {
//     walls->top_left_wall = "./textures/walls/top_left_wall.xpm";
//     walls->up_wall = "./textures/walls/up_wall.xpm";
//     walls->down_wall = "./textures/walls/down_wall.xpm";
//     walls->right_wall = "./textures/walls/right_wall.xpm";
//     walls->up_left_wall = "./textures/walls/up_left_wall.xpm";
//     walls->up_right_wall = "./textures/walls/up_right_wall.xpm";
//     walls->left_wall = "./textures/walls/left_wall.xpm";
//     walls->floor = "./textures/floors/floor.xpm";
//     walls->cross_wall = "./textures/walls/cross_wall.xpm";
//     walls->down_left_wall = "./textures/walls/down_left_wall.xpm";
//     walls->down_right_wall = "./textures/walls/down_right_wall.xpm";
// 	walls->exit = "./textures/walls/exit.xpm";
// 	keys->addr ="./textures/others/Key.xpm";
// 	game->player_addr = "./textures/others/Player_v2.xpm";
// 	game->player_pos_x = 0;
// 	game->player_pos_y = 0;
// 	game->map = NULL;
// 	game->steps = 0;
// 	game->map_width = 0;
// 	game->map_height = 0;
// }
void find_player_start(t_game *game)
{
	int x = 0;
	int y = 0;
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
void	move_player(int keycode, t_game *game)
{
	char *floor = "./textures/floors/floor.xpm";
	
	if(check_move_player(keycode, game) == 1)
	{
		game->steps++;
		ft_printf("number of steps : %d\n", game->steps);
		if (keycode == up)
		{
			game->map[game->player_pos_y][game->player_pos_x] = '0';
			display_image(game, floor, game->player_pos_x * 100, game->player_pos_y * 100);
			game->player_pos_y -= 1;
			game->map[game->player_pos_y][game->player_pos_x] = 'P';
		}
		else if (keycode == down)
		{
			game->map[game->player_pos_y][game->player_pos_x] = '0';
			display_image(game, floor, game->player_pos_x * 100, game->player_pos_y * 100);
			game->player_pos_y += 1;
			game->map[game->player_pos_y][game->player_pos_x] = 'P';
		}
		else if (keycode == right)
		{
			game->map[game->player_pos_y][game->player_pos_x] = '0';
			display_image(game, floor, game->player_pos_x * 100, game->player_pos_y * 100);
			game->player_pos_x += 1;
			game->map[game->player_pos_y][game->player_pos_x] = 'P';
		}
		else if (keycode == left)
		{
			game->map[game->player_pos_y][game->player_pos_x] = '0';
			display_image(game, floor, game->player_pos_x * 100, game->player_pos_y * 100);
			game->player_pos_x -= 1;
			game->map[game->player_pos_y][game->player_pos_x] = 'P';
		}
	}
	print_player(game);
}
int check_move_player(int keycode, t_game *game)
{
    int x = game->player_pos_x;
    int y = game->player_pos_y;

    if (keycode == up)
        y--;
    else if (keycode == down)
        y++;
    else if (keycode == right)
        x++;
    else if (keycode == left)
        x--;

    if (game->map[y][x] == '1')
        return 0;
	if (game->map[y][x] == 'E')
		return 0;

    return 1;
}
int close_window(t_game *game)
{
	mlx_destroy_display(game->mlx);
	exit(0);
	return (0);
}
int handle_keypress(int keycode, t_game *game)
{
	if(keycode == up || keycode == down || keycode == right || keycode == left)
		move_player(keycode, game);
	else if(keycode == esc)
		close_window(game);
	return 0;
}
void	print_player(t_game *game)
{
	int x = game->player_pos_x * 100;
	int y = game->player_pos_y * 100;
	display_image(game, game->player_addr, x, y);
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
	find_player_start(&game);
	print_player(&game);
	mlx_hook(game.window, 2, 1L<<0, handle_keypress, &game);
	mlx_hook(game.window, 17, 0, &close_window, &game);
	mlx_loop(game.mlx);
}

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