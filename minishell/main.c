#include "minishell.h"

void	signal_handler(int sig)
{
	write(1,"^C",2);
	rl_replace_line("", 0);
	rl_on_new_line();
	write(0,"\n",1);
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
int the_real_actual_main(t_data *data)
{
    t_node *list;
	pid_t pid;

    list = data->instr_list;
	// print_final_list(list);
    while (list)
    {
        if (list->type == s_command)
        {
            if (list->prev && list->prev->type == Pipe)
            {
                dup2(list->prev->piping.pipe_fd[0], 0);
            }
            if (list->next && list->next->type == Pipe)
            {
                dup2(list->prev->piping.pipe_fd[1], 1);
            }
            if (list->next && list->next->type == redir_input)
            {
                dup2(list->next->redir_in.fd, 0);
            }
            if (list->next && (list->next->type == redir_out_append || list->next->type == redir_out_overwrite))
            {
                dup2(list->next->redir_out.fd, 1);
            }
            execute(list->simple_cmd.array, &data);
        }
        list = list->next;
    }
    return 0;
}
int	run(char *line, t_data *data)
{
	t_tokens	*list;
	pid_t	pid;

	data->input_line = line;
	data->tokens = lexer(line, data->envp);
	// process_tokens(&data);
	if (data->tokens == NULL)
	{
		free(data->envp);
		return 1;
	}
	list = init_token_list(data);
	identify_tokens_list(list);
	identify_tokens_list2(list);
	if(check_valid_list(list) == 1)
		return(1);
	// printf("----------------------");
	data->instr_list = make_final_list(list);
	// execute(data.tokens, data.envp);
	// print_final_list(data.instr_list);
	if(data->instr_list != NULL)
		the_real_actual_main(data);
	return 0;
}

void	init_data_struct(t_data *data, char **envp)
{
	data->envp = malloc(sizeof(char *) * (total_strings(envp) + 1));
	malloc_dup_env(data->envp, envp);
}
int main(int argc, char **argv, char **envp) 
{
	pid_t	pid;
	t_data	data;
	char	*line;
	char	*readline_prompt;

	init_data_struct(&data, envp);
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
			run(line, &data);
		}
    }
    return 0;
}