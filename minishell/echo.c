#include "minishell.h"

int check_flag(char *str)
{
	int i = 2;
	if(str[0] == '-' && str[1] == 'n')
	{
		while(str[i] && str[i] == 'n')
			i++;
		if(str[i] == '\0')
			return 1;
	}
	return 0;
}

int	echo(char **cmd)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	while(check_flag(cmd[i]) == 1)
	{
		flag = 1;
		i++;
	}
	while(cmd[i])
	{
		printf("%s", cmd[i]);
		if (cmd[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (flag == 0)
		printf("\n");
	return 0;
}