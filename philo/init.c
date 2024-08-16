/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:27:05 by ethanlim          #+#    #+#             */
/*   Updated: 2024/08/17 02:53:39 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	print_philo(t_data *data)
// {
// 	int i = 0;
// 	while (i < data->total_philo_num)
// 	{
// 		printf("--------------------------------------------------\n");
// 		printf("philo id = %d\n", data->philo[i].id);
// 		printf("philo left fork id = %d\n", data->philo[i].left_fork_id);
// 		printf("philo right fork id = %d\n", data->philo[i].right_fork_id);
// 		printf("philo last ate = %lld\n", data->philo[i].last_ate);
// 		printf("philo total meals ate = %d\n", data->philo[i].num_of_meals);
// 		printf("--------------------------------------------------\n");
// 		i++;
// 	}
// }
// void	print_data(t_data *data)
// {
// 	printf("total philo num = %d\n", data->total_philo_num);
// 	printf("death time = %dms\n", data->death_time);
// 	printf("eating_time = %dms\n", data->eating_time);
// 	printf("sleeping time = %dms\n", data->sleeping_time);
// 	if (data->total_meals != -1)
// 		printf("total meals needed : %d\n", data->total_meals);
// }

void	init_mutex(t_data *data)
{
	int	i;
	int	error;

	i = 0;
	while (i < data->total_philo_num)
	{
		error = pthread_mutex_init(&(data->fork[i]), NULL);
		if (error != 0)
			print_error(3);
		i++;
	}
	error = pthread_mutex_init(&(data->writing_lock), NULL);
	if (error != 0)
		print_error(3);
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_philo_num)
	{
		data->philo[i].id = i;
		data->philo[i].left_fork_id = i;
		data->philo[i].right_fork_id = (i + 1) % data->total_philo_num;
		data->philo[i].last_ate = 0;
		data->philo[i].num_of_meals = 0;
		data->philo[i].data = data;
		i++;
	}
}

void	init_all(t_data *data, char **argv, int argc)
{
	data->total_philo_num = ft_atoi(argv[1]);
	data->death_time = ft_atoi(argv[2]);
	data->eating_time = ft_atoi(argv[3]);
	data->sleeping_time = ft_atoi(argv[4]);
	if (argc == 6)
	{
		data->total_meals = ft_atoi(argv[5]);
		if (data->total_meals < 0)
			print_error(2);
	}
	else
		data->total_meals = -1;
	if (data->total_philo_num < 1 || data->death_time < 60
		|| data->eating_time < 60 || data->sleeping_time < 60
		|| data->total_philo_num > 200)
		print_error(2);
	init_mutex(data);
	init_philo(data);
}
