#include "cub3d.h"

//calculates where the ray hits on the wall so we know how to print it
//line 1 - 4 calculates where the ray hits in EXACT coordinates
//line 5 calculates the PERCENTAGE of the wall we wanna print
//Example:
//wallX = 3.75
//floor(wallX) = 3;
//wallX = 0.75, this means the ray hit the wall at 75% along the wall
//line 6 times the wall width to get the actual wall coordinates we have to print

void	calc_tex(t_game *game)
{
	double wallX;

    if (game->ray.verti_side_hit == 0)
        wallX = game->player.posY + game->ray.perp_wall_dist * game->ray.rayDirY;
    else
        wallX = game->player.posX + game->ray.perp_wall_dist * game->ray.rayDirX;
    wallX -= floor(wallX);

	game->ray.texX = (int)(wallX * game->n_tex.img_width);
	// if (game->ray.verti_side_hit == 0 && game->ray.rayDirX > 0)
    //     game->ray.texX = game->n_tex.img_width - game->ray.texX - 1;
    // if (game->ray.verti_side_hit == 1 && game->ray.rayDirY < 0)
    //     game->ray.texX = game->n_tex.img_width - game->ray.texX - 1;
}

void	calc_draw_values(t_game *game)
{
	game->draw.line_height = (int)(WIN_HEIGHT / game->ray.perp_wall_dist);
	game->draw.draw_start = (WIN_HEIGHT / 2) - (game->draw.line_height / 2);
    if (game->draw.draw_start < 0)
		game->draw.draw_start = 0.00001;
	game->draw.draw_end = (WIN_HEIGHT / 2) + (game->draw.line_height / 2);
    if (game->draw.draw_end >= WIN_HEIGHT)
		game->draw.draw_end = WIN_HEIGHT - 1;
}

// line 2: get how much we shud increment the index which iterates thru the image data after we draw one pixel
// line 3: gets the starting index which is used to interate thru the image data (most of the time gonna be 0 unless our image is bigger than the screen)
// line 5: get the color of the pixel (modulus so instead of stretching we can print each tile repeatedly)
// line 6: put the color in the screen data
void	actually_drawing(t_game *game, int x)
{
	int	y;

	y = game->draw.draw_start - 1;
	game->draw.step = (double)game->n_tex.img_height / game->draw.line_height;
	game->draw.tex_pos = (game->draw.draw_start - WIN_HEIGHT / 2 + game->draw.line_height / 2) * game->draw.step;
	while(++y < game->draw.draw_end)
	{
		game->draw.color = game->n_tex.img_data[game->n_tex.img_height * (int)game->draw.tex_pos + (game->ray.texX % game->n_tex.img_width)];
		game->screen.img_data[y * WIN_WIDTH + x] = game->draw.color;
		game->draw.tex_pos += game->draw.step;
	}
}
void	draw_line(t_game *game, int x)
{
	calc_draw_values(game);
	calc_tex(game);
	actually_drawing(game, x);
}
