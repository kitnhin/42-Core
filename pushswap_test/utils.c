#include "push_swap.h"

t_stack_node	*find_last(t_stack_node *stack)
{
	if(!stack)
		return NULL;
	while(stack->next)
		stack = stack->next;
	return stack;
}

int	whitespace(char *str)
{
	int	i;

	i = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	return (i);
}

long	ft_atol(char *str)
{
	int	sign;
	long	res;
	int	i;

	sign = 1;
	res = 0;
	i = whitespace(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*newnode;
	t_stack_node	*last_node;

	if(!stack)
		return ;
	newnode =(t_stack_node *)malloc(sizeof(t_stack_node));
	if(!newnode)
		return ;
	newnode->next = NULL;
	newnode->nbr = n;
	if(!(*stack))
	{
		*stack = newnode;
		newnode->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = newnode;
		newnode->prev = last_node;
	}
}

int	stack_len(t_stack_node *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return 0;
	while(stack)
	{
		stack = stack->next;
		count++;
	}
	return count;
}

int	stack_sorted(t_stack_node *stack)
{
	while(stack->next)
	{
		if(stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack_node *find_max(t_stack_node *stack)
{
	long	max;
	t_stack_node	*max_node;

	max = LONG_MIN;
	while(stack)
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

t_stack_node *find_min(t_stack_node *stack)
{
	long	min;
	t_stack_node	*min_node;

	min = LONG_MAX;
	while(stack)
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