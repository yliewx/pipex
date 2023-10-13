/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:43:59 by yliew             #+#    #+#             */
/*   Updated: 2023/10/13 19:14:08 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include "libft/includes/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>

/*pipex.c*/
void	process_handler(char **argv, int index, int input_fd, char **path);
void	perror_exit(char *message, int exit_code);

/*pipe_utils.c*/
void	close_pipes(int pipe1, int pipe2);
void	read_pipe_handler(int *pipefd, int input_fd);
void	write_pipe_handler(char **argv, int index, int *pipefd, int *outfile);

/*command_utils.c*/
void	command_handler(char **argv, int index, char **path_array);
void	get_command_path(char **command_path, char *arg, char **path_array);
char	**get_env_path(char **envp);
void	get_child_argv(char *arg, char ***child_argv, int token_count);
int		count_tokens(char *arg);

#endif
