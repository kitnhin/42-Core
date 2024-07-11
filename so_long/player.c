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
void	print_steps(t_game *game)
{
	char *str;

	str = ft_itoa(game->steps);
	display_image(game, "./textures/walls/up_wall.xpm", 100, 0);
	mlx_string_put(game->mlx, game->window, 130, 50, 0xFFFFFF, "steps: ");
	mlx_string_put(game->mlx, game->window, 170, 50, 0xFFFFFF, str);
}
void	move_player(int keycode, t_game *game)
{
	char *floor = "./textures/floors/floor.xpm";
	
	if(check_move_player(keycode, game) == 1)
	{
		game->steps++;
		print_steps(game);
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
	char *open_exit = "./textures/others/open_exit.xpm";

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
	if (game->map[y][x] == 'E' && game->key_count != game->total_keys)
		return 0;
	if (game->map[y][x] == 'C')
	{
		game->key_count++;
		if (game->key_count == game->total_keys)
			display_image(game, open_exit, game->exit_posx * 100, game->exit_posy * 100);
	}
	if (game->map[y][x] == 'E' && game->key_count == game->total_keys)
	{
		ft_printf("u won in here but unfortunately life says otherwise lol\n");
		close_window(game);
		exit(0);
	}
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
// void animate(char **frames, t_game *game)
// {
// 	 int i = 0;
// 	 int j = 0;
// 	 int a = 0;
// 	 char *path;
// 	 while(j < 1)
// 	 {
// 		path = frames[i];
// 		display_image(vars, path, 0 , 0);
// 		i = (i + 1)% 8;
// 		while (a < 130000000)
// 			a++;
// 		a = 0;
// 	 }
// }

void	print_player(t_game *game)
{
	int x = game->player_pos_x * 100;
	int y = game->player_pos_y * 100;
	display_image(game, game->player_addr, x, y);
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