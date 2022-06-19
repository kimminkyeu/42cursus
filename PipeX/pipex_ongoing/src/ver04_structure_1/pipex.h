/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:32:46 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/14 17:54:15 by minkyeki         ###   ########.fr       */
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
# include "../include/libft.h"

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

/* for cmd_info */
typedef struct s_cmd {
	char	*cmd;
	char	**p_path_split;
}	t_cmd;

/* Environment variable */
extern char		**environ;

/* @ Main pipex logic */
/* ----------------------------------------------------- */
extern void		pipex(int *stdio, char *av[], char **environ);
/* ----------------------------------------------------- */

/* @ Below functions are pipex_utils functions */
/* ----------------------------------------------------- */
extern void		execute_program(char *cmd, char **p_path_split);

extern char		**get_environ_path(char **environ);

extern void		run_process_pid(int pid, t_cmd cmd_info, \
		int *pipe_in, int *pipe_out);
/* ----------------------------------------------------- */

/* @ Below functions are pipex helper functions for norm*/
/* ----------------------------------------------------- */
extern t_cmd	create_cmd_info(char *cmd, char **cmd_path);

/* if is_perror, then message is passed to perror function.
 * else, it is passed to ft_putstr_fd(->stderr) */
extern void		exit_error(char *messege, int is_perror);

extern void		free_data(char **program_split, char **p_path_split);
/* ----------------------------------------------------- */

#endif /* PIPEX_H */
