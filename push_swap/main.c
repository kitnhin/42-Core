#include "push_swap.h"

void	validate_input(char **argv, int argc)
{
	int		i;
	char	**input;

	i = 0;
	if (argv[0][0] == '\0')
		print_error();
	if (argc == 2)
		input = ft_split_special(argv[0], ' ');
	else
		input = argv;
	while (i < argc - 1)
	{
		if (check_nums(input[i]) == 0 || check_sign(input[i]) == 0
			|| check_int(input[i]) == 0)
			print_error();
		i++;
	}
	if (check_dup(input) == 0)
		print_error();
	if (argc == 2)
		free_array(input);
}

int main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;
	char **res;

	a = NULL;
	b = NULL;
	validate_input(argv + 1, argc);
	if (argc < 2)
	{
		write(2,"Error\n",6);
		return 1;
	}
	if (argc == 2)
	{
		res = ft_split_special(argv[1], ' ');
		init_stack_a(&a, res);
		free_array(res);
	}
	else
	{
		init_stack_a(&a, argv + 1);
	}
	if(!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 1);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else if (stack_len(a) > 100 && stack_len(a) <= 501)
			sort_stacks_500(&a, &b);
		else
			sort_stacks_100(&a, &b);
	}
	free_stack(&a);
	free(a);
	return (0);
}
