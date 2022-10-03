/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:21:34 by minkyeki          #+#    #+#             */
/*   Updated: 2022/08/03 20:55:45 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "executer.h"
#include "../builtin/environ.h"
#include "../main/minishell.h"
#include "../lexer/token.h"
#include "../main/signal_handle.h"
#include "../main/print_error.h"

#define PIPE_ERROR		(1)
#define FORK_ERROR		(-1)
#define CHILD			(0)

#define READ			(0)
#define WRITE			(1)

#define EXIT_COMMAND_NOT_FOUND (127)

static int	pipe_and_fork(int *pipe_fd, pid_t *pid)
{
	if (pipe(pipe_fd) == PIPE_ERROR)
	{
		ft_perror("pipe error");
		return (ERROR);
	}
	*pid = fork();
	if (*pid == FORK_ERROR)
	{
		ft_perror("fork error");
		return (ERROR);
	}
	return (SUCCESS);
}

static void	child_process(int *pipe_fd, t_tree *node, t_shell_config *config)
{
	int	tmp_fd;

	if (node->is_last_pipe_cmd)
		dup2(config->stdout_backup, pipe_fd[WRITE]);
	tmp_fd = pipe_fd[READ];
	open_redirection(pipe_fd, node->redirection, config);
	if (tmp_fd != pipe_fd[READ])
		dup2(pipe_fd[READ], STDIN_FILENO);
	dup2(pipe_fd[WRITE], STDOUT_FILENO);
	close(pipe_fd[WRITE]);
	close(pipe_fd[READ]);
}

static void	parent_process(int *pipe_fd, t_tree *node, \
				t_shell_config *config, pid_t pid)
{
	ft_lstadd_back(&config->pid_list, ft_lstnew(new_pid(pid)));
	if (node->is_last_pipe_cmd)
	{
		config->last_cmd_pid = pid;
		dup2(config->stdin_backup, STDIN_FILENO);
		dup2(config->stdout_backup, STDOUT_FILENO);
	}
	if (!node->is_last_pipe_cmd)
		dup2(pipe_fd[READ], STDIN_FILENO);
	close(pipe_fd[WRITE]);
	close(pipe_fd[READ]);
}

/* exec_subshell()
** NOTES:
** 1) char *line: input for subshell
** STEPS:
** 1) set_up new_config
** 2) delete bracket ( )
** 3) fork and run subshell
** 4) get subshell's exit status and exit
*/

int	exec_subshell(t_tree *node, t_string *str, t_shell_config *config)
{
	t_shell_config	new_config;
	pid_t			pid;
	int				pipe_fd[2];
	char			*line;

	load_shell_config(&new_config, *(config->envp));
	line = ft_substr(str->text, 1, ft_strlen(str->text) - 2);
	if (pipe_and_fork(pipe_fd, &pid) == ERROR)
		return (ERROR);
	if (pid == CHILD)
	{
		child_process(pipe_fd, node, config);
		exit(run_shell(line, &new_config));
	}
	else
	{
		parent_process(pipe_fd, node, config, pid);
		free(line);
		delete_environ(new_config.envp);
		free(new_config.envp);
		return (SUCCESS);
	}
}
