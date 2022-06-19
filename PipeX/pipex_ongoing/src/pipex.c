/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:23 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/16 20:36:58 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* TODO : check memory leak  */

void	del_pid(void *content)
{
	*(pid_t *)content = 0;
	return ;
}

int	main(int ac, char *av[])
{
	t_pipex	pipex;

	pipex.pid_list = NULL;
	pipex.is_here_doc = 0;


	if (ft_strncmp(av[1], "here_doc", 9) == IS_SAME)
		pipex.is_here_doc = 1;

	/** check argument cound */
	if (ac < 5 + pipex.is_here_doc)
		exit_error("wrong number of input arguments\n", PUTSTR, EXIT_FAILURE);


	/** check if ./pipex */

	if (pipex.is_here_doc == 1)
	{
		ft_printf("pipe here_doc\n");
		handle_here_doc(av[1], av[2]);
	}

	/** ./pipex here_doc "stop" cmd1 cmd2 outfile  */
	/** ./pipex infile cmd1 cml2 outfile  */

	/** Handling File permision each */
	pipex.io_fd.read = open(av[1], O_RDONLY);
	pipex.io_fd.write = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.io_fd.read < 0)
		perror(av[1]);
	if (pipex.io_fd.write < 0)
		perror(av[ac - 1]);
	if (pipex.io_fd.read < 0 || pipex.io_fd.write < 0)
		exit(EXIT_FAILURE);

	/**  TODO : (1) 두 파일 모두 open error 날 수 있음. 둘 다 오류일 경우 둘다 처리. 
	 *          (1) 모든 프로세스는 자식에서 실행해야 한다. (main이 아님)
	 *		    (5) 구조체로 정리하기
	 *
	 *		    (2) ./pipex 와 pipex 구분해서 예외처리 --> 이건 솔직히 에바쎄바.
	 *		    (4) single quote double quote 구분?
	 *		    (3) main에서 모든 pid를 wait한 뒤에 마지막 cmd의 wstatus 반환 (비트쉬프트?)
	 *
	 *		    (6) 파일 open 권한 체크. 만약 권한이 read가 안되면 에러처리
	 * */

	pipex.env_path = get_environ_path();
	run_pipex(2 + pipex.is_here_doc, &pipex, ac, av);

	/** free pid_list */
	ft_lstclear(&(pipex.pid_list), del_pid);

	/** checking leaks */
	system("leaks pipex > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (pipex.w_status);
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
	if (pid == CHILD)
	{
		// if it is last cmd, then do not dup2
		if (!is_last_cmd && dup2(pipe_fd.write, STDOUT_FILENO) == ERROR)
			exit_error("dup2()", PERROR, EXIT_FAILURE);
		if (close(pipe_fd.read) == ERROR || close(pipe_fd.write) == ERROR)
			exit_error("close()", PERROR, EXIT_FAILURE);
		execute_program(cmd, pipex->env_path);
	}

	/** add to list for main process to wait	 */
	if (dup2(pipe_fd.read, STDIN_FILENO) == ERROR)
			exit_error("dup2()", PERROR, EXIT_FAILURE);
	if (close(pipe_fd.read) == ERROR || close(pipe_fd.write) == ERROR)
		exit_error("close()", PERROR, EXIT_FAILURE);

	ft_lstadd_back(&(pipex->pid_list), ft_lstnew(&pid));
}

/** return last cmd's wstatus  */
void	run_pipex(int cmd_start, t_pipex *pipex, int ac, char *av[])
{
	int		i;
	t_list	*pid_curr;

	if (dup2(pipex->io_fd.read, STDIN_FILENO) == ERROR)
		exit_error("dup2()", PERROR, EXIT_FAILURE);

	if (close(pipex->io_fd.read) == ERROR)
		exit_error("close()", PERROR, EXIT_FAILURE);

	i = cmd_start;

	/** run until last cmd */
	while (i < ac - 2)
		fork_and_run(av[i++], pipex, NOT_LAST_CMD);

	/** Last Cmd must write to outfile */
	if (dup2(pipex->io_fd.write, STDOUT_FILENO) == ERROR)
		exit_error("dup2()", PERROR, EXIT_FAILURE);
	if (close(pipex->io_fd.write) == ERROR)
		exit_error("close()", PERROR, EXIT_FAILURE);

	/** Run last cmd */
	fork_and_run(av[ac - 2], pipex, LAST_CMD);
		
	/** no need for here_doc, so delete */
	if (ft_strncmp(av[1], "here_doc", 9) == IS_SAME)
		unlink(av[1]);

	/** wait all pids in main process */
	pid_curr = pipex->pid_list;
	while (pid_curr->next != NULL)
	{
		waitpid(*((pid_t *)(pid_curr->content)), NULL, 0);
		pid_curr = pid_curr->next;
	}
	waitpid(*((pid_t *)(pid_curr->content)), &pipex->w_status, 0);
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

