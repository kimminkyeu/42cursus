/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:57:07 by minkyeki          #+#    #+#             */
/*   Updated: 2022/08/04 20:43:42 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Standard library */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>

/** Readline library */
#include <readline/readline.h>
#include <readline/history.h>

#include "minishell.h"
#include "helper.h"
#include "../../include/builtin.h"
#include "../../include/libft.h"

extern int	g_is_sig_interupt;

/** NOTE : Use of waitpid() is to make sure
 *         sig_handler run only at main process. 
 **/
void	sig_ctrl_c(int signal)
{
	int	pid;

	pid = waitpid(-1, NULL, WNOHANG);
	g_is_sig_interupt = true;
	if (signal == SIGINT)
	{
		if (pid == -1)
		{
			rl_replace_line("", 1);
			ft_putstr_fd("\n", STDOUT_FILENO);
			rl_on_new_line();
			rl_redisplay();
		}
		else
		{
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
	}
}

void	set_signal(void)
{
	signal(SIGINT, sig_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

void	*new_pid(pid_t pid)
{
	pid_t	*tmp;

	tmp = ft_calloc(1, sizeof(*tmp));
	*tmp = pid;
	return (tmp);
}

void	wait_every_pid(t_shell_config *config)
{
	t_list	*cur;
	int		w_status;

	cur = config->pid_list;
	while (cur != NULL)
	{
		if (waitpid(-1, &w_status, 0) == config->last_cmd_pid)
			config->last_cmd_wstatus = w_status;
		if (WIFSIGNALED(config->last_cmd_wstatus))
			config->last_cmd_wstatus += 128;
		cur = cur->next;
	}
	ft_lstclear(&config->pid_list, free);
}
