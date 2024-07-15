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
// 	game->key_count = 0;
// 	game->total_keys = 0;
// }

char **readmap(int fd)
{
	char **res;
	int j = 0;
	res = (char **)malloc(sizeof(char *) * 100); 
	while ((res[j] = get_next_line(fd)) != NULL)
		j++;
	if (res[0] == NULL)
	{
		ft_printf("file contains nth bruh\n");
		exit(1);
	}
	res[j] = NULL; 
	return res;
}

void	put_top_bottom_walls(int y, t_game *game, t_wall *walls, int map_width)
{
	int i = 0;
	int x = 100;
	while(i < map_width - 2)
	{
		if(y == 0)
			display_image(game, walls->up_wall, x, y);
		else
			display_image(game, walls->down_wall, x, y);
		x += 100;
		i++;
	}
}
void	put_others(char c, int x, int y, t_game *game, t_wall *walls)
{
	if (c == '1')
		display_image(game, walls->cross_wall, x, y);
	if (c == 'C')
		display_image(game, "textures/others/Key.xpm", x, y);
	if (c == 'E')
		display_image(game, walls->exit, x, y);
}
void	put_mid_walls(t_game *game, t_wall *walls, int map_height, int map_width)
{
	int x = 0;
	int i = 0;
	int j = 1;
	int y = 100;
	while(game->map[j] && j < map_height - 1)
	{
		display_image(game, walls->left_wall, x ,y);
		i++;
		x += 100;
		while(i < map_width - 1)
		{
			if(game->map[j][i] != '0' && game->map[j][i] != 'P')
				put_others(game->map[j][i], x, y, game, walls);
			else
				display_image(game, walls->floor, x, y);
			x += 100;
			i++;
		}
		display_image(game, walls->right_wall, x, y);
		x = 0;
		y += 100;
		i = 0;
		j++;
	}
}


void	handle_image(t_game *game)
{
	int x = 0;
	int y = 0;
	t_wall walls;

	init_walls(&walls);
	display_image(game, walls.up_left_wall, x , y);
	x += 100;
	put_top_bottom_walls(y, game, &walls, game->map_width);
	x = (game->map_width - 1) * 100;
	display_image(game, walls.up_right_wall, x, y);
	put_mid_walls(game, &walls, game->map_height, game->map_width);
	y = (game->map_height - 1) * 100;
	x = 0;
	display_image(game, walls.down_left_wall, x, y);
	put_top_bottom_walls(y, game, &walls, game->map_width);
	x = (game->map_width - 1) * 100;
	display_image(game, walls.down_right_wall, x,y);
}

void	map_setup(t_game *game, char *file)
{
	int fd;
	t_wall walls;
	t_key keys;
	t_game test;
	init_structs(&walls, &keys, &test);
	fd = open(file, O_RDWR);
	if  (read(fd, NULL, 0) < 0)
	{
		ft_printf("cant read file lol\n");
		exit(1);
	}
	game->map = readmap(fd);
	game->map_width = width_map(game->map);
	game->map_height = height_map(game->map);
	int map_error = check_map(game->map, game->map_width, game->map_height);
	if (map_error == 0)
	{
		ft_printf("map error bruh\n");
		exit(1);
	}
	// handle_image(&walls, game, game->map_width, game->map_height, &keys);
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