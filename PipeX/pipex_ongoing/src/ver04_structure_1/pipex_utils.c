/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:35:46 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/14 20:33:39 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	run_process_pid(int pid, t_cmd cmd_info, int *pipe_in, int *pipe_out)
{

	(void)pid;
	printf("\nchild cmd: %s\n", cmd_info.cmd);
	printf("pipe_in --> read:%d write:%d\n", pipe_in[READ_END], pipe_in[WRITE_END]);
	printf("pipe_out --> read:%d write:%d\n", pipe_out[READ_END], pipe_out[WRITE_END]);


	if (dup2(pipe_in[READ_END], STDIN_FILENO) == ERROR \
			|| dup2(pipe_out[WRITE_END], STDOUT_FILENO) == ERROR)
		exit_error("dup2(): ", PERROR);


	if (close(pipe_in[READ_END]) == ERROR \
			|| close(pipe_in[WRITE_END]) == ERROR \
			|| close(pipe_out[READ_END]) == ERROR \
			|| close(pipe_out[WRITE_END]) == ERROR)
		exit_error("close(): ", PERROR);


	execute_program(cmd_info.cmd, cmd_info.p_path_split);
}
