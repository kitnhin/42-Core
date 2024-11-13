#include "cub3d.h"


void	move_front(t_game *game)
{
	double	newPosX;
	double	newPosY;

	newPosX = game->player.posX + game->player.dirX * MOV_SPEED;
	newPosY = game->player.posY + game->player.dirY * MOV_SPEED;
	if (game->map[(int)newPosY][(int)newPosX] != '1')
	{
		game->player.posX = newPosX;
		game->player.posY = newPosY;
	}
}

void	move_back(t_game *game)
{
	double	newPosX;
	double	newPosY;

	newPosX = game->player.posX - game->player.dirX * MOV_SPEED;
	newPosY = game->player.posY - game->player.dirY * MOV_SPEED;
	if (game->map[(int)newPosY][(int)newPosX] != '1')
	{
		game->player.posX = newPosX;
		game->player.posY = newPosY;
	}
}

void	move_left(t_game *game)
{
	double	newPosX;
	double	newPosY;

	newPosX = game->player.posX + game->player.dirY * MOV_SPEED;
	newPosY = game->player.posY - game->player.dirX * MOV_SPEED;
	if (game->map[(int)newPosY][(int)newPosX] != '1')
	{
		game->player.posX = newPosX;
		game->player.posY = newPosY;
	}
}

void	move_right(t_game *game)
{
	double	newPosX;
	double	newPosY;

	newPosX = game->player.posX - game->player.dirY * MOV_SPEED;
	newPosY = game->player.posY + game->player.dirX * MOV_SPEED;
	if (game->map[(int)newPosY][(int)newPosX] != '1')
	{
		game->player.posX = newPosX;
		game->player.posY = newPosY;
	}
}