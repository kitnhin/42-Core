#include "pipex.h"

void	print_error(int n)
{
	if (n == 1)
		ft_printf("dont try to be funny, syntax: ./pipex file1 cmd1 cmd2 file2");
	if (n == 2)
		ft_printf("fail to create pipe rip");
}