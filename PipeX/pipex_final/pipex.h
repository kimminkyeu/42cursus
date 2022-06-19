/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:32:46 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/17 16:45:10 by minkyeki         ###   ########.fr       */
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
# include "libft/include/libft.h"

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

/* for is_last_cmd flag */
# define LAST_CMD		(1)
# define NOT_LAST_CMD	(0)

typedef union u_fd2 {
	struct {
		int	read;
		int	write;
	};
	int	fd[2];
}	t_fd2;

/* struct for pipex */
typedef struct s_pipex {
	char	is_here_doc;
	t_fd2	io_fd;
	char	**env_path;
	t_list	*pid_list;
	pid_t	pid_curr;
	int		w_status;
}	t_pipex;

/* Environment variable */
extern char		**environ;

/* @ Main pipex logic */
/* ----------------------------------------------------- */
extern void		run_pipex(int cmd_start_idx, \
		t_pipex *pipex, int ac, char *av[]);
extern void		handle_here_doc(char *here_doc, char *limiter);
extern void		fork_and_run(char *cmd, t_pipex *pipex, int is_last_cmd);
/* ----------------------------------------------------- */

/* @ Below functions are pipex_utils functions */
/* ----------------------------------------------------- */
extern void		execute_program(char *cmd, char **p_path_split);
extern char		**get_environ_path(void);

/* if is_perror, then message is passed to perror function.
 * else, it is passed to ft_putstr_fd(->stderr) */
extern void		exit_error(char *messege, int is_perror, int exit_code);
extern void		free_data(char **program_split, char **p_path_split);
extern void		run_execve(char *cmd, char **program_split);
/* ----------------------------------------------------- */

#endif /* PIPEX_H */
