/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:42:32 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/30 15:43:44 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (cheapest_node->above_median == 1
		&& cheapest_node->target_node->above_median == 1)
		rotate_both_500(a, b, cheapest_node);
	else if (cheapest_node->above_median == 0
		&& cheapest_node->target_node->above_median == 0)
		rev_rotate_both_500(a, b, cheapest_node);
	bring_node_to_top(b, cheapest_node, 'b');
	bring_node_to_top(a, cheapest_node->target_node, 'a');
	pa(a, b, 1);
}

void	move_a_to_b_500(t_stack_node **a, t_stack_node **b)
{
	int		len_to_push;
	int		mid;
	int		i;

	mid = stack_len(*a) / 2;
	len_to_push = stack_len(*a) - 3;
	i = 0;
	while (i < (len_to_push / 2))
	{
		if ((*a)->sorted_index < mid)
		{
			pb(a, b, 1);
			i++;
		}
		else
			ra(a, 1);
	}
	while (i++ < len_to_push)
		pb(a, b, 1);
}

void	move_b_to_a_500(t_stack_node **a, t_stack_node **b)
{
	int	len_to_push;

	len_to_push = stack_len(*b);
	while (len_to_push > 0)
	{
		current_index(a);
		current_index(b);
		set_target_b(*a, *b);
		push_costs_b(*a, *b);
		set_cheapest(*b);
		push_b_to_a(a, b);
		len_to_push--;
	}
}

void	rotate_both_500(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node
		&& *stack_b != cheapest_node)
		rr(stack_a, stack_b, 1);
	current_index(stack_a);
	current_index(stack_b);
}

void	rev_rotate_both_500(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node
		&& *stack_b != cheapest_node)
		rrr(stack_a, stack_b, 1);
	current_index(stack_a);
	current_index(stack_b);
}
