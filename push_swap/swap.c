/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:51:12 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/30 15:51:58 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **head)
{
	t_stack_node	*first_node;
	t_stack_node	*sec_node;

	if (!head || !(*head) || !(*head)->next)
		return ;
	first_node = *head;
	sec_node = (*head)->next;
	*head = sec_node;
	first_node->prev = sec_node;
	first_node->next = sec_node->next;
	if (sec_node->next)
		sec_node->next->prev = first_node;
	sec_node->prev = NULL;
	sec_node->next = first_node;
}

void	sa(t_stack_node **a, int print)
{
	swap(a);
	if (print == 1)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, int print)
{
	swap(b);
	if (print == 1)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node**b, int print)
{
	swap(a);
	swap(b);
	if (print == 1)
		ft_printf("ss\n");
}
