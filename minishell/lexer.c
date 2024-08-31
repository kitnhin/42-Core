#include "minishell.h"

char **lexer(char *line, char **envp)
{
	t_lexing lexer;

	if(!line || line[0] == '\0')
		return NULL;
	if (init_lexer_struct(&lexer, envp, line) == 1)
		return NULL;
	while (lexer.line[lexer.i])
	{
		while (lexer.line[lexer.i] == ' ')
			lexer.i++;
		lexer.start = lexer.i;
		if (lexer.line[lexer.i] == '\'' || lexer.line[lexer.i] == '\"')
		{
			if (lexer_helper1(&lexer) == -1)
				return NULL;
			lexer.i++;
		}
		else if(lexer.line[lexer.i] == '|' || lexer.line[lexer.i] == '>' || lexer.line[lexer.i] == '<')
		{
			lexer_helper2(&lexer);
		}
		else
		{
			lexer_helper3(&lexer);
		}
		// if (lexer.line[lexer.i] == '\'' || lexer.line[lexer.i] == '\"')
		// 	lexer.i++;
		lexer.j++;
	}
	lexer.res[lexer.j] = NULL;
	return lexer.res;
}

t_tokens* init_token_list(t_data *data)
{
    t_tokens *list;
    t_tokens *last_node;
	int i;

	if (!data || !data->tokens)
        return NULL;
    i = 0;
	list = NULL;
    while(data->tokens[i])
    {
        t_tokens *newnode = malloc(sizeof(t_tokens));
        if (!newnode)
            return NULL;
        newnode->token = data->tokens[i];
        newnode->next = NULL;
        newnode->prev = last_node;
        if (!list)
            list = newnode;
        else
            last_node->next = newnode;
        last_node = newnode;
        i++;
    }
    return list;
}
void	identify_tokens_list(t_tokens *tokens)
{
	while(tokens)
	{
		if(tokens->token[0] == '|')
			tokens->type = Pipe;
		else if(tokens->token[0] == '>')
		{
			if(tokens->token[1] == '>')
				tokens->type = redir_out_append;
			else
				tokens->type = redir_out_overwrite;
		}
		else if(tokens->token[0] == '<')
		{
			if(tokens->token[1] == '<')
				tokens->type = heredoc;
			else
				tokens->type = redir_input;
		}
		else if(tokens->token[0] == '\'')
			tokens->type = single_quote_string;
		else if(tokens->token[0] == '\"')
			tokens->type = double_quote_string;
		// else if(tokens->token[0] == '$')
		// 	tokens->type = dollar_sign;
		else
			tokens->type = string;
		tokens = tokens->next;
	}
}

t_tokens *get_last_node(t_tokens *tokens)
{
	t_tokens *list;

	list = tokens;
	while(list->next)
	{
		list = list->next;
	}
	return list;
}

void	identify_tokens_list2(t_tokens *list)
{
	t_tokens *first_token;
	t_tokens *last_token;

	first_token = list;
	last_token = get_last_node(list);
	if(!last_token)
		return ;
	while(list)
	{
		if(list == first_token)
		{
			if(list->type != string) 
			{
				if(list->type == redir_input)
					list->next->type = infile;
				else if(list->type == redir_out_append)
					list->next->type = outfile_append;
				else if(list->type == redir_out_overwrite)
					list->next->type = outfile_overwrite;
				if(list->type != Pipe)
				{
					list = list->next;
					list = list->next;
				}
			}
			if(list->type == string)
				list->type = command;
		}
		else
		{
			if(list->type == string && list->prev->type == Pipe)
				list->type = command;
			else if(list->type == string && list->prev && list->prev->type == redir_input)
				list->type = infile;
			else if(list->type == string && list->prev && list->prev->type == redir_out_overwrite)
				list->type = outfile_overwrite;
			else if(list->type == string && list->prev && list->prev->type == redir_out_append)
				list->type = outfile_append;
			else if(list->type == string)
				list->type = arguments;
		}
		list = list->next;
	}
}

int check_operator(int n)
{
	if(n == Pipe || n == redir_input
		|| n == redir_out_append || n == redir_out_overwrite
		|| n == heredoc)
		return 1;
	return 0;
}
int	check_valid_list(t_tokens *list)
{
	t_tokens *last_node;
	t_tokens *first_node;
	t_tokens *temp;

	first_node = list;
	last_node = get_last_node(list);
	temp = list;

	if(first_node->type == Pipe)
	{
		ft_printf("syntax error near unexpected token '|'\n", last_node->token);
		return 1;
	}
	if(check_operator(last_node->type) == 1)
		{
			ft_printf("syntax error near unexpected token '%s'\n", last_node->token);
			return 1;
		}
	if(last_node->type == dollar_sign && last_node->prev)
	{
		last_node->prev->token = ft_strjoin(last_node->prev->token, last_node->token);
		free(last_node);
		last_node->prev->next = NULL;
	}
	while(temp->next)
	{
		if(check_operator(temp->type) == 1 && check_operator(temp->next->type) == 1)
		{
			ft_printf("syntax error near unexpected token '%s'", temp->token);
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}
void print_tokens_list(t_tokens *list) 
{
	int i = 0;
    while (list != NULL) 
	{
        printf("token %d : %s, type : %d\n", i, list->token, list->type);
        list = list->next;
		i++;
    }
}

void	print_token_array(char **str)
{
	int i = 0;
	if(!str)
	{
		printf("ERORRR LOLLL\n");
		return ;
	}
	while(str[i])
	{
		printf("token %d = %s\n", i, str[i]);
		i++;
	}
}

// int	main(int argc, char **argv, char **envp)
// {
// 	t_tokens *list;
// 	char *str = "echo \"$USER\"";
// 	t_data data;
// 	data.tokens = lexer(str,envp);
// 	print_token_array(data.tokens);
// 	printf("-----------------------------------\n");
// 	list = init_token_list(&data);
// 	identify_tokens_list(list);
// 	identify_tokens_list2(list);
// 	if(check_valid_list(list) == 1)
// 		exit(1);
// 	print_tokens_list(list);
// }

// int main(int argc, char **argv, char **envp)
// {
// 	char *str = "echo \"fsfsffsf";
// 	char **lex = lexer(str, envp);
// 	print_token_array(lex);
// }