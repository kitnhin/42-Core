/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 02:20:01 by ethanlim          #+#    #+#             */
/*   Updated: 2024/08/06 02:21:17 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// utils
void	exit_error(int n);
void	exit_error_str(char *str, int n);
void	free_2d_array(char **str);

//main
char	*get_path(char **envp, char *cmd);
void	execute(char *argv, char **envp);
void	child(int *pipe_fd, char **argv, char **envp);
void	parent(int *pipe_fd, char **argv, char **envp);

#endif