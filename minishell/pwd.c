#include "minishell.h"

int	pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	if(!str)
	{
		perror("getcwd error");
		return 1;
	}
	printf("%s\n", str);
	free(str);
	return 0;
}