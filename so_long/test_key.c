/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:51:07 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/17 20:51:20 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "mlx.h"
// #include <stdio.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	key_hook(int keycode, t_vars *vars)
// {
// 	printf("Key press: %d\n", keycode);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");

// 	mlx_key_hook(vars.win, key_hook, &vars);

// 	mlx_loop(vars.mlx);
// 	return (0);
// }