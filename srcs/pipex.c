/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:25:15 by yliew             #+#    #+#             */
/*   Updated: 2023/10/16 14:50:52 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_handler(char **argv, int index, int input_fd, char **envp)
{
	pid_t	pid;
	int		pipefd[2];
	int		outfile;
	int		child_exit_code;

	if (pipe(pipefd) == -1)
		perror_exit("Pipe failed", EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		perror_exit("Fork failed", EXIT_FAILURE);
	if (pid == 0)
	{
		read_pipe_handler(pipefd, input_fd);
		write_pipe_handler(argv, index, pipefd, &outfile);
		command_handler(argv, index, envp);
	}
	close_pipes(pipefd[1], input_fd);
	if (argv[index + 2] == NULL)
	{
		waitpid(pid, &child_exit_code, 0);
		close_pipes(input_fd, outfile);
		check_exit_status(child_exit_code);
		exit(EXIT_SUCCESS);
	}
	process_handler(argv, index + 1, pipefd[0], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	input_fd;

	if (argc != 5)
	{
		ft_putstr_fd("Please enter 4 arguments.\n", 2);
		return (1);
	}
	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
		perror("Cannot open file");
	process_handler(argv, 2, input_fd, envp);
	return (1);
}
