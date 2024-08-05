#include "pipex.h"

void	exit_error(int n)
{
	if (n == 1)
		write(2, "Error: wrong pipex usage\n", 25);
	else
		perror("Error");
	exit(1);
}

void	exit_error_str(char *str, int n)
{
	int len;

	len = ft_strlen(str);
	if (n == 1)
		write(2,"Error: command not found: ",26);
	else
		write(2,"Error: no such file or directory: ", 35);
	write(2,str,len);
	write(2,"\n",1);
	exit(1);

}

char *get_path(char **envp, char *cmd)
{
	int		i;
	char	**paths_list;
	char	*paths_string;
	char	*full_path;
	char	*temp;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths_string = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	paths_list = ft_split(paths_string, ':');
	i = 0;
	while (paths_list[i])
	{
		temp = ft_strjoin(paths_list[i], "/");
		full_path = ft_strjoin(temp, cmd);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(temp);
		free(full_path);
		i++;
	}
	i = 0;
	while (paths_list[i])
	{
		free(paths_list[i]);
		i++;
	}
	free(paths_list);
	exit_error_str(cmd, 1);
	return (NULL);
}

void	execute(char *argv, char **envp)
{
	char **cmd;
	char *path;

	cmd = ft_split(argv, ' ');
	path = get_path(envp, cmd[0]);
	if (execve(path, cmd, envp) == -1)
		exit_error(0);
}

void	exec_pipe_cmd(char *cmd, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		exit_error(0);
	pid = fork();
	if (pid == -1)
		exit_error(0);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		execute(cmd, envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
	}
}

void	handle_pipe(int argc, char **argv, char **envp)
{
	int	outfile;
	int	i;

	outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	i = 2;
	while (i < argc - 1)
	{
		if (i == argc - 2)
		{
			dup2(outfile, 1);
			execute(argv[i], envp);
		}
		exec_pipe_cmd(argv[i], envp);
		i++;
	}
}

void	get_heredoc_input(char *limit, int *pipe_fd)
{
	char	*line;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_error(0);
	if (pid == 0)
	{
		while (1)
		{
			line = get_next_line(0);
			if (ft_strncmp(limit, line, ft_strlen(limit)) == 0)
			{
				free(line);
				exit(0) ;
			}
			ft_putstr_fd(line, pipe_fd[1]);
			free(line);
		}
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(pipe_fd[1]);
		return;
	}
}
int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	pipe_fd[2];
	
	if (argc < 5)
		exit_error(1);
	else if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc < 6)
			exit_error(1);
		if (pipe(pipe_fd) == -1)
			exit_error(0);
		get_heredoc_input(argv[2], pipe_fd);
		dup2(pipe_fd[0], 0);
		handle_pipe(argc - 1, argv + 1, envp);
	}
	else
	{
		infile = open(argv[1], O_RDONLY);
		if (infile == -1)
			exit_error_str(argv[1], 2);
		dup2(infile, 0);
		handle_pipe(argc, argv, envp);
	}
}
