/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 02:12:23 by ethanlim          #+#    #+#             */
/*   Updated: 2024/08/06 02:16:59 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// utils
void	exit_error(int n);
void	exit_error_str(char *str, int n);
void	free_2d_array(char **str);
void	execute(char *argv, char **envp);

//main
char	*get_path(char **envp, char *cmd);
void	exec_pipe_cmd(char *cmd, char **envp);

#endif