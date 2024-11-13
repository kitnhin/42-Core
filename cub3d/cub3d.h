#ifndef CUB3D_H
#define CUB3D_H

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "libft/libft.h"

//Definition
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define WKEY 119
# define AKEY 97
# define SKEY 115
# define DKEY 100


#define WIN_HEIGHT 1000
#define WIN_WIDTH 1000

#define PI 3.141592653589793238462643383279502884197
#define TILE_SIZE 1
#define MOV_SPEED 0.2
#define ROT_SPEED 4

//structs

typedef struct s_ray
{
	double	angle;
	double	rayDirX;
    double	rayDirY;
	double	deltaDistX;
    double	deltaDistY;
	int		stepX;
	int		stepY;
	int		hitflag;
	int		verti_side_hit;
	double	perp_wall_dist;
	double	sideDistX;
	double	sideDistY;
	int		mapX;
	int		mapY;
	double	drawstart;
	double	drawend;
}	t_ray;

typedef struct s_textures
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		*floorcolor;
	int		*ceilingcolor;
}t_textures;

typedef struct s_player
{
	double	posX;
	double	posY;
	int		curr_tileX;
	int		curr_tileY;
	double	curr_dir;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}	t_player;

typedef struct s_img
{
	//mlx ptr
	void	*mlx_ptr;

	// img info
	void	*img_ptr;
	int		img_width;
	int		img_height;
	int		*img_data;

	//not important lol just to save lines
	int		bitsperpixel;
	int		linesize;
	int		endian;
}	t_img;

typedef struct s_game
{
	t_textures	textures;
	t_player	player;
	t_img		screen;
	t_ray		ray;

	char		**filedata;
	char		**map;
	void		*mlx;
	void		*window;
	
}	t_game;

typedef struct s_mapchecks
{
	char	**map;
	int		check;
}	t_mapchecks;

//utils
void	print_2d_array(char **argv);
void	free_2d_array(char **arr);
int 	print_error(char *str);
int		get_map_height(char **map);
void	ft_exit();
double	rad_to_deg(double rad);
double	deg_to_rad(double deg);
double	normalise_angle(double degree);

//parsing1
void	get_game_data(t_game *game);

//parsing_utils
int		get_map_height_for_malloc(t_game *game, int i);
char	**readfile(int fd);
int		count_2d_arr(char **arr);

//checkmap
int		check_map(t_game *game);

//img
int		img_main_control_function(t_game *game);
void	print_img(t_game *game, char *img_path, int width, int height);

//background
void	draw_floor(t_game *game);
void	draw_ceiling(t_game *game);

//player1
int		locate_player_row(char **map);
int		locate_player_col(char **map);
void	init_player_struct(t_game* game, t_player *player);
void	rotate_player(t_game *game, int key);
void	move_player(t_game *game, int key);

//print
void	print_player_stats(t_player *player);
void	print_textures(t_game *game);

//raycast
int			render_screen(t_game *game);

//movement
void		move_front(t_game *game);
void		move_back(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);

#endif