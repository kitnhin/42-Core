#include "cub3d.h"

void	resize_img(t_img *img)
{
	int	x;
	int	y;

	y = -1;
	img->src_data = (int *)mlx_get_data_addr(img->src_img, &img->bitsperpixel, &img->linesize, &img->endian);
	img->dest_data = (int *)mlx_get_data_addr(img->dest_img, &img->bitsperpixel, &img->linesize, &img->endian);
	if (!img->src_data || !img->dest_data)
	{
		printf("Failed to get image data rip");
		return;
	}
	while (++y < img->dest_height)
	{
		x = -1;
		while(++x < img->dest_width)
		{
        	img->dest_data[y * img->dest_width + x] = img->src_data
			[(y * img->src_height / img->dest_height) * img->src_width +
			x * img->src_width / img->dest_width];
		}
	}
}

//wah this fking thing took me almost 3 hours
//mlx_get_data_addr returns a char *arr of information about the PIXELS, where each char stores RGBA of a pixel.
//i typecasted it to int so we can group tgt each RGBA (since its groups of 4 bytes), so can track easier (COPILOT HELPED)
//for the math, basically all the information is stored in a single array, so for example if the first row has 4 pixels, the data gonna be the first 4 ints,
//and the next 4 ints for the second row and so on..
//the src/dest data ratio is to handpick which pixel to take from the source for the dest.

void	init_img(t_img *img, char *img_path, int dst_width, int dst_height)
{
	img->dest_height = dst_height;
	img->dest_width = dst_width;
	img->src_img = mlx_xpm_file_to_image(img->mlx_ptr, img_path, &img->src_width, &img->src_height);
	img->dest_img = mlx_new_image(img->mlx_ptr, dst_width, dst_height);
	if (!img->src_img || !img->dest_img)
	{
		printf("Failed to open image\n");
		exit(1);
	}
}

void	print_img(t_game *game, char *img_path, int width, int height)
{
	t_img	img;

	img.mlx_ptr = game->mlx;
	init_img(&img, img_path, width, height);
	resize_img(&img);
	mlx_put_image_to_window(game->mlx, game->window, img.dest_img, 100, 100);
}

void	img_main_control_function(t_game *game)
{
	char	*img_path = "textures/testimg2.xpm";
	int width;
	int height;
	print_img(game, img_path, 300, 100);
	void	*ori_img = mlx_xpm_file_to_image(game->mlx, img_path, &width, &height);
	mlx_put_image_to_window(game->mlx, game->window, ori_img, 500, 500);
}