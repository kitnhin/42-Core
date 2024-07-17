/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:50:26 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/17 21:20:30 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	locate_e(char **map, int *x, int *y)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map[row])
	{
		if (map[row][col] == 'E')
		{
			*x = col;
			*y = row;
		}
		if (map[row][col] == '\0')
		{
			row++;
			col = 0;
		}
		col++;
	}
}

void	check_sol(int *error, t_checks *game, int row, int col)
{
	if (row < 0 || col < 0 || row >= game->height_map || col >= game->width_map)
		return ;
	else if (game->map[row][col] != '0' && game->map[row][col] != 'C' &&
		game->map[row][col] != 'E' &&
			game->map[row][col] != 'P')
		return ;
	else if (game->map[row][col] == 'P')
	{
		*error = 1;
		return ;
	}
	game->map[row][col] = 'V';
	check_sol(error, game, row -1, col);
	check_sol(error, game, row +1, col);
	check_sol(error, game, row, col - 1);
	check_sol(error, game, row, col + 1);
}

char	**copy_map(char **map, int map_width, int map_height)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc(sizeof(char *) * map_height);
	while (i < map_height)
	{
		map_copy[i] = ft_substr(map[i], 0, map_width);
		i++;
	}
	return (map_copy);
}

int	check_map(char **map, int map_width, int map_height)
{
	int			error;
	int			col;
	int			row;
	int			i;
	t_checks	check;

	i = -1;
	error = 0;
	init_check(&check);
	check.map = copy_map(map, map_width, map_height);
	check.height_map = map_height;
	check.width_map = map_width;
	locate_e(map, &col, &row);
	check_sol(&error, &check, row, col);
	while (++i < map_height)
		free(check.map[i]);
	free(check.map);
	if (check_map_ply_col_exit(map, map_width, map_height) == 1
		&& check_bounds (map, map_width, map_height) == 1
		&& check_lines(map, map_width, map_height) == 1 && error == 1)
		return (1);
	else
		return (0);
}

int	check_map_ply_col_exit(char **map, int map_width, int map_height)
{
	int			i;
	int			j;
	t_checks	checks;

	i = 0;
	j = 0;
	init_check(&checks);
	while (j < map_height)
	{
		if (map[j][i] == 'P')
			checks.p_count++;
		if (map[j][i] == 'E')
			checks.e_count++;
		if (map[j][i] == 'C')
			checks.c_count++;
		if (i == map_width)
		{
			j++;
			i = 0;
		}
		i++;
	}
	if (checks.p_count == 1 && checks.e_count == 1 && checks.c_count > 0)
		return (1);
	return (0);
}

// char **readmap(int fd)
// {
// 	char **res;
// 	int j = 0;
// 	res = (char **)malloc(sizeof(char *) * 100); 
// 	while ((res[j] = get_next_line(fd)) != NULL)
// 		j++;
// 	if (res[0] == NULL)
// 	{
// 		ft_printf("file contains nth bruh\n");
// 		free(res);
// 		exit(1);
// 	}
// 	res[j] = NULL; 
// 	return res;
// }
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	t_checks checks;
// 	init_check(&checks);
// 	int fd = open("./maps/map1.ber", O_RDWR);
// 	int fd1 = open("./maps/no_wall.ber", O_RDWR);
// 	int fd2 = open("./maps/no_player.ber", O_RDWR);
// 	int fd3 = open("./maps/no_exit.ber", O_RDWR);
// 	int fd4 = open("./maps/no_key.ber", O_RDWR);
// 	int fd5 = open("./maps/more_player.ber", O_RDWR);
// 	int fd6 = open("./maps/diff_size.ber", O_RDWR);
// 	char **map = readmap(fd);
// 	char **map1 = readmap(fd1);
// 	char **map2 = readmap(fd2);
// 	char **map3 = readmap(fd3);
// 	char **map4 = readmap(fd4);
// 	char **map5 = readmap(fd5);
// 	char **map6 = readmap(fd6);
// 	// char **map7 = readmap(fd7);
// 	// char **map8 = readmap(fd8);
// 	int a = check_map(map, width_map(map), height_map(map));
// 	int b = check_map(map1, width_map(map1), height_map(map1));
// 	int c = check_map(map2, width_map(map2), height_map(map2));
// 	int d = check_map(map3, width_map(map3), height_map(map3));
// 	int e = check_map(map4, width_map(map4), height_map(map4));
// 	int f = check_map(map5, width_map(map5), height_map(map5));
// 	int g = check_map(map6, width_map(map6), height_map(map6));
// 	// int h = check_map(map7, width_map(map7), height_map(map7));
// 	// int i = check_map(map8, width_map(map8), height_map(map8));
// 	printf("error map0 = %d\n", a);
// 	printf("error map1 = %d\n", b);
// 	printf("error map2 = %d\n", c);
// 	printf("error map3 = %d\n", d);
// 	printf("error map4 = %d\n", e);
// 	printf("error map5 = %d\n", f);
// 	printf("error map6 = %d\n", g);
// 	// printf("error map7 = %d\n", h);
// 	// printf("error map8 = %d\n", i);
// 	return (0);
// }