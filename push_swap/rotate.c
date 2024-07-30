/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:17:25 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/30 13:17:26 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	(*stack)->prev = last_node;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, int print)
{
	rotate(a);
	if (print == 1)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, int print)
{
	rotate(b);
	if (print == 1)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, int print)
{
	rotate(a);
	rotate(b);
	if (print == 1)
		ft_printf("rr\n");
}
