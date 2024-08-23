#include "minishell.h"

void	init_parsing_list(int type, t_node *node)
{
	if(type == pipe)
	{
		
	}
}
void	make_final_list(t_tokens *token)
{
	t_node *list;
	t_node *newnode;
	t_node *last_node;
	t_tokens *tokens;

	tokens = token;
	while(tokens)
	{
		newnode = malloc(sizeof(t_node));
		
	}
}