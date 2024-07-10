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

char **readmap(int fd)
{
	char **res;
	int j = 0;
	res = (char **)malloc(sizeof(char *) * 100); 
	if (get_next_line(fd) == NULL)
	{
		ft_printf("cant read map or map has nothing lol\n");
		exit(0);
	}
	while ((res[j] = get_next_line(fd)) != NULL)
		j++;
	res[j] = NULL; 
	return res;
}

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
}
void	put_top_bottom_walls(int y, t_game *game, t_wall *walls, int map_width)
{
	int i = 0;
	int x = 100;
	while(game->map[0][i] == '1' && i < map_width - 2)
	{
		if(y == 0)
			display_image(game, walls->up_wall, x, y);
		else
			display_image(game, walls->down_wall, x, y);
		x += 100;
		i++;
	}
}
void	put_others(char c, int x, int y, t_game *game, t_wall *walls, t_key *keys)
{
	if (c == '1')
		display_image(game, walls->cross_wall, x, y);
	if (c == 'C')
		display_image(game, keys->addr, x, y);
	if (c == 'E')
		display_image(game, walls->exit, x, y);
}
void	put_mid_walls(t_game *game, t_wall *walls, int map_height, int map_width, t_key *keys)
{
	int x = 100;
	int i = 0;
	int j = 1;
	int y = 100;
	while(j < map_height - 1)
	{
		if(game->map[j][0] == '1' && i == 0)
		{
			x = 0;
			display_image(game, walls->left_wall, x, y);
			x += 100;
		}
		i++;
		if(game->map[j][map_width - 1] == '1' && i == map_width - 1)
		{
			display_image(game, walls->right_wall, x, y);
			x = 0;
			y += 100;
			i = 0;
			j++;
		}
		else if(game->map[j][i] != '0' && game->map[j][i] != 'P')
			put_others(game->map[j][i], x, y, game, walls, keys);
		else
			display_image(game, walls->floor, x, y);
		x += 100;
	}
}


void	handle_image(t_wall *walls, t_game *game, int map_width, int map_height, t_key *keys)
{
	int x = 0;
	int y = 0;

	display_image(game, walls->up_left_wall, x , y);
	x += 100;
	put_top_bottom_walls(y, game, walls, map_width);
	x = (map_width - 1) * 100;
	display_image(game, walls->up_right_wall, x, y);
	put_mid_walls(game, walls, map_height, map_width, keys);
	y = (map_height - 1) * 100;
	x = 0;
	display_image(game, walls->down_left_wall, x, y);
	put_top_bottom_walls(y, game, walls, map_width);
	x = (map_width - 1) * 100;
	display_image(game, walls->down_right_wall, x,y);
}

// int	main(void)
// {
// 	t_wall	walls;
// 	t_key	keys;
// 	t_game	game;
// 	char *img_path = "./wall.xpm";
// 	int fd = open("./maps/map1.ber", O_RDWR);

// 	game.mlx = mlx_init();
// 	game.window = mlx_new_window(game.mlx, 1300, 500, "Hello world!");
// 	init_structs(&walls, &keys, &game);
// 	game.map = readmap(fd);
// 	handle_image(&walls,&game, 13, 5, &keys);
// 	mlx_loop(game.mlx);
// }