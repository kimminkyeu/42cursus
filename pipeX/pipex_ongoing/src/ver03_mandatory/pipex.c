/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:23 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/14 16:18:23 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[])
{
	int fd_start;
	int fd_end;
	int	stdio[2];
	/** ./pipex infile "ls -al" "grep a" outfile */
	if (ac < 3) // NOTE : 3개면 적당?
	{
		ft_printf("wrong input arguments");
		exit(EXIT_FAILURE);
	}
	fd_start = open(av[1], O_RDONLY);
	// 참고: https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=bestheroz&logNo=113881732
	fd_end = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);

	if (fd_start < 0 || fd_end < 0)
	{
		perror("open():");
		exit(EXIT_FAILURE);
	}
	stdio[0] = fd_start;
	stdio[1] = fd_end;
	pipex(stdio, av, environ);
	return (0);
}
	
void	pipex(int *stdio, char *av[], char **environ)
{
	int		pid1;
	int		pipe_fd[2];
	char	**p_path_split;

	p_path_split = get_environ_path(environ); // get PATH in environ
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
	if (pid1 != CHILD) // if is parent, then get data from it's child
		run_process_pid(pid1, create_cmd_info(av[3], p_path_split), pipe_fd, stdio);
	else if (pid1 == CHILD) // if is child, do fork()
		run_process_pid(pid1, create_cmd_info(av[2], p_path_split), stdio, pipe_fd);
}
