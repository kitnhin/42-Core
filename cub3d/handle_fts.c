#include "cub3d.h"

void	render_screen(t_game *game)
{
	int	x;

	x = 0;
	draw_ceiling(game);
	draw_floor(game);
	while (x < WIN_WIDTH)
	{
		raycasting(game, x);
		draw_line(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->screen.img_ptr, 0, 0);
}

void	change_movement_status(t_game *game, int keycode, int status)
{
	if (keycode == RIGHT && status == 1)
		game->movement.rot_right = true;
	else if (keycode == RIGHT && status == 0)
		game->movement.rot_right = false;
	else if (keycode == LEFT && status == 1)
		game->movement.rot_left = true;
	else if (keycode == LEFT && status == 0)
		game->movement.rot_left = false;
	else if (keycode == WKEY && status == 1)
		game->movement.front = true;
	else if (keycode == WKEY && status == 0)
		game->movement.front = false;
	else if (keycode == SKEY && status == 1)
		game->movement.back = true;
	else if (keycode == SKEY && status == 0)
		game->movement.back = false;
	else if (keycode == AKEY && status == 1)
		game->movement.left = true;
	else if (keycode == AKEY && status == 0)
		game->movement.left = false;
	else if (keycode == DKEY && status == 1)
		game->movement.right = true;
	else if (keycode == DKEY && status == 0)
		game->movement.right = false;
}