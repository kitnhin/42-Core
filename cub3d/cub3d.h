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


//structs
typedef struct s_textures
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		*floorcolor;
	int		*ceilingcolor;
}t_textures;

typedef struct s_game
{
	t_textures	textures;

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

typedef struct s_img
{
	//mlx ptr
	void	*mlx_ptr;

	// src info
	void	*src_img;
	int		src_width;
	int		src_height;
	int		*src_data;

	//dest data
	void	*dest_img;
	int		dest_width;
	int		dest_height;
	int		*dest_data;

	//not important lol just to save lines
	int		bitsperpixel;
	int		linesize;
	int		endian;
}	t_img;

//utils
void	print_2d_array(char **argv);
void	free_2d_array(char **arr);
int 	print_error(char *str);
int		get_map_height(char **map);

//parsing1
void	get_game_data(t_game *game);

//parsing_utils
void	print_textures(t_game *game);
int		get_map_height_for_malloc(t_game *game, int i);
char	**readfile(int fd);

//checkmap
int		check_map(t_game *game);

//img
void	img_main_control_function(t_game *game);
void	print_img(t_game *game, char *img_path, int width, int height);

#endif