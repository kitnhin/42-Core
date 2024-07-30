/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:00:28 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/30 12:19:17 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		append_node(a, (int)n);
		i++;
	}
}

// sort 100 functions
void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(&a);
	current_index(&b);
	set_target_a(a, b);
	push_costs_a(a, b);
	set_cheapest(a);
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(&a);
	current_index(&b);
	set_target_b(a, b);
}
