#include "minishell.h"

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

t_tokens*	process_tokens(t_data *data)
{
	t_tokens *list;
	t_tokens *newnode;
	int i;

	i = 0;
	while(data->tokens[i])
	{
		newnode = malloc(sizeof(t_tokens *));
		newnode->token = data->tokens[i];
		if(!list)
		{
			list = newnode;
			newnode->next = NULL;
			newnode->prev = NULL;
		}
		else
		{
			list->next = newnode;
			newnode->prev = list;
			newnode->next = NULL;
		}
		i++;
	}
	return list;
}
int	run(char *line, char **envp)
{
	t_data	data;
	pid_t	pid;

	data.input_line = line;
	data.envp = envp;
	data.tokens = lexer(line, envp);
	// process_tokens(&data);
	if (data.tokens == NULL)
		return 1;
	execute(data.tokens, data.envp);
	return 0;
}

int main(int argc, char **argv, char **envp) 
{
	t_data	data;
	pid_t	pid;
	char	*line;
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
			write(1,"exit\n",5);
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