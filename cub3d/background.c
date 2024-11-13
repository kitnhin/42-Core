#include "cub3d.h"

int	convert_to_hex(int *arr)
{
	int	red;
	int	green;
	int	blue;
	int	res;

	red = arr[0];
	green = arr[1];
	blue = arr[2];
	res = red << 16 | green << 8 | blue;
	return res;
}
// shift red value by 16 bits because red is the most left component
// same thing

void	draw_rectangle_into_dest_img(int color, int *data, int start, int end)
{
	int	x;
	int	y;

	y = start - 1;
	while (++y < end)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			data[y * WIN_WIDTH + x] = color;
	}
}

void	draw_floor(t_game *game)
{
	int		hex_color;

	hex_color = convert_to_hex(game->textures.floorcolor);
	draw_rectangle_into_dest_img(hex_color, game->screen.img_data, WIN_WIDTH / 2, WIN_WIDTH);
}

void	draw_ceiling(t_game *game)
{
	int		hex_color;

	hex_color = convert_to_hex(game->textures.ceilingcolor);
	draw_rectangle_into_dest_img(hex_color, game->screen.img_data, 0, WIN_WIDTH / 2);
}
