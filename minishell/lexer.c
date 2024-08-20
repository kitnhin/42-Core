#include "minishell.h"


int handle_quotes(char *line, int i)
{
	if (line[i] == '\'')
	{
    	i++;
		while (line[i] && line[i] != '\'')
            i++;
		if (line[i] == '\0')
		{
			printf("Unclosed quote detected\n");
			return -1;
		}
	}
	else if (line[i] == '\"')
	{
		i++;
		while (line[i] && line[i] != '\"')
			i++;
		if (line[i] == '\0')
		{
			printf("Unclosed quote detected\n");
			return -1;
		}
	}
	return i;
}

char	*substr_expand(char *line, char **envp, int i, int start)
{
	char *res;
	char *temp;

	temp = ft_substr(line, start, i - start);
	res = expansion(temp, envp);
	free(temp);
	return res;
}
char **lexer(char *line, char **envp)
{
    int i = 0;
	int single_quote_check = 0;
    char **res = malloc(sizeof(char *) * 1024);
    if (!res)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    int j = 0;
    int start;
    while (line[i])
    {
        while (line[i] == ' ')
            i++;
        start = i;
        if (line[i] == '\'')
        {
            start++;
			if(handle_quotes(line, i) == -1)
				return NULL;
			else
				i = handle_quotes(line, i);
			res[j] = ft_substr(line, start, i - start);
		}
	    else if (line[i] == '\"')
        {
            start++;
			if(handle_quotes(line, i) == -1)
				return NULL;
			else
				i = handle_quotes(line, i);
			res[j] = substr_expand(line, envp, i, start);
		}
		else if(line[i] == '|')
		{
				res[j] = ft_substr(line, i, 1);
				i++;
		}
		else
        {
			while (line[i] && line[i] != ' ' && line[i] != '|')
				i++;
			if (line[i] == '|')
			{
				res[j] = substr_expand(line, envp, i, start);
				j++;
				res[j] = ft_substr(line, i, 1);
				i++;
			}
			else
				res[j] = substr_expand(line, envp, i, start);
        }
		if (line[i] == '\'' || line[i] == '\"')
			i++;
        j++;
    }
    res[j] = NULL;
    return res;
}

// void	print_token(char **str)
// {
// 	int i = 0;
// 	while(str[i])
// 	{
// 		printf("token %d = %s\n", i, str[i]);
// 		i++;
// 	}
// }
// // int main(int argc, char **argv, char **envp)
// // {
// // 	char *string = "cat | '$USER' main.c|sort";
// // 	char **lex = lexer(string, envp);
// // 	print_token(lex);
// // }