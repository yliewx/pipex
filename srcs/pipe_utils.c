/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:33:22 by yliew             #+#    #+#             */
/*   Updated: 2023/10/16 17:33:35 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*child process: replace stdin with the read end of the pipe*/
void	read_pipe_handler(int *pipefd, int input_fd)
{
	close(pipefd[0]);
	if (dup2(input_fd, STDIN_FILENO) == -1)
		perror_exit("Stdin redirection failed", EXIT_FAILURE);
}

/*child process: replace stdout with the write end of the pipe
- if at the last command, replace stdout with outfile*/
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
