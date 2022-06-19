/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:23 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/15 17:33:05 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	main(int ac, char *av[])
{
	t_fd2	io_fd;

	if (ac < 5)
		exit_error("wrong number of input arguments\n", PUTSTR);
	io_fd.read = open(av[1], O_RDONLY);
	io_fd.write = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (io_fd.read < 0 || io_fd.write < 0)
		exit_error("open(): ", PERROR);
	pipex_bonus(io_fd, ac, av, environ);
	if (close(io_fd.read) == ERROR || close(io_fd.write) == ERROR)
		exit_error("close(): ", PERROR);
	return (0);
}

void	fork_and_run_child(pid_t *pid, char *cmd, char **p_path_split)
{
	t_fd2	pipe_fd;

	if (pipe(pipe_fd.fd) == PERROR)
		exit_error("pipe(): ", PERROR);
	*pid = fork();
	if (*pid == ERROR)
		exit_error("fork(): ", PERROR);
	if (*pid == CHILD)
	{
		dup2(pipe_fd.write, STDOUT_FILENO);
		if (close(pipe_fd.read) == ERROR || close(pipe_fd.write) == ERROR)
			exit_error("close(): ", PERROR);
		execute_program(cmd, p_path_split);
	}
	dup2(pipe_fd.read, STDIN_FILENO);
	if (close(pipe_fd.read) == ERROR || close(pipe_fd.write) == ERROR)
		exit_error("close(): ", PERROR);
}

void	pipex_bonus(t_fd2 io_fd, int ac, char *av[], char **environ)
{
	int		i;
	pid_t	pid;
	char	**p_path_split;

	pid = 0;
	p_path_split = get_environ_path(environ);
	if (dup2(io_fd.read, STDIN_FILENO) == ERROR)
		exit_error("dup2(): ", PERROR);
	i = 2;
	while (i < ac - 2)
		fork_and_run_child(&pid, av[i++], p_path_split);
	dup2(io_fd.write, STDOUT_FILENO);
	if (close(io_fd.write) == ERROR)
		exit_error("close(): ", PERROR);
	execute_program(av[ac - 2], p_path_split);
	waitpid(pid, NULL, 0);
}
