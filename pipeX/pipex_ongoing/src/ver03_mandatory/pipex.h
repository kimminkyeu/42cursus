/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:32:46 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/14 16:25:41 by minkyeki         ###   ########.fr       */
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
# define CHILD (0)
# define ERROR (-1)
# define READ_END (0)
# define WRITE_END (1)

/* for cmd array (Ex. name = "grep" | option "hello" ) */
# define NAME	(0)
# define OPTION	(1)

/* for access() */
# define ACCESS_OK	(0)

/* for cmd_info */
typedef struct s_cmd {
	char	*cmd;
	char	**p_path_split;
}	t_cmd;

/* environment variable */
extern char		**environ;

/* main pipex logic */
extern void		pipex(int *stdio, char *av[], char **environ);

/* * Below functions are pipex_utils functions */
extern void		free_data(char **program_split, char **p_path_split);

extern void		execute_program(char *cmd, char **p_path_split);

extern char		**get_environ_path(char **environ);

extern void		run_process_pid(int pid, t_cmd cmd_info, int *pipe_in, int *pipe_out);

extern t_cmd	create_cmd_info(char *cmd, char **cmd_path);

#endif /* PIPEX_H */
