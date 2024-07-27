#include "push_swap.h"

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node *push_node;

	if (!(*src))
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!(*dest))
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		(*dest)->prev = push_node;
		push_node->next = (*dest);
		*dest = push_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, int print)
{
	push(a, b);
	if (print == 1)
		ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b, int print)
{
	push(b, a);
	if (print == 1)
		ft_printf("pb\n");
}
