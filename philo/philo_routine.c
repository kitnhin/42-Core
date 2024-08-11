#include "philo.h"

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
	// usleep(data->eating_time * 1000);
	timer(data->eating_time);
	philo->num_of_meals++;
	pthread_mutex_unlock(&(data->fork[philo->left_fork_id]));
	pthread_mutex_unlock(&(data->fork[philo->right_fork_id]));
}

void	*routine(void *philosopher)
{
	t_philo *philo;
	t_data *data;

	philo = (t_philo *)philosopher;
	data = philo->data;
	if (philo->id % 2 == 0)
	{
		print_action(data, philo->id, "is thinking");
		// usleep(data->eating_time * 1000);
		timer(data->eating_time);
	}
	while(1)
	{
		eat(philo);
		print_action(data, philo->id, "is sleeping");
		// usleep(data->sleeping_time * 1000);
		timer(data->sleeping_time);
		print_action(data, philo->id, "is thinking");
	}
}

void	end_checker(t_data *data)
{
	int	i;

	i = 0;
	while(1)
	{
		while(i < data->total_philo_num)
		{
			// pthread_mutex_lock(&(data->checks_lock));
			if (gettime() - data->philo[i].last_ate > data->death_time)
			{
				print_action(data, i, "died");
				free_exit(data);
			}
			// pthread_mutex_unlock(&(data->checks_lock));
			i++;
			timer(100);
		}
		i = 0;
		if (data->total_meals != -1)
		{
			while(data->philo[i].num_of_meals >= data->total_meals)
				i++;
			if (i == data->total_philo_num)
				free_exit(data);
		}
	}
}

void	run(t_data *data)
{
	int i;

	i = 0;
	data->start_time = gettime();
	while (i < data->total_philo_num)
	{
		data->philo[i].last_ate = gettime();
		pthread_create(&(data->philo[i].thread), NULL, routine, &(data->philo[i]));
		i++;
	}
	end_checker(data);
}