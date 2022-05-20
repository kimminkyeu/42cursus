/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:23 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/15 22:02:46 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* TODO : check memory leak  */

int	main(int ac, char *av[])
{
	t_fd2	io_fd;
	int		is_here_doc;

	is_here_doc = 0;
	if (ft_strncmp(av[1], "here_doc", 9) == IS_SAME)
		is_here_doc = 1;
	if (ac < 5 + is_here_doc)
		exit_error("wrong number of input arguments\n", PUTSTR);
	if (is_here_doc == 1)
	{
		ft_printf("pipe here_doc\n");
		handle_here_doc(av[1], av[2]);
	}
	io_fd.read = open(av[1], O_RDONLY);
	io_fd.write = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (io_fd.read < 0 || io_fd.write < 0)
		exit_error("open(): ", PERROR);
	pipex_bonus(2 + is_here_doc, io_fd, ac, av);
	return (0);
}

void	handle_here_doc(char *here_doc, char *limiter)
{
	t_fd2	io_fd;
	char	*line;

	io_fd.read = STDIN_FILENO;
	io_fd.write = open(here_doc, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (io_fd.write < 0)
		exit_error("open(): ", PERROR);
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
		exit_error("close(): ", PERROR);
}

void	pipex_bonus(int cmd_start, t_fd2 io_fd, int ac, char *av[])
{
	int		i;
	char	**p_path_split;

	p_path_split = get_environ_path();
	if (dup2(io_fd.read, STDIN_FILENO) == ERROR)
		exit_error("dup2(): ", PERROR);
	close(io_fd.read);
	i = cmd_start;
	while (i < ac - 2)
		fork_and_run_child(av[i++], p_path_split);
	dup2(io_fd.write, STDOUT_FILENO);
	if (close(io_fd.write) == ERROR)
		exit_error("close(): ", PERROR);
	if (ft_strncmp(av[1], "here_doc", 9) == IS_SAME)
		unlink(av[1]);
	execute_program(av[ac - 2], p_path_split);
}

void	fork_and_run_child(char *cmd, char **p_path_split)
{
	t_fd2	pipe_fd;
	pid_t	pid;

	if (pipe(pipe_fd.fd) == PERROR)
		exit_error("pipe(): ", PERROR);
	pid = fork();
	if (pid == ERROR)
		exit_error("fork(): ", PERROR);
	if (pid == CHILD)
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
