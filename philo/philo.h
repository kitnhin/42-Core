/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:14:19 by ethanlim          #+#    #+#             */
/*   Updated: 2024/08/12 17:30:08 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				right_fork_id;
	int				left_fork_id;
	long long int	last_ate;
	int				num_of_meals;

	pthread_t		thread;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				total_philo_num;
	int				death_time;
	int				eating_time;
	int				sleeping_time;
	int				total_meals;
	long long int	start_time;

	t_philo			philo[200];
	pthread_mutex_t	fork[200];
	pthread_mutex_t	writing_lock;
	pthread_mutex_t	checks_lock;
}	t_data;

void			print_error(int n);

void			init_all(t_data *data, char **argv, int argc);

int				ft_atoi(const char *str);
long long int	gettime(void);
void			free_exit(t_data *data);
void			timer(long long int time);

void			run(t_data *data);

// void	print_data(t_data *data);
// void	print_philo(t_data *data);
// void	print_action(t_data *data, int id, char *str);
#endif
