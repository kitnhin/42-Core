/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:11:06 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/30 13:12:39 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!(*stack) || !stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	(*stack)->prev = last_node;
	*stack = last_node;
}

void	rra(t_stack_node **a, int print)
{
	rev_rotate(a);
	if (print == 1)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, int print)
{
	rev_rotate(b);
	if (print == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, int print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (print == 1)
		ft_printf("rrr\n");
}
