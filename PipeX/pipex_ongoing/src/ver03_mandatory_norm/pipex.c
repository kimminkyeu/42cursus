/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:23 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/14 16:49:28 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[])
{
	int	fd_start;
	int	fd_end;
	int	stdio[2];

	if (ac != 5)
	{
		ft_printf("wrong number of input arguments");
		exit(EXIT_FAILURE);
	}
	fd_start = open(av[1], O_RDONLY);
	fd_end = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd_start < 0 || fd_end < 0)
	{
		perror("open():");
		exit(EXIT_FAILURE);
	}
	stdio[READ_END] = fd_start;
	stdio[WRITE_END] = fd_end;
	pipex(stdio, av, environ);
	return (0);
}

void	pipex(int *stdio, char *av[], char **environ)
{
	int		pid1;
	int		pipe_fd[2];
	char	**p_path_split;

	p_path_split = get_environ_path(environ);
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe: ");
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 == ERROR)
	{
		perror("fork: ");
		exit(EXIT_FAILURE);
	}
	if (pid1 != CHILD)
		run_process_pid(pid1, create_cmd_info(av[3], p_path_split), \
				pipe_fd, stdio);
	else if (pid1 == CHILD)
		run_process_pid(pid1, create_cmd_info(av[2], p_path_split), \
				stdio, pipe_fd);
}
