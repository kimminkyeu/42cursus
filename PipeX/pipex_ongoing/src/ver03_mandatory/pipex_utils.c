/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:35:46 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/14 16:17:55 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	execute_program(char *cmd, char **p_path_split)
{
	char	**program_split;
	char	*p_path;
	int		i;

	program_split = ft_split(cmd, ' '); // "ls -al" --> ls || -al || null
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
		p_path = ft_strnstr(environ[i], "PATH", 4); // find PATH env
		if (p_path != NULL)
		{
			p_path_split = ft_split(p_path + 5, ':');
			if (p_path_split == NULL)
			{
				perror("path split():");
				exit(EXIT_FAILURE);
			}
			break ;
		}
		i++; // MEMO : do i need to handle no PATH env??
	}
	return (p_path_split);
}

void	run_process_pid(int pid, t_cmd cmd_info, int *pipe_in, int *pipe_out)
{
	dup2(pipe_in[READ_END], STDIN_FILENO); // read from child, not stdin
	dup2(pipe_out[WRITE_END], STDOUT_FILENO); // send data to outfile

	close(pipe_in[READ_END]); // TODO : really needed?
	close(pipe_in[WRITE_END]); // TODO : really needed?
	close(pipe_out[READ_END]); // after dup2, we dont need both fds
	close(pipe_out[WRITE_END]);

	waitpid(pid, NULL, 0); // wait until it's child to finish
	execute_program(cmd_info.cmd, cmd_info.p_path_split);
}

t_cmd	create_cmd_info(char *cmd, char **cmd_path)
{
	t_cmd	tmp;

	tmp.cmd = cmd;
	tmp.p_path_split = cmd_path;
	return (tmp);
}
