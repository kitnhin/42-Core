#include <sys/time.h>
#include <unistd.h>

long long int gettime()
{
	struct timeval time;
	long long int	milisec_time;

	gettimeofday(&time, NULL);
	milisec_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (milisec_time);
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

// #include <stdio.h>
// int main()
// {
// 	int i = 0;

// 	// long long int time = gettime();
// 	// printf("%lld\n", time);
// 	while(i <= 20)
// 	{
// 		printf("this is printed at %d sec\n", i);
// 		timer(1000);
// 		i++;
// 	}
// 	return 0;
// }