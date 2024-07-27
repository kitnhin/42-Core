#include "push_swap.h"

void	current_index(t_stack_node **stack)
{
	int	i;
	int	median;
	t_stack_node *temp;

	i = 0;
	if (!stack)
		return ;
	temp = *stack;
	median = stack_len(*stack) / 2;
	while(temp)
	{
		temp->index = i;
		if (i <= median)
			temp->above_median = 1;
		else
			temp->above_median = 0;
		temp = temp->next;
		i++;
	}
}
