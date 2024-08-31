#include "minishell.h"

void	init_pipe_node(t_node *node)
{
	if(pipe(node->piping.pipe_fd) == -1)
	{
		perror("pipe");
		exit(1);
	}
}
// void	init_parsing_list(int type, t_node *node, t_tokens *token)
// {
// 	if(type == Pipe)
// 	{
// 		node->type = Pipe;
// 		init_pipe_node(node);
// 	}
// 	else if(type = command)
// 	{
// 		node->type = simple_command;
// 		node->simple_cmd.cmd = token->token;
// 	}
// 	else if(type == redir_input)
// 	{

// 	}
// }

void	error_str(int n, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (n == 1)
		write(2, "Error: command not found: ", 26);
	else
		write(2, "Error: no such file or directory: ", 35);
	write(2, str, len);
	write(2, "\n", 1);
}

t_node	*make_final_list(t_tokens *tokens)
{
	t_node *list = NULL;
	t_node *newnode = NULL;
	t_node *last_node = NULL;
	t_tokens *token;

	token = tokens;
	int i = 0;
	int j = 0;
	while(token)
	{
		newnode = malloc(sizeof(t_node));
		newnode->type = token->type;
		if(token->type == Pipe)
		{
			init_pipe_node(newnode);
			token = token->next;
		}
		else if(token->type == redir_input)
		{
			newnode->type = redir_input;
			if(token->next->type == infile)
			{
				newnode->redir_in.in_file = token->next->token;
				newnode->redir_in.fd = open(newnode->redir_in.in_file, O_RDONLY);
				if(newnode->redir_in.fd == -1)
				{
					error_str(2, newnode->redir_in.in_file);
					return NULL;
				}
				token = token->next;
				token = token->next;
			}
			else
			{
				printf("infile redir error");
			}
		}
		else if(token->type == redir_out_append)
		{
			newnode->type = redir_out_append;
			if(token->next->type == outfile_append)
			{
				newnode->redir_out.outfile = token->next->token;
				newnode->redir_out.fd = open(newnode->redir_out.outfile, O_WRONLY | O_CREAT, 0777);
				token = token->next;
				token = token->next;
			}
			else
			{
				printf("outfile redir error");
			}
		}
		else if(token->type == redir_out_overwrite)
		{
			newnode->type = redir_out_overwrite;
			if(token->next->type == outfile_overwrite)
			{
				newnode->redir_out.outfile = token->next->token;
				newnode->redir_out.fd = open(newnode->redir_out.outfile, O_WRONLY | O_TRUNC| O_CREAT, 0777);
				token = token->next;
				token = token->next;
			}
			else
			{
				printf("outfile redir error");
			}
		}
		else if(token->type == command)
		{
			newnode->type = s_command;
			newnode->simple_cmd.cmd = ft_strdup(token->token);
			newnode->simple_cmd.array = malloc(sizeof(char *) * 1000);
			newnode->simple_cmd.array[i] = ft_strdup(token->token);
			i++;
			token = token->next;
			while(token != NULL && token->type == arguments)
			{
				// newnode->simple_cmd.args[j] = ft_strdup(token->token);
				newnode->simple_cmd.array[i] = ft_strdup(token->token);
				i++;
				// j++;
				token = token->next;
			}
			// newnode->simple_cmd.args[j] = NULL;
			newnode->simple_cmd.array[i] = NULL;
			i = 0;
			// j = 0;
			// token = token->prev;
		}
		else
			token = token->next;
		if(last_node)
		{
			last_node->next = newnode;
			newnode->prev = last_node;
		}
		else
			newnode->prev = NULL;
		last_node = newnode;
		newnode->next = NULL;
		if (!list)
			list = newnode;
	}
	return list;
}

void	print_final_list(t_node *list)
{
	while(list)
	{
		printf("|%d|", list->type);
		if(list->type == redir_input)
		{
			printf("|infile: %s, fd : %d|", list->redir_in.in_file, list->redir_in.fd);
		}
		if(list->type == s_command)
		{
			printf("|%s|", list->simple_cmd.cmd);
			int i = 0;
			printf("|");
			while(list->simple_cmd.array[i])
			{
				printf(":%s:", list->simple_cmd.array[i]);
				i++;
			}
			// i = 0;
			printf("|");
		}
		if(list->type == redir_out_append || list->type == redir_out_overwrite)
		{
			printf("|outfile: %s, fd : %d|", list->redir_out.outfile, list->redir_out.fd);
		}
		if (list->type == Pipe)
		{
			printf("pipe fd[0] = %d, fd[1] = %d", list->piping.pipe_fd[0], list->piping.pipe_fd[1]);
		}
		list = list->next;
		printf("\n");
	}
}
// int	main(int argc, char **argv, char **envp)
// {
// 	t_tokens *list;
// 	t_node	*final_list;
// 	char *str = "< testfile | cat | sort >> outfile";
// 	t_data data;
// 	data.tokens = lexer(str,envp);
// 	// print_token_array(data.tokens);
// 	printf("-----------------------------------\n");
// 	list = init_token_list(&data);
// 	identify_tokens_list(list);
// 	identify_tokens_list2(list);
// 	if(check_valid_list(list) == 1)
// 		exit(1);
// 	// print_tokens_list(list);
// 	final_list = make_final_list(list);
// 	print_final_list(final_list);
// }
