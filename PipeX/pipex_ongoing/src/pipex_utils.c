/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:35:46 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/16 17:09:11 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

#define COMMAND_NOT_FOUND (127)

void	execute_program(char *cmd, char **p_path_split)
{
	char	**program_split;
	char	*p_path;
	int		i;

	program_split = ft_split(cmd, ' ');
	i = 0;
	while (p_path_split[i])
	{
		p_path = ft_strjoin_all(3, p_path_split[i], "/", program_split[NAME]);
		if (access(p_path, F_OK | X_OK) == ACCESS_OK)
		{
			execve(p_path, program_split, environ);
			exit_error(cmd, PERROR, EXIT_FAILURE);
		}
		else
			free(p_path);
		i++;
	}
	ft_putstr_fd(program_split[NAME], STDERR_FILENO);
	free_data(program_split, p_path_split);
	exit_error(": command not found\n", PUTSTR, COMMAND_NOT_FOUND);
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

void	free_data(char **program_split, char **p_path_split)
{
	int	i;

	i = 0;
	while (program_split[i] != NULL)
		free(program_split[i++]);
	free(program_split);
	i = 0;
	while (p_path_split[i] != NULL)
		free(p_path_split[i++]);
	free(p_path_split);
}
