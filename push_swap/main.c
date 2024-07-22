#include "push_swap.h"

void print_stack(t_stack_node *stack)
{
    if (!stack)
	{
		printf("NULL\n");
		return ;
	}
	while (stack) 
	{
        printf("value at node = %d\n", stack->nbr);
        stack = stack->next;
    }
}

void print_index(t_stack_node *stack)
{
    if (!stack)
	{
		printf("NULL\n");
		return ;
	}
	while (stack) 
	{
        printf("index at node = %d\n", stack->index);
        stack = stack->next;
    }
}
void print_median(t_stack_node *stack)
{
    if (!stack)
	{
		printf("NULL\n");
		return ;
	}
	while (stack) 
	{
        printf("median at node = %d\n", stack->above_median);
        stack = stack->next;
    }
}

void print_target(t_stack_node *stack)
{
    if (!stack)
	{
		printf("NULL\n");
		return ;
	}
	while (stack) 
	{
        printf("value at target node = %d\n", stack->target_node->nbr);
        stack = stack->next;
    }
}


void print_push_cost(t_stack_node *stack)
{
    if (!stack)
	{
		printf("NULL\n");
		return ;
	}
	while (stack) 
	{
        printf("push cost at node = %d\n", stack->push_cost);
        stack = stack->next;
    }
}

void print_cheapest(t_stack_node *stack)
{
    if (!stack)
	{
		printf("NULL\n");
		return ;
	}
	while (stack) 
	{
        printf("cheapest value = %d\n", stack->cheapest);
        stack = stack->next;
    }
}

int main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
	{
		ft_printf("Error/n");
		return 1;
	}
	if (argc == 2)
		argv = ft_split_special(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	print_stack(a);
	printf("----------------------------------\n");
	if(!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 1);
		if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	printf("----------------------------------\n");
	print_stack(a);
	return (0);
}
