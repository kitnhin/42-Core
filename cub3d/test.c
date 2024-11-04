#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

void resize_image(void *mlx_ptr, void *src_img, int src_width, int src_height, void *dst_img, int dst_width, int dst_height)
{
	int	bitsperpixel;
	int	linesize;
	int	endian;
	int	x;
	int	y;
    int	*src_data;
    int	*dst_data;

	src_data = (int *)mlx_get_data_addr(src_img, &bitsperpixel, &linesize, &endian);
	dst_data = (int *)mlx_get_data_addr(dst_img, &bitsperpixel, &linesize, &endian);
	y = -1;

// complicated af but mlx_get_data_addr actually returns a char* array of data about the pixels in the picture
// we typecast it to int because the returned array contains info abt groups of RGBA for each pixels, where R is one char G is one char and so on
// therefore if we just typecast it to int, we can mainupula RGBA of each pixel easily by just changing the int values

    if (src_data == NULL || dst_data == NULL)
	{
        printf("Failed to get image data\n");
        return;
    }
	while (++y < dst_height)
    {
		x = -1;
        while (++x < dst_width)
        {
            int src_x = x * src_width / dst_width;
            int src_y = y * src_height / dst_height;
            dst_data[y * dst_width + x] = src_data[src_y * src_width + src_x];
        }
    }
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;
    void *src_img;
    void *dst_img;
    int src_width, src_height;
    int dst_width = 300; // Desired width
    int dst_height = 100; // Desired height

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Resized Image Window");
    src_img = mlx_xpm_file_to_image(mlx_ptr, "textures/testimg2.xpm", &src_width, &src_height);
    if (src_img == NULL)
	{
        printf("Failed to load image\n");
        return 1;
    }

    dst_img = mlx_new_image(mlx_ptr, dst_width, dst_height);
    resize_image(mlx_ptr, src_img, src_width, src_height, dst_img, dst_width, dst_height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, dst_img, 100, 100);
    mlx_loop(mlx_ptr);
    return 0;
}