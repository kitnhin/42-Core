#include "push_swap.h"

int compare(char *str1, char *str2)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i] == '0')
		i++;
	while (str2[j] == '0')
		j++;
	while (str1[i] && str2[j] && str1[i] == str2[j])
	{
		i++;
		j++;
	}
	if(str1[i] == '\0' && str2[j] == '\0')
		return 0;
	return 1;
}

int	check_int(char *str)
{
	long	n;

	n = atol(str);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	else
		return (1);
}

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
		j = i + 1;
		while(argv[j])
		{
			a = atol(argv[i]);
			b = atol(argv[j]);
			if (a == b)
				return 0;
			else
				j++;
		}
		i++;
	}
	return 1;
}

int	check_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i != 0 && (str[i] == '-' || str[i] == '+'))
			return (0);
		if (i == 0 && (str[i] == '-' || str[i] == '+') && str[i + 1] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int check_nums(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if(str[i] >= '0' && str[i] <= '9' || str[i] == '+' || str[i] == '-')
			i++;
		else
			return 0;
	}
	return 1;
}

char **copy_array(char **argv, int argc)
{
	char **dest;
	int	i;

	i = 0;
	dest = (char **)malloc(sizeof(char *) * argc);
	while(i < argc - 1)
	{
		dest[i] = ft_strdup(argv[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
void	print_2d_array(char **str)
{
	int i = 0;

	while(str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	validate_input(char **argv, int argc)
{
	int i;
	char **input;

	i = 0;
	// print_2d_array(input);
	if (argv[0][0] == '\0')
		print_error();
	if (argc == 2)
		input = ft_split_special(argv[0], ' ');
	else
		input = argv;
	while(i < argc - 1)
	{
		// printf("%d\n", check_nums(input[i]));
		if (check_nums(input[i]) == 0 || check_sign(input[i]) == 0
			|| check_int(input[i]) == 0)
			print_error();
		i++;
	}
	// printf("%d\n", check_dup(argv));
	if (check_dup(input) == 0)
		print_error();
	if(argc == 2)
		free_array(input);
}



