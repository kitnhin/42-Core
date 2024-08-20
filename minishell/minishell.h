#ifndef MINISHELL_H
#define MINISHELL_H


#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/history.h>
#include "libft/libft.h"

typedef struct s_data
{
	char	**envp;
	char	*input_line;
	char	**tokens;
}	t_data;


extern void rl_replace_line(const char *, int);
char **lexer(char *line, char **envp);
char	*get_expand_string(char *str, char **envp);

char	*expansion(char *line, char **envp);

//utils
void	free_2d_array(char **str);

#endif