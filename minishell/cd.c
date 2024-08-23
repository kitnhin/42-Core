#include "minishell.h"

int cd(char **cmd, char **envp)
{
	char *path;

	if(cmd[1] == NULL)
		path = get_expand_string("HOME", envp);
	else
		path = cmd[1];
	if (chdir(path) == -1)
	{
		perror("chdir");
		return 1;
	}
	// printf("current dir %s\n", getcwd(NULL, 0));
	return 0;
}