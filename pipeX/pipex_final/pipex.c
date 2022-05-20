/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:23 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/17 16:44:58 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[])
{
	t_pipex	pipex;

	pipex.pid_list = NULL;
	pipex.is_here_doc = 0;
	if (ac > 1 && ft_strncmp(av[1], "here_doc", 9) == IS_SAME)
		pipex.is_here_doc = 1;
	if (ac < 5 + pipex.is_here_doc)
		exit_error("wrong number of input arguments\n", PUTSTR, EXIT_FAILURE);
	if (pipex.is_here_doc == 1)
		handle_here_doc(av[1], av[2]);
	pipex.io_fd.read = open(av[1], O_RDONLY);
	pipex.io_fd.write = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.io_fd.read < 0)
		perror(av[1]);
	if (pipex.io_fd.write < 0)
	{
		perror(av[ac - 1]);
		exit(EXIT_FAILURE);
	}
	pipex.env_path = get_environ_path();
	run_pipex(2 + pipex.is_here_doc, &pipex, ac, av);
	return (pipex.w_status >> 8 & 0xFF);
}

void	handle_here_doc(char *here_doc, char *limiter)
{
	t_fd2	io_fd;
	char	*line;

	io_fd.read = STDIN_FILENO;
	io_fd.write = open(here_doc, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (io_fd.write < 0)
		exit_error("open()", PERROR, EXIT_FAILURE);
	limiter = ft_strjoin(limiter, "\n");
	line = get_next_line(STDIN_FILENO);
	while (ft_strncmp(limiter, line, ft_strlen(limiter) + 1) != IS_SAME)
	{
		free(line);
		ft_putstr_fd(line, io_fd.write);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	free(limiter);
	if (close(io_fd.write) == ERROR)
		exit_error("close()", PERROR, EXIT_FAILURE);
}

void	run_pipex(int cmd_start, t_pipex *pipex, int ac, char *av[])
{
	int		i;

	dup2(pipex->io_fd.read, STDIN_FILENO);
	close(pipex->io_fd.read);
	i = cmd_start;
	while (i < ac - 2)
		fork_and_run(av[i++], pipex, NOT_LAST_CMD);
	dup2(pipex->io_fd.write, STDOUT_FILENO);
	close(pipex->io_fd.write);
	fork_and_run(av[ac - 2], pipex, LAST_CMD);
	waitpid(pipex->pid_curr, &pipex->w_status, 0);
	if (ft_strncmp(av[1], "here_doc", 9) == IS_SAME)
		unlink(av[1]);
}

void	fork_and_run(char *cmd, t_pipex *pipex, int is_last_cmd)
{
	t_fd2	pipe_fd;
	pid_t	pid;

	if (pipe(pipe_fd.fd) == PERROR)
		exit_error("pipe()", PERROR, EXIT_FAILURE);
	pid = fork();
	if (pid == ERROR)
		exit_error("fork()", PERROR, EXIT_FAILURE);
	if (pid != CHILD)
	{
		pipex->pid_curr = pid;
		dup2(pipe_fd.read, STDIN_FILENO);
		close(pipe_fd.read);
		close(pipe_fd.write);
	}
	else if (pid == CHILD)
	{
		if (!is_last_cmd)
		{
			dup2(pipe_fd.write, STDOUT_FILENO);
			close(pipe_fd.read);
			close(pipe_fd.write);
		}
		execute_program(cmd, pipex->env_path);
	}
}
