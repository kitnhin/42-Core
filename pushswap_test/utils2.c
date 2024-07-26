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

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	long	current_target_value;
	t_stack_node	*node_b;
	t_stack_node	*current_target_node;

	while (a)
	{
		current_target_value = LONG_MIN;
		node_b = b;
		while (node_b)
		{
			if (node_b->nbr > current_target_value && node_b->nbr < a->nbr)
			{
				current_target_value = node_b->nbr;
				current_target_node = node_b;
			}
			node_b = node_b->next;
		}
		if (current_target_value == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = current_target_node;
		a = a->next;
	}
}

void	push_costs_b(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		if (b->above_median == 1)
			b->push_cost = b->index;
		else
			b->push_cost = len_b - b->index;
		if (b->target_node->above_median == 1)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += len_a - b->target_node->index;
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	t_stack_node *cheapest_node;
	t_stack_node *tempstack;
	long	cheapest_value;

	tempstack = stack;
	cheapest_value = LONG_MAX;
	while (tempstack)
	{
		tempstack->cheapest = 0;
		tempstack = tempstack->next;
	}
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	long	current_target_value;
	t_stack_node	*node_a;
	t_stack_node	*current_target_node;

	while (b)
	{
		current_target_value = LONG_MAX;
		node_a = a;
		while (node_a)
		{
			if (node_a->nbr < current_target_value && b->nbr < node_a->nbr)
			{
				current_target_value = node_a->nbr;
				current_target_node = node_a;
			}
			node_a = node_a->next;
		}
		if (current_target_value == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = current_target_node;
		b = b->next;
	}
}