#include "push_swap.h"

// void	refresh_index(t_stack_node **stack)
// {
// 	while(*stack)
// 	{
// 		current_index(*stack);
// 		*stack = (*stack)->next;
// 	}
// }

void	rotate_both(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
		rr(stack_a, stack_b, 1);
	current_index(stack_a);
	current_index(stack_b);
}

void	rev_rotate_both(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
		rrr(stack_a, stack_b, 1);
	current_index(stack_a);
	current_index(stack_b);
}

void	bring_node_to_top(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median == 1)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median == 1)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

void	push_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (cheapest_node->above_median == 1 && cheapest_node->target_node->above_median == 1)
		rotate_both(a, b, cheapest_node);
	else if (cheapest_node->above_median == 0 && cheapest_node->target_node->above_median == 0)
		rev_rotate_both(a, b, cheapest_node);
	bring_node_to_top(b, cheapest_node, 'b');
	bring_node_to_top(a, cheapest_node->target_node, 'a');
	pa(a, b, 1);
}
void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;
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

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	int len_to_push = stack_len(*b);
	while(len_to_push > 0)
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
