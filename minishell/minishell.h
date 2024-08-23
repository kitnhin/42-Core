#ifndef MINISHELL_H
#define MINISHELL_H


#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/history.h>
#include "libft/libft.h"


#define string 1
#define operator 2
#define single_quote_string 3
#define double_quote_string 4
#define pipe 5
#define redir_input 6
#define heredoc 7
#define redir_out_overwrite 8
#define redir_out_append 9
#define dollar_sign 10
//-------------------------------------------
#define command 21
#define arguments 22
#define infile 23
#define outfile_overwrite 24
#define outfile_append 25
//-----------------------------------------
#define simple_command 31


typedef struct s_data
{
	char	**envp;
	char	*input_line;
	char	**tokens;
}	t_data;

typedef struct s_lexing
{
	char *line;
	char **res;
	int start;
	int i;
	char **envp;
	int j;
}	t_lexing;

typedef struct s_token
{
    char *token;
    int type;

    struct s_token *next;
    struct s_token *prev;
} t_tokens;

typedef struct s_simple_command
{
	char *cmd;
	char **args;
	char **array;
} t_simple_command;

typedef struct s_redir_out
{
	char *outfile;
	int fd;
} t_redir_out;

typedef struct s_redir_in
{
	char *in_file;
	int fd;
	int here_doc;
} t_redir_in;

typedef struct s_pipe
{
	int *pipe_fd;
} t_pipe;


typedef struct s_node
{
	int type;
	t_simple_command simple_cmd;
	t_redir_in redir_in;
	t_redir_out redir_out;
	t_pipe piping;

	struct s_node *next;
	struct s_node *prev;
}	t_node;


extern void rl_replace_line(const char *, int);
char **lexer(char *line, char **envp);

//expansion
char	*get_expand_string(char *str, char **envp);

char	*expansion(char *line, char **envp);

//utils
void	free_2d_array(char **str);

//execve
char	*get_path(char **envp, char *cmd);
void	execute(char **cmd, char **envp);

//lexer2
int handle_quotes(char *line, int i);
char	*substr_expand(char *line, char **envp, int i, int start);
int	lexer_helper1(t_lexing *lexer);
int	lexer_helper2(t_lexing *lexer);
int lexer_helper3(t_lexing *lexer);
int	init_lexer_struct(t_lexing *lexer, char **envp, char *line);

//pwd
int	pwd(void);

//echo
int	echo(char **cmd);

//env
int	env(char **envp);

//cd
int cd(char **cmd, char **envp);
#endif