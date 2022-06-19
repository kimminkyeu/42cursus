/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:23 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/13 22:34:59 by minkyeki         ###   ########.fr       */
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

void	execute_program(char *cmd, char **p_path_split)
{
	char	**program_split;
	char	*p_path;
	int		i;

	program_split = ft_split(cmd, ' '); // "ls -al" --> ls || -al || null
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
}

char	**get_environ_path(char **environ)
{
	int		i;
	char	*p_path;
	char	**p_path_split;

	i = 0;
	p_path_split = NULL;
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
	return (p_path_split);
}

void	pipex(int fd_start, int fd_end, char *av[], char **environ)
{
	int	pid1;
	/** int	pid2; */
	int	pipe_fd[2];
	char **p_path_split;

	(void)fd_start;
	(void)fd_end;

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
	{
		dup2(fd_end, STDOUT_FILENO); // send data to outfile
		dup2(pipe_fd[READ_END], STDIN_FILENO); // read from child, not stdin

		close(fd_end); // TODO : really needed?
		close(pipe_fd[READ_END]); // after dup2, we dont need both fds
		close(pipe_fd[WRITE_END]);

		/* ---------------------------------------------------  
		 * NOTE: Checking total processes made by fork() */
		system("printf '\n--------------------------------\n' ");
		system("printf 'total process' && ps -ef | grep pipex | wc -l");
		system("printf '\n--------------------------------\n' ");
		/* -----------------------------------------------------  */

		waitpid(pid1, NULL, 0); // wait until it's child to finish
		execute_program(av[3], p_path_split);
	}
	else if (pid1 == CHILD) // if is child, do fork()
	{
		/** pid2 = fork(); */
		/** if (pid2 == ERROR) */
		/** { */
		/**     perror("fork: "); */
		/**     exit(EXIT_FAILURE); */
		/** } */

		/** 
		 * -----------------------------------------
		 * TODO & FIXME : How many pipes do i need?
		 * -----------------------------------------
		 * */

		/** if(pid2 != CHILD) // if is parent, then get data from it's child */
		/** { */
			dup2(fd_start, STDIN_FILENO); // get data from infile
			dup2(pipe_fd[WRITE_END], STDOUT_FILENO); // send data to pipe[WRITE]
			
			close(fd_start); // TODO : really needed?
			close(pipe_fd[READ_END]); // after dup2, we dont need both fds
			close(pipe_fd[WRITE_END]);

			/** waitpid(pid2, NULL, 0); // wait until it's child to finish */
			execute_program(av[2], p_path_split);
		/** } */
		/** else if (pid2 == CHILD) // if is child, then it is end. */
		/** { */
		/**     close(pipe_fd[READ_END]); */
		/**     close(pipe_fd[WRITE_END]); */
		/** } */
	}


	// for grep to stop listening.
	
	/** waitpid(pid1, NULL, 0); // make pid1 to wait until it's child process finish */
	/** waitpid(pid2, NULL, 0); // make pid2 to wait until it's child process finish */
}
