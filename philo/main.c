/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:30:12 by ethanlim          #+#    #+#             */
/*   Updated: 2024/08/12 17:19:42 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	gettime(void)
{
	struct timeval	time;
	long long int	milisec_time;

	gettimeofday(&time, NULL);
	milisec_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (milisec_time);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;
	int	i;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
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

void	timer(long long int time)
{
	long long int	current;

	current = gettime();
	while (1)
	{
		if (gettime() - current >= time)
			return ;
		usleep(200);
	}
}

void	print_error(int n)
{
	write(2, "Error: ", 7);
	if (n == 1)
		write(2, "wrong philo usage", 17);
	if (n == 2)
		write(2, "at least one argument is invalid", 32);
	if (n == 3)
		write(2, "mutex init failed", 17);
	if (n == 4)
		write(2, "pthread creation failed", 24);
	write(2, "\n", 1);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		print_error(1);
	init_all(&data, argv, argc);
	run(&data);
	return (0);
}
