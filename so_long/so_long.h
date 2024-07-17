#include "mlx.h"
#include <stdio.h>
#include "libft/libft.h"
// #include <mlx.h>

# define up 65362
# define down 65364
# define left 65361
# define right 65363
# define esc 65307
# define wKey 119
# define aKey 97
# define sKey 115
# define dKey 100

// # define up 126
// # define down 125
// # define left 123
// # define right 124
// # define esc 53
// # define wKey 13
// # define aKey 0
// # define sKey 1
// # define dKey 2

typedef struct s_checks{
	int p_count;
	int e_count;
	int c_count;
	char **map;
	int width_map;
	int height_map;
}	t_checks;

typedef struct s_wall{
	char *top_left_wall;
	char *up_wall;
	char *down_wall;
	char *right_wall;
	char *up_left_wall;
	char *up_right_wall;
	char *left_wall;
	char *floor;
	char *cross_wall;
	char *down_left_wall;
	char *down_right_wall;
	char *exit;
}	t_wall;

typedef struct s_key{
	char *addr;
	int x;
	int y;
} t_key;

typedef struct s_bat{
	char *addr;
	int	x;
	int	y;
}t_bat;

typedef struct s_game{
	char **map;
	int map_width;
	int map_height;
	char *player_addr;
	int player_pos_x;
	int player_pos_y;
	void *mlx;
	void *window;
	int steps;
	int total_keys;
	int key_count;
	int exit_posx;
	int exit_posy;
	int total_bats;
	int frames;
} t_game;

// main
void	display_image(t_game *game, char *img_path, int x, int y);
int	close_window(t_game *game);

//make_map
char **readmap(int fd);
void	put_top_walls(int x, char **map, t_wall *walls, int map_width);
void    put_mid_walls(t_game *game, t_wall *walls, int map_height, int map_width);
void	make_map(void);
void	handle_image(t_game *game);
void	put_others(char c, int x, int y, t_game *game);

//check_map
void	init_check(t_checks *checks);
int width_map(char **map);
int		height_map(char **map);
int	check_bounds(char **map, int map_width, int map_height);
int		check_lines(char **map, int map_width, int map_height);
int	check_map_ply_col_exit(char **map, int map_width, int map_height);

//check_map2
int check_map(char **map, int map_width, int map_height);
void	map_setup(t_game *game, char *file);
void locate_e(char **map, int *x, int *y);

//player
int handle_keypress(int keycode, t_game *game);
void find_player_start(t_game *game);
void	move_player(int keycode, t_game *game);
int check_move_player(int keycode, t_game *game);
void	print_player(t_game *game);

// keys
int total_keys(char **map);
void	print_key(t_game *game);
t_key	*find_key(t_game *game, t_key *keys, int x, int y);

//bat
void	print_bat(t_game *game);
int total_bats(char **map);
void	move_bat_left(t_game *game);
void	move_bat_right(t_game *game);

//animation
int ft_animate(t_game *game);
void char_anim(t_game *game);
void key_anim(t_game *game, t_key *keys);
void bat_anim(t_game *game, int x, int y);
// int	move_bat(t_game *game);

//inits
void init_walls(t_wall *walls);
void init_structs(t_wall *walls, t_key *keys, t_game *game);

