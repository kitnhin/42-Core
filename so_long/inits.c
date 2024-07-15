#include "so_long.h"

void init_structs(t_wall *walls, t_key *keys, t_game *game)
{
    walls->top_left_wall = "./textures/walls/top_left_wall.xpm";
    walls->up_wall = "./textures/walls/up_wall.xpm";
    walls->down_wall = "./textures/walls/down_wall.xpm";
    walls->right_wall = "./textures/walls/right_wall.xpm";
    walls->up_left_wall = "./textures/walls/up_left_wall.xpm";
    walls->up_right_wall = "./textures/walls/up_right_wall.xpm";
    walls->left_wall = "./textures/walls/left_wall.xpm";
    walls->floor = "./textures/floors/floor.xpm";
    walls->cross_wall = "./textures/walls/cross_wall.xpm";
    walls->down_left_wall = "./textures/walls/down_left_wall.xpm";
    walls->down_right_wall = "./textures/walls/down_right_wall.xpm";
	walls->exit = "./textures/walls/exit.xpm";
	keys->addr ="./textures/others/Key.xpm";
	game->player_addr = "./textures/others/Player_v2.xpm";
	game->player_pos_x = 0;
	game->player_pos_y = 0;
	game->map = NULL;
	game->steps = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->key_count = 0;
	game->total_keys = 0;
	game->exit_posx = 0;
	game->exit_posy = 0;
	game->total_bats = 0;
}


void init_walls(t_wall *walls)
{
    walls->top_left_wall = "./textures/walls/top_left_wall.xpm";
    walls->up_wall = "./textures/walls/up_wall.xpm";
    walls->down_wall = "./textures/walls/down_wall.xpm";
    walls->right_wall = "./textures/walls/right_wall.xpm";
    walls->up_left_wall = "./textures/walls/up_left_wall.xpm";
    walls->up_right_wall = "./textures/walls/up_right_wall.xpm";
    walls->left_wall = "./textures/walls/left_wall.xpm";
    walls->floor = "./textures/floors/floor.xpm";
    walls->cross_wall = "./textures/walls/cross_wall.xpm";
    walls->down_left_wall = "./textures/walls/down_left_wall.xpm";
    walls->down_right_wall = "./textures/walls/down_right_wall.xpm";
	walls->exit = "./textures/walls/exit.xpm";
}
