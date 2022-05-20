/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:23 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/14 20:35:09 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[])
{
	int	fd_start;
	int	fd_end;
	int	stdio[2];

	if (ac != 5)
		exit_error("wrong number of input arguments\n", PUTSTR);
	fd_start = open(av[1], O_RDONLY);
	fd_end = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd_start < 0 || fd_end < 0)
		exit_error("open(): ", PERROR);

	stdio[READ_END] = fd_start;
	stdio[WRITE_END] = fd_end;

	printf("fd_start / end : (%d/%d)\n", fd_start, fd_end);
	pipex(stdio, av, environ);

	/* NOTE : 여기 필요함?  */
	if (close(stdio[READ_END]) == ERROR || close(stdio[WRITE_END]) == ERROR)
		exit_error("close(): ", PERROR);

	return (0);
}

void	pipex(int *stdio, char *av[], char **environ)
{
	int		pid1; // child 1
	int		pid2; // child 2
	int		pipe_fd[2];
	char	**p_path_split;

	p_path_split = get_environ_path(environ);

	if (pipe(pipe_fd) == -1)
		exit_error("pipe(): ", PERROR);

	/** 자식 1 생성 */
	pid1 = fork();
	if (pid1 == ERROR)
		exit_error("fork(): ", PERROR);
	if (pid1 == CHILD) // if child, do ping or ls-al
		run_process_pid(pid1, create_cmd_info(av[2], p_path_split), stdio, pipe_fd);

	/** NOTE : 부모만 하단 코드 실행함. */

	/** 자식 2 생성 */
	pid2 = fork();
	if (pid2 == ERROR)
		exit_error("fork(): ", PERROR);
	if (pid2 == CHILD) // if child2, do grep
		run_process_pid(pid2, create_cmd_info(av[3], p_path_split), pipe_fd, stdio);


	/** 부모의 파일 디스크립터 종료 
	 * NOTE : waitpid를 호출하기 전에 pipe를 닫아줘야 한다. 왜 ?? 
	 * */
	if (close(pipe_fd[READ_END]) == ERROR || close(pipe_fd[WRITE_END]) == ERROR)
		exit_error("close(): ", PERROR);


	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
