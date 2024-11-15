#include "cub3d.h"

// line 1: calculate the coordinate of the ray in the camera plane (-1 is the most left, 1 is the most right)
// line 2 and 3 : determines the x and y component of the ray angle
// Lets say player is facing 1, 0 (right), since camera perpendicular then planeX will be 0, planeY will be 0.66
// rayDirX = 1
// rayDirY = -0.66 (left) to 0.66 (right)
// line 4 and 5: calculates how much the rays length increase due to one unit of increase in X or Y
// First main part : calculate distance of ray from player to first grid intersection
// second main part : DDA 
// third part : calculate perp dist

void	init_ray_values(t_game *game, int x)
{
	double cameraX;

	cameraX = 2 * (x / (double)WIN_WIDTH) - 1; // -1 on the left and 1 on the right
	game->ray.rayDirX = game->player.dirX + (game->player.planeX * cameraX);
	game->ray.rayDirY = game->player.dirY + (game->player.planeY * cameraX);
	game->ray.deltaDistX = sqrt(1 + (game->ray.rayDirY * game->ray.rayDirY) / (game->ray.rayDirX * game->ray.rayDirX));
	game->ray.deltaDistY = sqrt(1 + (game->ray.rayDirX * game->ray.rayDirX) / (game->ray.rayDirY * game->ray.rayDirY));
	game->ray.mapX = game->player.curr_tileX;
	game->ray.mapY = game->player.curr_tileY;
}

void	calc_first_part_of_ray_distance(t_game *game)
{
	if (game->ray.rayDirX < 0)
	{
		game->ray.stepX = -1;
		game->ray.sideDistX = (game->player.posX - game->player.curr_tileX) * game->ray.deltaDistX;
	}
	else
	{
		game->ray.stepX = 1;
		game->ray.sideDistX = (TILE_SIZE - game->player.posX + game->player.curr_tileX) * game->ray.deltaDistX;
	}
	if (game->ray.rayDirY < 0)
	{
		game->ray.stepY = -1;
		game->ray.sideDistY = (game->player.posY - game->player.curr_tileY) * game->ray.deltaDistY;
	}
	else
	{
		game->ray.stepY = 1;
		game->ray.sideDistY = (TILE_SIZE - game->player.posY + game->player.curr_tileY) * game->ray.deltaDistY;
	}
}

//when u increase sideDistX ray will ALWAYSSSS hit the vertical side

void	DDA(t_game *game)
{
	while (1)
	{
		if (game->ray.sideDistX < game->ray.sideDistY)
		{
			game->ray.sideDistX += game->ray.deltaDistX;
			game->ray.mapX += game->ray.stepX;
			game->ray.hori_side_hit = 0;
		}
		else
		{
			game->ray.sideDistY += game->ray.deltaDistY;
			game->ray.mapY += game->ray.stepY;
			game->ray.hori_side_hit = 1;
		}
		if (game->map[game->ray.mapY][game->ray.mapX] == '1')
			break;
	}
}

void	calc_perp_dist(t_game *game)
{
	if (game->ray.hori_side_hit == 0)
	{
		if (game->ray.stepX == -1)
			game->ray.perp_wall_dist = (game->ray.mapX - game->player.posX + 1.0) / game->ray.rayDirX;
		else
			game->ray.perp_wall_dist = (game->ray.mapX - game->player.posX) / game->ray.rayDirX;
	}
	else
	{
		if (game->ray.stepY == -1)
			game->ray.perp_wall_dist = (game->ray.mapY - game->player.posY + 1.0) / game->ray.rayDirY;
		else
			game->ray.perp_wall_dist = (game->ray.mapY - game->player.posY) / game->ray.rayDirY;
	}
}
void	raycasting(t_game *game, int x)
{
	init_ray_values(game, x);
	calc_first_part_of_ray_distance(game);
	DDA(game);
	calc_perp_dist(game);
}
