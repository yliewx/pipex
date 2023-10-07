/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:25:15 by yliew             #+#    #+#             */
/*   Updated: 2023/10/07 19:08:44 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_handler(char *command, char *file)
{
	pid_t	pid1;
	pid_t	pid2;
	pid_t	ended_pid1;
	pid_t	ended_pid2;
	int	pipefd[2];

	ft_printf("%s can be read. Command: %s\n", file, command);
	//create pipe
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	//1st fork: cat file
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
	{
		ft_printf("testing output fork; pid: %i\n", pid1);
		//replace stdout with pipe write end
		pipe_handler(pipefd[1], pipefd[0], 1);
		cat_file(file);
		exit(EXIT_SUCCESS);
	}
	//2nd fork: execute command on the output of 1st process
	else
	{
		ended_pid1 = waitpid(pid1, NULL, 0);
		pid2 = fork();
		if (pid2 == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid2 == 0)
		{
			//replace stdin with pipe read end
			pipe_handler(pipefd[0], pipefd[1], 0);
			execute_command(command, file);
			exit(EXIT_SUCCESS);
		}
		else
		{
			close(pipefd[0]);
			close(pipefd[1]);
			ended_pid2 = waitpid(pid2, NULL, 0);
			printf("ended pids: %i, %i\n", ended_pid1, ended_pid2);
		}
	}
}

int	main(int argc, char **argv)
{
	char	*file1;
	char	*command1;

	if (argc != 3)
	{
		ft_printf("Please enter 2 arguments.\n");
		return (0);
	}
	file1 = argv[1];
	command1 = argv[2];
	if (access(file1, R_OK) != 0)
	{
		perror("access");
		exit(EXIT_SUCCESS);
	}
	process_handler(command1, file1);
	ft_printf("end of test\n");
	return (0);
}
