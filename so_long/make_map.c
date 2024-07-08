#include "mlx.h"
#include <stdio.h>
#include "libft/libft.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}		t_vars;

typedef struct s_wall{
	char *top_left_wall;
	char *up_wall;
	char *down_wall;
	char *right_wall;
	char *up_left_wall;
	char *up_right_wall;
	char *left_wall;
	char *floor;
	char *cross_wall;
	char *down_left_wall;
	char *down_right_wall;
}	t_wall;

void init_wall(t_wall *walls)
{
    walls->top_left_wall = "./walls/top_left_wall.xpm";
    walls->up_wall = "./walls/up_wall.xpm";
    walls->down_wall = "./walls/down_wall.xpm";
    walls->right_wall = "./walls/right_wall.xpm";
    walls->up_left_wall = "./walls/up_left_wall.xpm";
    walls->up_right_wall = "./walls/up_right_wall.xpm";
    walls->left_wall = "./walls/left_wall.xpm";
    walls->floor = "./walls/floor.xpm";
    walls->cross_wall = "./walls/cross_wall.xpm";
    walls->down_left_wall = "./walls/down_left_wall.xpm";
    walls->down_right_wall = "./walls/down_right_wall.xpm";
}

char **readmap(int fd)
{
	char **res;
	int j = 0;
	res = (char **)malloc(sizeof(char *) * 100); 
	while ((res[j] = get_next_line(fd)) != NULL)
	{
		j++;
	}
	res[j] = NULL; 
	return res;
}

void	load_and_display_image(t_vars *vars, char *img_path, int x, int y)
{
	void *img;
	int img_width;
	int img_height;

	img = mlx_xpm_file_to_image(vars->mlx, img_path, &img_width, &img_height);
	if (img == NULL)
	{
		mlx_string_put(vars->mlx, vars->win, 140, 100, 0xFFFFFF, "invalid");
		return;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
}
void	put_top_walls(int x, char **map, t_wall *walls, t_vars *vars, int map_width)
{
	int i = 0;
	while(map[0][i] == '1' && i < map_width - 2)
	{
			load_and_display_image(vars, walls->up_wall, x, 0);
			x += 100;
			i++;
	}
}

void	put_mid_walls(char **map, t_wall *walls, t_vars *vars, int map_height, int map_width)
{
	int j = 1;
	int i = 0;
	int x = 0;
	int y = 100;
	while(j < map_height - 1)
	{
		if(map[j][0] == '1' && i == 0)
		{
			load_and_display_image(vars, walls->left_wall, x, y);
			x += 100;
		}
		i++;
		if(map[j][map_width - 1] == '1' && i == map_width - 1)
		{
			load_and_display_image(vars, walls->right_wall, x, y);
			x = 0;
			y += 100;
			i = 0;
			j++;
		}
		else if(map[j][i] == '1')
		{
			load_and_display_image(vars, walls->cross_wall, x, y);
			x += 100;
		}
		else
		{
			load_and_display_image(vars, walls->floor, x, y);
			x += 100;
		}
	}
}
void	put_down_walls(int y, char **map, t_wall *walls, t_vars *vars, int map_width, int map_height)
{
	int i = 0;
	int x = 100;
	while(map[map_height - 1][i] == '1' && i < map_width - 2)
	{
			load_and_display_image(vars, walls->down_wall, x, y);
			x += 100;
			i++;
	}
}

void	handle_image(t_wall *walls, t_vars *vars,char **map, int map_width, int map_height)
{
	int x = 0;
	int y = 0;

	load_and_display_image(vars, walls->up_left_wall, x , y);
	x += 100;
	put_top_walls(x, map, walls, vars, map_width);
	x = (map_width - 1) * 100;
	load_and_display_image(vars, walls->up_right_wall, x, y);
	put_mid_walls(map, walls, vars, map_height, map_width);
	y = (map_height - 1) * 100;
	x = 0;
	load_and_display_image(vars, walls->down_left_wall, x, y);
	put_down_walls(y, map, walls, vars, map_width, map_height);
	x = (map_width - 1) * 100;
	load_and_display_image(vars, walls->down_right_wall, x,y);
}
int	main(void)
{
	t_vars	vars;
	t_wall	walls;
	char **map;
	char *img_path = "./wall.xpm";
	int fd = open("map1.ber", O_RDWR);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1300, 500, "Hello world!");
	init_wall(&walls);
	map = readmap(fd);
	handle_image(&walls, &vars, map, 13, 5);
	mlx_loop(vars.mlx);
	return (0);
}