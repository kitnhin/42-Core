#include "cub3d.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == RIGHT || keycode == LEFT
		|| keycode == WKEY || keycode == AKEY
		|| keycode == SKEY || keycode == DKEY)
			change_movement_status(game, keycode, 1);
	else if (keycode == ESC)
	{
		free_2d_array(game->map);
		ft_exit();
	}
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	change_movement_status(game, keycode, 0);
	return (0);
}

int	loop_handle(t_game *game)
{
	move_player(game);
	rotate_player(game);
	render_screen(game);
	return (1);
}
