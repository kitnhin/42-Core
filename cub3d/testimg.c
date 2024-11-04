#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

void	display_image(void *window, void *mlx, char *img_path)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(mlx, img_path, &img_width, &img_height);
	if (img == NULL)
	{
		mlx_string_put(mlx, window, 140, 100, 0xFFFFFF, "invalid");
		return ;
	}
	mlx_put_image_to_window(mlx, window, img, 100, 100);
	mlx_destroy_image(mlx, img);
}


int main()
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "testimg");
	display_image(window, mlx, "textures/testimg2.xpm");
	mlx_loop(mlx);
}