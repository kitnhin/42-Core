#include "minishell.h"

char **unset_array(char **env, char *str)
{
	char **tempenv = malloc((total_strings(env) + 1) * sizeof(char *));
	int i;
	int j;

	i = 0;
	j = 0;
	while(env[i])
	{
		if(ft_strncmp(env[i], str, ft_strlen(str)) != 0)
		{
			tempenv[j] = ft_strdup(env[i]);
			j++;
		}
		i++;
	}
	tempenv[j] = NULL;
	return tempenv;
}

int unset(char ***env, char *str)
{
	char **tempenv = unset_array(*env, str);
	free_2d_array(*env);
	*env = tempenv;
	// print_env(*env);
	return 0;
}

void	print_env(char **env)
{
	int i;

	i = 0;
	while(env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}

// int main(int argc, char **argv, char **envp)
// {
// 	char **env;

// 	env = envp;
// 	print_env(env);
// 	unset(&env, "USER");
// 	printf("---------------------------------------------\n");
// 	print_env(env);
// }