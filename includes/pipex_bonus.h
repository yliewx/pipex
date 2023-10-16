/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:43:59 by yliew             #+#    #+#             */
/*   Updated: 2023/10/16 17:55:50 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
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

/*pipe_utils_bonus.c*/
void	read_pipe_handler(int *pipefd, int input_fd);
void	write_pipe_handler(char **argv, int index, int *pipefd, int *outfile);

/*heredoc_bonus.c*/
int		heredoc_handler(char *limiter);

/*command_utils_bonus.c*/
void	command_handler(char **argv, int index, char **path_array);
void	get_command_path(char **command_path, char *arg, char **path_array);
char	**get_env_path(char **envp);
void	get_child_argv(char *arg, char ***child_argv, int token_count);
int		count_tokens(char *arg);

/*exit_utils_bonus.c*/
void	perror_exit(char *message, int exit_code);
void	check_exit_status(int child_exit_code);
void	close_pipes(int pipe1, int pipe2);

#endif
