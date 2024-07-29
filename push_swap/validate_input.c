/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:23:05 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/29 19:07:47 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *str)
{
	long	n;

	n = atol(str);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	else
		return (1);
}

int	check_dup(char **argv)
{
	int		i;
	int		j;
	long	a;
	long	b;

	i = 0;
	j = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			a = atol(argv[i]);
			b = atol(argv[j]);
			if (a == b)
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
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

int	check_nums(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
