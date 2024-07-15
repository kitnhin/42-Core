#include "mlx.h"
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	*load_image(t_vars *vars, char *img_path, int *img_width, int *img_height)
{
	void *img;

	img = mlx_xpm_file_to_image(vars->mlx, img_path, img_width, img_height);
	if (img == NULL)
	{
		mlx_string_put(vars->mlx, vars->win, 140, 100, 0xFFFFFF, "invalid");
		return NULL;
	}
	return img;
}

int	main(void)
{
	t_vars	vars;
	void *img;
	void *img2;
	int img_width;
	int img_height;
	char *img_path = "./others/Bat.xpm";

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 700, 500, "Hello world!");
	img = load_image(&vars, img_path, &img_width, &img_height);
	img2 = load_image(&vars, "./bats/bat1.xpm", &img_width, &img_height);
	void *img3 = load_image(&vars, "./player2.xpm", &img_width, &img_height);
	void *img4 = load_image(&vars, "./bats/bat3.xpm", &img_width, &img_height);
	void *img5 = load_image(&vars, "./bats/bat4.xpm", &img_width, &img_height);
	// void *img6 = load_image(&vars, "./bats/bat1.xpm", &img_width, &img_height);
	// void *img7 = load_image(&vars, "./bats/bat1.xpm", &img_width, &img_height);
	if (img != NULL)
		mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img2, 100, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img3, 200, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img4, 300, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img5, 400, 0);
	// mlx_put_image_to_window(vars.mlx, vars.win, img6, 500, 0);
	// mlx_put_image_to_window(vars.mlx, vars.win, img7, 600, 0);
	mlx_loop(vars.mlx);
	return (0);
}