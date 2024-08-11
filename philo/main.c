#include "philo.h"

void	print_error(int n)
{
	write(2, "Error: ", 7);
	if (n == 1)
		write(2, "wrong philo usage", 17);
	if (n == 2)
		write(2, "at least one argument is invalid", 32);
	if (n == 3)
		write(2, "mutex init failed", 17);
	write(2, "\n", 1);
	exit(1);
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 5 && argc != 6)
		print_error(1);
	init_all(&data, argv, argc);
	run(&data);
	// print_data(&data);
	// print_philo(&data);

}