/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:09:05 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/30 15:37:55 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_input(char **argv, int argc)
{
	int		i;
	char	**input;

	i = 0;
	if (argv[0][0] == '\0')
		print_error();
	if (argc == 2)
		input = ft_split(argv[0], ' ');
	else
		input = argv;
	while (i < argc - 1)
	{
		if (check_nums(input[i]) == 0 || check_sign(input[i]) == 0
			|| check_int(input[i]) == 0)
			print_error();
		i++;
	}
	if (check_dup(input) == 0)
		print_error();
	if (argc == 2)
		free_array(input);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**res;

	a = NULL;
	b = NULL;
	validate_input(argv + 1, argc);
	if (argc < 2)
		print_error();
	if (argc == 2)
	{
		res = ft_split(argv[1], ' ');
		init_stack_a(&a, res);
		free_array(res);
	}
	else
		init_stack_a(&a, argv + 1);
	sort(&a, &b);
	free_stack(&a);
	free(a);
	return (0);
}
