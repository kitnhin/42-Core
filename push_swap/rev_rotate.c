#include "push_swap.h"

void	rev_rotate(t_stack_node **stack)
{
	t_stack_node *last_node;

	if (!stack || !(*stack)->next)
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
	// printf("stack_a -----------------\n");
	// print_stack(*a);
	// printf("stack_b -----------------\n");
	// print_stack(*b);
	if(print == 1)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, int print)
{
	rev_rotate(b);
	// printf("stack_a -----------------\n");
	// print_stack(*a);
	// printf("stack_b -----------------\n");
	// print_stack(*b);
	if(print == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, int print)
{
	rev_rotate(a);
	rev_rotate(b);
	if(print == 1)
		ft_printf("rrr\n");
}