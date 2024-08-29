#include "minishell.h"

void	free_2d_array(char **str)
{
	int i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
}
void	exit_error(int n)
{
	if (n == 1)
		write(2, "Error: wrong pipex usage\n", 25);
	else
		perror("Error");
	exit(1);
}

void	exit_error_str(char *str, int n)
{
	int	len;

	len = ft_strlen(str);
	if (n == 1)
		write(2, "Error: command not found: ", 26);
	else
		write(2, "Error: no such file or directory: ", 35);
	write(2, str, len);
	write(2, "\n", 1);
	exit(1);
}

char	*get_path(char **envp, char *cmd)
{
	int		i;
	char	**paths_list;
	char	*paths_string;
	char	*full_path;
	char	*temp;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	paths_string = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	paths_list = ft_split(paths_string, ':');
	i = -1;
	while (paths_list[++i])
	{
		temp = ft_strjoin(paths_list[i], "/");
		full_path = ft_strjoin(temp, cmd);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(temp);
		free(full_path);
	}
	free_2d_array(paths_list);
	exit_error_str(cmd, 1);
	return (NULL);
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

void	execute(char **cmd, char **envp)
{
	char	*path;
	pid_t	pid;

	if(ft_strcmp(cmd[0], "cd") == 0)
	{
		cd(cmd, envp);
		return ;
	}
	pid = fork();
	if (cmd == NULL)
		exit_error(0);
	if (pid == 0)
	{
		// cmd = lexer(argv, envp);
		if (cmd[0][0] == '.' && cmd[0][1] == '/')
			path = ft_strdup(cmd[0]);
		else if(ft_strcmp(cmd[0], "pwd") == 0)
		{
			pwd();
			exit(0);
		}
		else if(ft_strcmp(cmd[0], "echo") == 0)
		{
			echo(cmd);
			exit(0);
		}
		else if(ft_strcmp(cmd[0], "env") == 0)
		{
			env(envp);
			exit(0);
		}
		else
			path = get_path(envp, cmd[0]);
		execve(path, cmd, envp);
	}
	else
		waitpid(pid, NULL, 0);
	// if (execve(path, cmd, envp) == -1)
	// 	exit_error(0);
}