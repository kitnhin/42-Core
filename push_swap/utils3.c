#include "push_swap.h"

t_stack_node	*find_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if(stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	bring_min_top(t_stack_node **stack)
{
	t_stack_node	*smallest_node;
	int	smallest_nbr;

	smallest_node = find_min(*stack);
	smallest_nbr = smallest_node->nbr;
	while ((*stack)->nbr != smallest_nbr)
	{
		if (smallest_node->above_median == 1)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
}