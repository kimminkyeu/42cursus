/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:32:46 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/15 22:01:47 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* for exit and free, malloc */
# include <stdlib.h>
/* for perror */
# include <stdio.h>
/* for process system call */
# include <unistd.h>
/* for wait function */
# include <sys/wait.h>
/* for open() */
# include <fcntl.h>
/* for libft functions */
# include "libft.h"

/* for pipe() and fork() */
# define CHILD		(0)
# define READ_END	(0)
# define WRITE_END	(1)

/* for cmd array (Ex. name = "grep" | option "hello" ) */
# define NAME		(0)
# define OPTION		(1)

/* for access() */
# define ACCESS_OK	(0)

/* for error_exit() flag */
# define ERROR		(-1)
# define PERROR		(1)
# define PUTSTR		(0)

/* here doc limiter */
# define IS_SAME	(0)

typedef union u_fd2 {
	struct {
		int	read;
		int	write;
	};
	int	fd[2];
}	t_fd2;

/* Environment variable */
extern char		**environ;

/* @ Main pipex logic */
/* ----------------------------------------------------- */
extern void		pipex(t_fd2 io_fd, char *av[]);
extern void		run_process_pid(char *cmd, char **p_path, \
		t_fd2 pipe_in, t_fd2 pipe_out);

/* @ Main pipex bonus logic */
extern void		pipex_bonus(int cmd_start_idx, t_fd2 io_fd, int ac, char *av[]);
extern void		handle_here_doc(char *here_doc, char *limiter);
extern void		fork_and_run_child(char *cmd, char **p_path_split);
/* ----------------------------------------------------- */

/* @ Below functions are pipex_utils functions */
/* ----------------------------------------------------- */
extern void		execute_program(char *cmd, char **p_path_split);
extern char		**get_environ_path(void);
/* if is_perror, then message is passed to perror function.
 * else, it is passed to ft_putstr_fd(->stderr) */
extern void		exit_error(char *messege, int is_perror);
extern void		free_data(char **program_split, char **p_path_split);
/* ----------------------------------------------------- */

#endif /* PIPEX_H */
