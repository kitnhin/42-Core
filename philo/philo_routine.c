/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:11:50 by ethanlim          #+#    #+#             */
/*   Updated: 2024/08/17 03:02:30 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&(data->writing_lock));
	printf("%lld ", gettime() - data->start_time);
	printf("%d ", id + 1);
	printf("%s\n", str);
	pthread_mutex_unlock(&(data->writing_lock));
}

void	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->fork[philo->left_fork_id]));
	print_action(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->fork[philo->right_fork_id]));
	print_action(data, philo->id, "has taken a fork");
	philo->last_ate = gettime();
	print_action(data, philo->id, "is eating");
	philo->num_of_meals++;
	timer(data->eating_time);
	pthread_mutex_unlock(&(data->fork[philo->left_fork_id]));
	pthread_mutex_unlock(&(data->fork[philo->right_fork_id]));
}

void	*routine(void *philosopher)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)philosopher;
	philo->last_ate = gettime();
	data = philo->data;
	if (philo->id % 2 == 0)
	{
		print_action(data, philo->id, "is thinking");
		timer(data->eating_time);
	}
	while (1)
	{
		eat(philo);
		print_action(data, philo->id, "is sleeping");
		timer(data->sleeping_time);
		print_action(data, philo->id, "is thinking");
	}
	return (NULL);
}

void	end_checker(t_data *data)
{
	int	i;

	i = 0;
	usleep(50);
	while (1)
	{
		while (i < data->total_philo_num)
		{
			if (gettime() - data->philo[i].last_ate > data->death_time)
			{
				print_action(data, i, "died");
				exit(0);
			}
			i++;
		}
		i = 0;
		if (data->total_meals != -1)
		{
			while (data->philo[i].num_of_meals >= data->total_meals)
				i++;
			if (i == data->total_philo_num)
				exit(0);
		}
	}
}

void	run(t_data *data)
{
	int	i;
	int	error;

	i = 0;
	data->start_time = gettime();
	while (i < data->total_philo_num)
	{
		error = pthread_create(&(data->philo[i].thread), NULL, routine,
				&(data->philo[i]));
		if (error != 0)
			print_error(4);
		i++;
	}
	end_checker(data);
}
