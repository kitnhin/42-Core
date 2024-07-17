/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:31:07 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/17 22:30:07 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdio.h>
# include "libft/libft.h"
// #include <mlx.h>

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define WKEY 119
# define AKEY 97
# define SKEY 115
# define DKEY 100

// # define UP 126
// # define DOWN 125
// # define LEFT 123
// # define RIGHT 124
// # define ESC 53
// # define WKEY 13
// # define AKEY 0
// # define SKEY 1
// # define DKEY 2

typedef struct s_checks
{
	int		p_count;
	int		e_count;
	int		c_count;
	char	**map;
	int		width_map;
	int		height_map;
}	t_checks;

typedef struct s_wall
{
	char	*top_left_wall;
	char	*up_wall;
	char	*down_wall;
	char	*right_wall;
	char	*up_left_wall;
	char	*up_right_wall;
	char	*left_wall;
	char	*floor;
	char	*cross_wall;
	char	*down_left_wall;
	char	*down_right_wall;
	char	*exit;
}	t_wall;

typedef struct s_key
{
	char	*addr;
	int		x;
	int		y;
}	t_key;

typedef struct s_bat
{
	char	*addr;
	int		x;
	int		y;
}	t_bat;

typedef struct s_game
{
	char	**map;
	int		map_width;
	int		map_height;
	char	*player_addr;
	int		player_pos_x;
	int		player_pos_y;
	void	*mlx;
	void	*window;
	int		steps;
	int		total_keys;
	int		key_count;
	int		exit_posx;
	int		exit_posy;
	int		total_bats;
	int		frames;
}	t_game;

// main
void	map_setup(t_game *game, char *file);
void	display_image(t_game *game, char *img_path, int x, int y);
int		close_window(t_game *game);
int		handle_keypress(int keycode, t_game *game);

//make_map
char	**readmap(int fd);
void	put_top_bottom_walls(int y, t_game *game, t_wall *walls, int map_width);
void	put_mid_walls(t_game *game, t_wall *walls, int map_height,
			int map_width);
void	handle_image(t_game *game);
void	put_others(char c, int x, int y, t_game *game);

//check_map
void	init_check(t_checks *checks);
int		width_map(char **map);
int		height_map(char **map);
int		check_bounds(char **map, int map_width, int map_height);
int		check_lines(char **map, int map_width, int map_height);

//check_map2
int		check_map(char **map, int map_width, int map_height);
void	map_setup(t_game *game, char *file);
void	locate_e(char **map, int *x, int *y);
int		check_map_ply_col_exit(char **map, int map_width, int map_height);
void	check_sol(int *error, t_checks *game, int row, int col);

//player
void	find_player_start(t_game *game);
void	print_steps(t_game *game);
void	move_player(int keycode, t_game *game);
void	move_player_ver(int keycode, t_game *game);
void	move_player_hori(int keycode, t_game *game);

//player2
int		check_move_player(int keycode, t_game *game);
int		check_move(t_game *game, int x, int y);

// keys
void	init_key_struct(t_key *key);
int		total_keys(char **map);
void	print_key(t_game *game);
t_key	*find_key(t_game *game, t_key *keys, int x, int y);

//bat
void	print_bat(t_game *game);
int		total_bats(char **map);

//animation
int		ft_animate(t_game *game);
void	char_anim(t_game *game);
void	key_anim(t_game *game, t_key *keys);
void	bat_anim(t_game *game, int x, int y);

//inits
void	init_walls(t_wall *walls);
void	init_structs(t_wall *walls, t_key *keys, t_game *game);
#endif