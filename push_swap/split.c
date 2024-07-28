#include "push_swap.h"

int	count_strings(char const *s, char c)
{
	int	i;
	int	count;

	count = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (s[i + 1] != c)
				count++;
		}
		i++;
	}
	if (s[0] == c)
		count--;
	if (s[i - 1] == c)
		count--;
	return (count);
}


char	**ft_split_special(char const *s, char c)
{
	char	**str;
	size_t	i;
	int		j;
	int 	start;
	int 	end;

	i = 0;
	j = 0;
	start = 0;
	end = 0;
	if (!s)
		return (NULL);
	str = malloc (sizeof(char *) * (count_strings(s, c) + 2));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		end = i;
		str[j++] = ft_substr(s, start, (end - start));
	}
	str[j] = NULL;
	return (str);
}

// void	string_to_stack(char **argv, t_stack_node *a)
// {
// 	argv = ft_split_special(argv[1], ' ');
// 	init_stack_a(&a, argv + 1);
// 	free_array(argv);
// }
