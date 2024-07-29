#include "push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*biggest_node;
	biggest_node = find_max(*stack);
	if (*stack == biggest_node)
		ra(stack, 1);
	else if((*stack)->next == biggest_node)
		rra(stack, 1);
	if((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, 1);
}

void	sort_stacks_500(t_stack_node **a, t_stack_node **b)
{
	init_sorted_index(a);
	move_a_to_b_500(a, b);
	sort_three(a);
	move_b_to_a_500(a, b);
	bring_min_top(a);
}

void	sort_stacks_100(t_stack_node **a, t_stack_node **b)
{
	int	stack_len_a;

	stack_len_a = stack_len(*a);
	if (stack_len_a-- > 3 && stack_sorted(*a) == 0)
		pb(a , b, 1);
	if (stack_len_a-- > 3 && stack_sorted(*a) == 0)
		pb(a, b, 1);
	while (stack_len_a-- > 3 && stack_sorted(*a) == 0)
	{
		init_nodes_a(*a, *b);
		move_a_to_b_100(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a_100(a, b);
	}
	bring_min_top(a);
}