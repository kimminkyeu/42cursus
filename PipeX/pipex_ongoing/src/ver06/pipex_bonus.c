/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:23 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/15 16:03:43 by minkyeki         ###   ########.fr       */
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

	ft_printf("infile:%d outfile:%d\n\n", io_fd.read, io_fd.write);
	pipex_bonus(io_fd, ac, av, environ);

	/* ./pipex infile "cmd1" "cmd2" "cmd3" outfile */

	if (close(io_fd.read) == ERROR || close(io_fd.write) == ERROR)
		exit_error("close(): ", PERROR);
	return (0);
}

void	pipex_bonus(t_fd2 io_fd, int ac, char *av[], char **environ)
{
	int		i;
	pid_t	pid;
	t_fd2	pipe_fd;
	char	**p_path_split;

	/** (1) get PATH info of cmd progams  */
	p_path_split = get_environ_path(environ);

	/** (2) start with infile and outfile */
	if (dup2(io_fd.read, STDIN_FILENO) == ERROR)
		exit_error("dup2(): ", PERROR);

	/** TODO(1): handle Error statement */
	/** TODO(2): check if i use printf, not ft_printf */

	i = 2;
	while (i < ac - 2) // run before last cmd
	{
		if(pipe(pipe_fd.fd) == PERROR)
			exit_error("pipe(): ", PERROR);
		pid = fork();
		if (pid == ERROR)
			exit_error("fork(): ", PERROR);
		if (pid == CHILD) // if child, set stdout (write)
		{
			ft_printf("cmd: %s\n\n", av[i]);
			dup2(pipe_fd.write, STDOUT_FILENO);
			close(pipe_fd.read);
			close(pipe_fd.write);
			execute_program(av[i], p_path_split);
		}
		// if parent, set stdin (read)
		dup2(pipe_fd.read, STDIN_FILENO);
		close(pipe_fd.read);
		close(pipe_fd.write);
		i++;
	}
	pid = fork();
	if (pid == ERROR)
		exit_error("fork(): ", PERROR);
	if (pid == CHILD)
	{
		dup2(io_fd.write, STDOUT_FILENO);
		close(pipe_fd.read);
		close(pipe_fd.write);
		execute_program(av[ac - 2], p_path_split);
	}
	close(pipe_fd.read);
	close(pipe_fd.write);
	waitpid(pid, NULL, 0);

		/** TODO: close and wait */
}
