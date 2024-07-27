#include "push_swap.h"

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		append_node(a, (int)n);
		i++;
	}
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(&a);
	current_index(&b);
	set_target_a(a, b);
	push_costs_a(a, b);
	set_cheapest(a);
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(&a);
	current_index(&b);
	set_target_b(a, b);
}
