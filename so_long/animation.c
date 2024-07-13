#include "so_long.h"
#include "mlx.h"

int ft_animate(t_game *game)
{
	int	a;

	a = 0;
	char_anim(game);
	print_key(game);
	print_bat(game);
	while (a < 130000000)
		a++;
	a = 0;
	return 0;
}

void char_anim(t_game *game)
{
	static int i = 0;
	 int j = 0;
	 int a = 0;
	 char *path;

	char **frames = (char **)malloc(8 * sizeof(char *));
    frames[0] = "./textures/player/player.xpm";
    frames[1] = "./textures/player/player3.xpm";
    frames[2] = "./textures/player/player2.xpm";
    frames[3] = "./textures/player/player3.xpm";
    frames[4] = "./textures/player/player.xpm";
	frames[5] = "./textures/player/player5.xpm";
	frames[6] = "./textures/player/player4.xpm";
	frames[7] = "./textures/player/player5.xpm";

	path = frames[i];
	// while (a < 130000000)
	// 	a++;
	// a = 0;
	display_image(game, path, game->player_pos_x * 100 , game->player_pos_y * 100);
	i = (i + 1)% 8;
}

void key_anim(t_game *game, t_key *keys)
{
	static int i = 0;
	 int j = 0;
	 int a = 0;
	 char *path;

	char **frames = (char **)malloc(6 * sizeof(char *));
    frames[0] = "./textures/keys/key1.xpm";
    frames[1] = "./textures/keys/key2.xpm";
    frames[2] = "./textures/keys/key3.xpm";
    frames[3] = "./textures/keys/key4.xpm";
    frames[4] = "./textures/keys/key5.xpm";
	frames[5] = "./textures/keys/key6.xpm";

	path = frames[i];
	while(j < game->total_keys)
	{
		display_image(game, path, keys[j].x * 100 , keys[j].y * 100);
		j++;
	}
	i = (i + 1)% 6;
	// while (a < 13000000)
	// 	a++;
	a = 0;
}

void bat_anim(t_game *game, t_bat *bat)
{
	static int i = 0;
	 int j = 0;
	 int a = 0;
	 char *path;

	char **frames = (char **)malloc(6 * sizeof(char *));
    frames[0] = "./textures/bats/bat1.xpm";
    frames[1] = "./textures/bats/bat2.xpm";
    frames[2] = "./textures/bats/bat3.xpm";
    frames[3] = "./textures/bats/bat4.xpm";
    frames[4] = "./textures/bats/bat3.xpm";
	frames[5] = "./textures/bats/bat2.xpm";

	path = frames[i];
	while(j < game->total_bats)
	{
		if(game->map[bat[j].y + 1][bat[j].x + 1] == '0')
		display_image(game, path, bat[j].x * 100 , bat[j].y * 100);
		j++;
	}
	i = (i + 1)% 6;
	// while (a < 13000000)
	// 	a++;
	a = 0;
}



