/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:23 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/13 21:35:37 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[])
{
	int fd_start;
	int fd_end;

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
	pipex(fd_start, fd_end, av, environ);
	return (0);
}
	
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

void	pipex(int fd_start, int fd_end, char *av[], char **environ)
{
	int	pid1;
	int	pid2;
	int i;
	char *p_path;
	char **p_path_split;

	char **program_split;
	int	pipe_fd[2];


	(void)fd_start;
	(void)fd_end;
	p_path_split = NULL;
	i = 0;
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

	// child ---> parent --> grandparent --> ....
	if (pid1 == CHILD)
	{
		// send to pipe instead of stdout
		dup2(pipe_fd[WRITE_END], STDOUT_FILENO);
		close(pipe_fd[READ_END]); // after dup2, we dont need both fds
		close(pipe_fd[WRITE_END]);

		program_split = ft_split(av[2], ' '); // "ls -al" --> ls || -al || null
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
	} // endif : IF_CHILD1

	pid2 = fork();
	if (pid2 == ERROR)
	{
		perror("fork: ");
		exit(EXIT_FAILURE);
	}
	if (pid2 == CHILD) // if parent --> wait
	{
		dup2(pipe_fd[READ_END], STDIN_FILENO);
		close(pipe_fd[WRITE_END]);
		close(pipe_fd[READ_END]);

		program_split = ft_split(av[3], ' '); // "ls -al" --> ls || -al || null
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
		ft_putstr_fd(": command not found\n", STDERR_FILENO); // if fail, then process doesn't finish
		free_data(program_split, p_path_split);
		exit(EXIT_FAILURE);
	}

	// for grep to stop listening.
	close(pipe_fd[READ_END]);
	close(pipe_fd[WRITE_END]);

	waitpid(pid1, NULL, 0); // make pid1 to wait until it's child process finish
	waitpid(pid2, NULL, 0); // make pid2 to wait until it's child process finish
	
}
