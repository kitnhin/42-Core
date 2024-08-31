#include "minishell.h"

void	free_2d_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	print_2d_array(char **cmd)
{
	int i = 0;
	while(cmd[i])
	{
		printf("token %d = %s\n", i, cmd[i]);
		i++;
	}
}

int	exit_process()
{
	write(1,"exit\n", 5);
	exit(0);
	return 0;
}