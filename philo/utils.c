#include "philo.h"

long long int gettime(void)
{
	struct timeval time;
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

void	print_action(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&(data->writing_lock));
	printf("%lld ", gettime() - data->start_time);
	printf("%d ", id + 1);
	printf("%s\n", str);
	pthread_mutex_unlock(&(data->writing_lock));
}

void	free_exit(t_data *data)
{
	int	i;

	i = 0;
	// while (i < data->total_philo_num)
	// {
	// 	pthread_join(data->philo[i].thread, NULL);
	// 	i++;
	// }
	exit(0);
}

void	timer(long long int time)
{
	long long int current;

	current = gettime();
	while (1)
	{
		if (gettime() - current >= time)
			break;
		usleep(50);
	}
}