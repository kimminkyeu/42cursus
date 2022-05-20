/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:23 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/15 21:55:34 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char *av[])
{
	int		infile_fd;
	int		outfile_fd;
	t_fd2	io_fd;

	if (ac != 5)
		exit_error("wrong number of input arguments\n", PUTSTR);
	infile_fd = open(av[1], O_RDONLY);
	outfile_fd = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (infile_fd < 0 || outfile_fd < 0)
		exit_error("open(): ", PERROR);
	io_fd.read = infile_fd;
	io_fd.write = outfile_fd;
	pipex(io_fd, av);
	if (close(io_fd.read) == ERROR || close(io_fd.write) == ERROR)
		exit_error("close(): ", PERROR);
	return (0);
}

void	pipex(t_fd2 io_fd, char *av[])
{
	pid_t	pid1;
	pid_t	pid2;
	t_fd2	pipe_fd;
	char	**p_path_split;

	p_path_split = get_environ_path();
	if (pipe(pipe_fd.fd) == -1)
		exit_error("pipe(): ", PERROR);
	pid1 = fork();
	if (pid1 == ERROR)
		exit_error("fork(): ", PERROR);
	if (pid1 == CHILD)
		run_process_pid(av[2], p_path_split, io_fd, pipe_fd);
	pid2 = fork();
	if (pid2 == ERROR)
		exit_error("fork(): ", PERROR);
	if (pid2 == CHILD)
		run_process_pid(av[3], p_path_split, pipe_fd, io_fd);
	if (close(pipe_fd.read) == ERROR \
			|| close(pipe_fd.write) == ERROR)
		exit_error("close(): ", PERROR);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void	run_process_pid(char *cmd, char **p_path, t_fd2 pipe_in, t_fd2 pipe_out)
{
	if (dup2(pipe_in.read, STDIN_FILENO) == ERROR \
			|| dup2(pipe_out.write, STDOUT_FILENO) == ERROR)
		exit_error("dup2(): ", PERROR);
	if (close(pipe_in.read) == ERROR \
			|| close(pipe_in.write) == ERROR \
			|| close(pipe_out.read) == ERROR \
			|| close(pipe_out.write) == ERROR)
		exit_error("close(): ", PERROR);
	execute_program(cmd, p_path);
}
