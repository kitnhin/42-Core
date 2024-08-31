#ifndef MINISHELL_H
#define MINISHELL_H


#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/history.h>
#include "libft/libft.h"
#include <string.h>
#include <limits.h>


#define string 1
#define operator 2
#define single_quote_string 3
#define double_quote_string 4
#define Pipe 5
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
#define s_command 31

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
	int pipe_fd[2];
} t_pipe;

typedef struct s_heredoc
{
	char *limiter;
} t_heredoc;

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

typedef struct s_data
{
	char	**envp;
	char	*input_line;
	char	**tokens;
	t_node	*instr_list;
}	t_data;

extern void rl_replace_line(const char *, int);
char **lexer(char *line, char **envp);

//expansion
char	*get_expand_string(char *str, char **envp);

char	*expansion(char *line, char **envp);

//utils
void	free_2d_array(char **str);
void	print_2d_array(char **cmd);
int		exit_process();

//execve
char	*get_path(char **envp, char *cmd);
int		execute(char **cmd, t_data **data);

//lexer2
int handle_quotes(char *line, int i);
char	*substr_expand(char *line, char **envp, int i, int start);
int	lexer_helper1(t_lexing *lexer);
int	lexer_helper2(t_lexing *lexer);
int lexer_helper3(t_lexing *lexer);
int	init_lexer_struct(t_lexing *lexer, char **envp, char *line);


//parse_list
t_node	*make_final_list(t_tokens *tokens);

//pwd
int	pwd(void);

//echo
int	echo(char **cmd);

//env
int	env(t_data *data);

//cd
int cd(char **cmd, char **envp);

void	print_token_array(char **str);
int	check_valid_list(t_tokens *list);
int check_operator(int n);
void	identify_tokens_list2(t_tokens *list);
void	identify_tokens_list(t_tokens *tokens);
t_tokens* init_token_list(t_data *data);
char **lexer(char *line, char **envp);
void print_tokens_list(t_tokens *list);
void	print_final_list(t_node *list);

//export
void	malloc_dup_env(char **dest, char **env);
int total_strings(char **env);
int export(char ***env, char *str);

//unset
int unset(char ***env, char *str);
void	print_env(char **env);
char **unset_array(char **env, char *str);
#endif