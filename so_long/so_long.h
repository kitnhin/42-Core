#include "mlx.h"
#include <stdio.h>
#include "libft/libft.h"

# define up 65362
# define down 65364
# define left 65361
# define right 65363
# define esc 65307


typedef struct s_checks{
	int p_count;
	int e_count;
	int c_count;
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
} t_key;


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
} t_game;

void init_structs(t_wall *walls, t_key *keys, t_game *game);
char **readmap(int fd);
void	display_image(t_game *game, char *img_path, int x, int y);
void	put_top_walls(int x, char **map, t_wall *walls, int map_width);
void    put_mid_walls(t_game *game, t_wall *walls, int map_height, int map_width, t_key *keys);
void	make_map(void);
void	handle_image(t_wall *walls, t_game *game, int map_width, int map_height, t_key *keys);
void	print_player(t_game *game);
int		check_move_player(int keycode, t_game *game);
int		check_lines(char **map, int map_width, int map_height); 
int		height_map(char **map);
int check_map(char **map, int map_width, int map_height);
int width_map(char **map);
void	map_setup(t_game *game, int fd);

//player
int handle_keypress(int keycode, t_game *game);
int close_window(t_game *game);
void find_player_start(t_game *game);
void	move_player(int keycode, t_game *game);
int check_move_player(int keycode, t_game *game);
void	print_player(t_game *game);

// keys
int total_keys(char **map);

