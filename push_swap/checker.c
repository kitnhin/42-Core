/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:54:03 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/30 15:26:08 by ethanlim         ###   ########.fr       */
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

void	do_commands(char *command, t_stack_node **a, t_stack_node **b)
{
	if (ft_strncmp(command, "sa\n", 3) == 0)
		sa(a, 0);
	else if (ft_strncmp(command, "sb\n", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(command, "ss\n", 3) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(command, "pa\n", 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(command, "pb\n", 3) == 0)
		pb(a, b, 0);
	else if (ft_strncmp(command, "ra\n", 3) == 0)
		ra(a, 0);
	else if (ft_strncmp(command, "rb\n", 3) == 0)
		rb(b, 0);
	else if (ft_strncmp(command, "rr\n", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(command, "rra\n", 4) == 0)
		rra(a, 0);
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp(command, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else
		print_error();
}

void	checker(t_stack_node **a, t_stack_node **b)
{
	char	*read;

	while (1)
	{
		read = get_next_line(0);
		if (read == NULL)
			break ;
		do_commands(read, a, b);
		free(read);
	}
	if (read)
		free(read);
	if (stack_sorted(*a) == 1)
		write(1, "OK\n", 3);
	else if (stack_sorted(*a) == 0)
		write(1, "KO\n", 3);
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
	checker(&a, &b);
	free_stack(&a);
	free(a);
	return (0);
}
