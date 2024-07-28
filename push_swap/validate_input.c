#include "push_swap.h"

int check_dup(char **argv)
{
	int i;
	int j;
	long	a;
	long	b;

	i = 0;
	j = 0;
	while (argv[i])
	{
		j = i;
		while(argv[j])
		{
			a = atol(argv[i]);
			b = atol(argv[j]);
			if(a == b)
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

int check_nums(char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if(argv[i][j] < '0' && argv[i][j] > '9')
		{
			// printf("%c\n", argv[i][j]);
			return 0;
		}
		j++;
		if (argv[i][j] == '\0')
		{
			i++;
			j = 0;
		}
	}
	return 1;
}


void	validate_input(char **argv)
{
	int check1;
	int check2;

	check1 = check_nums(argv);
	// check2 = check_dup(argv);

	// printf("%d, %d\n", check1, check2);
	if(check1 == 0)
	{
		ft_printf("Error\n");
		// free_array(argv);
		exit(1);
	}
}



