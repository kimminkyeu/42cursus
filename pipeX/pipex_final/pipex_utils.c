/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:35:46 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/17 16:45:25 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define COMMAND_NOT_FOUND (127)

void	execute_program(char *cmd, char **env_path)
{
	char	**program_split;
	char	*cmd_with_path;
	int		i;

	program_split = ft_split(cmd, ' ');
	if (access(program_split[NAME], F_OK | X_OK) == ACCESS_OK)
		run_execve(program_split[NAME], program_split);
	i = -1;
	while (env_path[++i])
	{
		cmd_with_path = ft_strjoin_all(3, \
				env_path[i], "/", program_split[NAME]);
		if (access(cmd_with_path, F_OK | X_OK) == ACCESS_OK)
			run_execve(cmd_with_path, program_split);
		else
			free(cmd_with_path);
	}
	ft_putstr_fd(program_split[NAME], STDERR_FILENO);
	free_data(program_split, env_path);
	exit_error(": command not found\n", PUTSTR, COMMAND_NOT_FOUND);
}

void	run_execve(char *cmd, char **program_split)
{
	execve(cmd, program_split, environ);
	exit_error(cmd, PERROR, EXIT_FAILURE);
}

char	**get_environ_path(void)
{
	int		i;
	char	*p_path;
	char	**p_path_split;

	i = 0;
	p_path_split = NULL;
	while (environ[i] != NULL)
	{
		p_path = ft_strnstr(environ[i], "PATH", 4);
		if (p_path != NULL)
		{
			p_path_split = ft_split(p_path + 5, ':');
			if (p_path_split == NULL)
				exit_error("ft_split()", PUTSTR, EXIT_FAILURE);
			break ;
		}
		i++;
	}
	return (p_path_split);
}

void	exit_error(char *messege, int is_perror, int exit_code)
{
	if (is_perror)
		perror(messege);
	else
		ft_putstr_fd(messege, STDERR_FILENO);
	exit(exit_code);
}

void	free_data(char **program_split, char **env_path)
{
	int	i;

	i = 0;
	while (program_split[i] != NULL)
		free(program_split[i++]);
	free(program_split);
	i = 0;
	while (env_path[i] != NULL)
		free(env_path[i++]);
	free(env_path);
}
