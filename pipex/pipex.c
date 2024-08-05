/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 00:43:56 by ethanlim          #+#    #+#             */
/*   Updated: 2024/08/06 01:07:01 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp, char *cmd)
{
	int		i;
	char	**paths_list;
	char	*paths_string;
	char	*full_path;
	char	*temp;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	paths_string = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	paths_list = ft_split(paths_string, ':');
	i = -1;
	while (paths_list[++i])
	{
		temp = ft_strjoin(paths_list[i], "/");
		full_path = ft_strjoin(temp, cmd);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(temp);
		free(full_path);
	}
	free_2d_array(paths_list);
	exit_error_str(cmd, 1);
	return (NULL);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = get_path(envp, cmd[0]);
	if (execve(path, cmd, envp) == -1)
		exit_error(0);
}

void	child(int *pipe_fd, char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		exit_error_str(argv[1], 2);
	close(pipe_fd[0]);
	dup2(infile, 0);
	dup2(pipe_fd[1], 1);
	execute(argv[2], envp);
}

void	parent(int *pipe_fd, char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (outfile == -1)
		exit_error(0);
	close(pipe_fd[1]);
	dup2(outfile, 1);
	dup2(pipe_fd[0], 0);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			exit_error(0);
		pid = fork();
		if (pid == -1)
			exit_error(0);
		if (pid == 0)
			child(pipe_fd, argv, envp);
		else
		{
			waitpid(pid, NULL, 0);
			parent(pipe_fd, argv, envp);
		}
	}
	else
		exit_error(1);
	return (0);
}
