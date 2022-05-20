/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:35:46 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/15 17:24:15 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

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
			execve(p_path, program_split, environ);
		else
			free(p_path);
		i++;
	}
	ft_putstr_fd(program_split[NAME], STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	free_data(program_split, p_path_split);
	exit(EXIT_FAILURE);
}

char	**get_environ_path(char **environ)
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
				exit_error("ft_split() error\n", PUTSTR);
			break ;
		}
		i++;
	}
	return (p_path_split);
}
