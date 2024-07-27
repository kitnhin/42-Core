#include "push_swap.h"

void	rotate_both_100(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target_node)
		rr(stack_a, stack_b, 1);
	current_index(stack_a);
	current_index(stack_b);
}

void	rev_rotate_both_100(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target_node)
		rrr(stack_a, stack_b, 1);
	current_index(stack_a);
	current_index(stack_b);
}

void	move_a_to_b_100(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->above_median == 1 && cheapest_node->target_node->above_median == 1)
		rotate_both_100(a, b, cheapest_node);
	else if (cheapest_node->above_median == 0 && cheapest_node->target_node->above_median == 0)
		rev_rotate_both_100(a, b, cheapest_node);
	bring_node_to_top(a, cheapest_node, 'a');
	bring_node_to_top(b, cheapest_node->target_node, 'b');
	pb(a, b, 1);
}

void	move_b_to_a_100(t_stack_node **a, t_stack_node **b)
{
	bring_node_to_top(a, (*b)->target_node, 'a');
	pa(a, b, 1);
}

