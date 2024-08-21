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

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	pid_t	pid;


	pid = fork();
	cmd = lexer(argv, envp);
	if (pid == 0)
	{	
		// cmd = lexer(argv, envp);
		path = get_path(envp, cmd[0]);
		execve(path, cmd, envp);
	}
	else
		waitpid(pid, NULL, 0);
	// if (execve(path, cmd, envp) == -1)
	// 	exit_error(0);
	if(ft_strcmp(cmd[0], "cat") == 0)
		ft_printf("\n");
}

void	signal_handler(int sig)
{
	write(1,"^C",2);
	write(1,"\n",1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

char	*get_readline_prompt(char **env)
{
	char	*temp1;
	char	**temp_split;
	char	temp_buffer[1024];
	char	*temp2;
	char	*res;
	int		i;

	i = 0;
	temp1 = ft_strjoin(ft_strjoin("\033[34m", ft_strjoin(get_expand_string("USER", env), "@Minishell$ ")), "\033[0m");
	if (getcwd(temp_buffer,sizeof(temp_buffer)) == NULL)
	{
		perror("getcwd error");
		exit(1);
	}
	temp_split = ft_split(temp_buffer, '/');
	while(temp_split[i + 1] != NULL)
		i++;
	temp2 = ft_strjoin(temp1, temp_split[i]);
	res = ft_strjoin(temp2, ":");
	free(temp1);
	free(temp2);
	free_2d_array(temp_split);
	return res;
}

int	run(char *line, char **envp)
{
	t_data	data;
	pid_t	pid;

	data.input_line = line;
	data.envp = envp;
	data.tokens = lexer(line, envp);
	// pid = fork();
	// if (pid == 0)
	// 	execute(line, envp);
	// else
	// 	waitpid(pid, NULL, 0);
	execute(data.input_line, data.envp);
	return 0;
}
int main(int argc, char **argv, char **envp) 
{
	t_data	data;
	pid_t	pid;
	char *line;
	char	*readline_prompt;

	data.envp = envp;
    rl_initialize();

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
    while (1)
	{
		readline_prompt = get_readline_prompt(envp);
    	line = readline(readline_prompt);
		if (line == NULL)
		{
			write(1,"exit",4);
			break ;
		}
		if (line)
			add_history(line);
		// print_history();
		if (line)
		{
			run(line, envp);
		}
    }
    return 0;
}