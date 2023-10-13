/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:05:30 by yliew             #+#    #+#             */
/*   Updated: 2023/10/13 18:50:55 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(int pipe1, int pipe2)
{
	close(pipe1);
	close(pipe2);
}

void	read_pipe_handler(int *pipefd, int input_fd)
{
	close(pipefd[0]);
	if (dup2(input_fd, STDIN_FILENO) == -1)
		perror_exit("Stdin redirection failed", EXIT_FAILURE);
}

void	write_pipe_handler(char **argv, int index, int *pipefd, int *outfile)
{
	if (argv[index + 2] == NULL)
	{
		*outfile = open(argv[index + 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (*outfile == -1)
			perror("Error opening outfile");
		if (dup2(*outfile, STDOUT_FILENO) == -1)
			perror_exit("Outfile redirection failed", EXIT_FAILURE);
	}
	else
	{
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			perror_exit("Stdout redirection failed", EXIT_FAILURE);
	}
}
