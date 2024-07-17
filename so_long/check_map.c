/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:24:10 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/17 21:24:10 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_check(t_checks *checks)
{
	checks->c_count = 0;
	checks->e_count = 0;
	checks->p_count = 0;
	checks->map = NULL;
	checks->height_map = 0;
	checks->width_map = 0;
}

int	width_map(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0' && map[0][i] != '\n')
		i++;
	return (i);
}

int	height_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

int	check_bounds(char **map, int map_width, int map_height)
{
	int	i;

	i = -1;
	while (++i < map_width - 1)
		if (map[0][i] != '1')
			return (0);
	i = -1;
	while (++i < map_height)
		if (map[i][0] != '1')
			return (0);
	i = -1;
	while (++i < map_width - 1)
		if (map[map_height - 1][i] != '1')
			return (0);
	i = -1;
	while (++i < map_height)
		if (map[i][map_width - 1] != '1')
			return (0);
	return (1);
}

int	check_lines(char **map, int map_width, int map_height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map_height)
	{
		while (map[j][i] && map[j][i] != '\n')
			i++;
		if (i != map_width)
			return (0);
		i = 0;
		j++;
	}
	return (1);
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
