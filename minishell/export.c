#include "minishell.h"

// void	free_2d_array(char **str)
// {
// 	int i;

// 	i = 0;
// 	while(str[i])
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// }

int total_strings(char **env)
{
	int i;

	i = 0;
	while(env[i])
		i++;
	return i;
}

void	malloc_dup_env(char **dest, char **env)
{
	int i;

	i = 0;
	while(env[i])
	{
		dest[i] = ft_strdup(env[i]);
		i++;
	}
	dest[i] = NULL;
}

int export(char ***env, char *str)
{
	char **tempenv;
	tempenv = malloc(sizeof(char *) * (total_strings(*env) + 2));
	
	malloc_dup_env(tempenv, *env);
	tempenv[total_strings(*env)] = ft_strdup(str);
	tempenv[total_strings(*env) + 1] = NULL;
	free_2d_array(*env);
	*env = tempenv;
	return 0;
}