/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:52:58 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/30 15:52:59 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node **stack)
{
	int				i;
	int				median;
	t_stack_node	*temp;

	i = 0;
	if (!stack)
		return ;
	temp = *stack;
	median = stack_len(*stack) / 2;
	while (temp)
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

int	stack_sorted(t_stack_node *stack)
{
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_node;

	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max_node = stack;
			max = stack->nbr;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min_node = stack;
			min = stack->nbr;
		}
		stack = stack->next;
	}
	return (min_node);
}
