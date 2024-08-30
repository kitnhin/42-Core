#include "minishell.h"

int	env(t_data *data)
{
	int i;

	i = 0;
	while(data->envp[i])
	{
		printf("%s\n", data->envp[i]);
		i++;
	}
	return 0;
}