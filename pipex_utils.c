/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:05:30 by yliew             #+#    #+#             */
/*   Updated: 2023/10/07 18:15:52 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cat_file(char *file)
{
	char	*child_argv[3];
	char	*new_env[2];
	char	*command_path;

	command_path = "/usr/bin/cat";
	new_env[0] = NULL;
	new_env[1] = NULL;
	if (access(command_path, X_OK) == 0)
		new_env[0] = "PATH=/usr/bin";
	child_argv[0] = command_path;
	child_argv[1] = file;
	child_argv[2] = NULL;
	execve(command_path, child_argv, new_env);
}

void	execute_command(char *command, char *file)
{
	char	*child_argv[5];
	char	*new_env[2];
	char	*command_path;

	command_path = ft_strjoin("/usr/bin/", command);
	new_env[0] = NULL;
	new_env[1] = NULL;
	if (access(command_path, X_OK) == 0)
		new_env[0] = "PATH=/usr/bin";
	child_argv[0] = "/bin/sh";
	child_argv[1] = "-c";
	child_argv[2] = command;
	child_argv[3] = file;
	child_argv[4] = NULL;
	execve(child_argv[0], child_argv, new_env);
}
