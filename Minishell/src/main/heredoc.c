/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:20:24 by minkyeki          #+#    #+#             */
/*   Updated: 2022/08/04 21:12:09 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdio.h>
#include <readline/readline.h>
#include <fcntl.h>
#include <signal.h>

#include "minishell.h"
#include "heredoc.h"
#include "../lexer/token.h"
#include "print_error.h"

#define PIPE_ERROR		(1)
#define FORK_ERROR		(-1)

#define CHILD (0)
#define NO_STOP_OR_EXIT_CHILD (0)

extern int	g_is_sig_interupt;

static void	expand_token(t_token *tok)
{
	t_iterator	iter;
	t_string	*expanded_str;
	char		c;

	init_iterator(&iter, tok->str->text);
	expanded_str = new_string(tok->str->capacity);
	while (iter.f_has_next(&iter))
	{
		c = iter.f_next(&iter);
		if (c == '\'' || c == '\"')
		{
			expand_quote(expanded_str, &iter, c);
			tok->type = E_TYPE_REDIR_ARG_HEREDOC_QUOTED;
		}
		else
			expanded_str->f_push_back(expanded_str, c);
	}
	delete_string(&tok->str);
	tok->str = expanded_str;
}

/* NOTES:
** 0) keep checking pid.
** 1) if non-zero pid is returned, return SUCCESS.
** 2) if zero pid is returned but ^C occcured, return ERROR.
*/

static int	parent_process(int *pipefd, pid_t pid, t_token *tok)
{
	int	wstatus;

	close(pipefd[WRITE]);
	tok->heredoc_fd = pipefd[READ];
	waitpid(pid, &wstatus, 0);
	if (WIFSIGNALED(wstatus))
		return (ERROR);
	return (SUCCESS);
}

static void	child_process(int *pipefd, t_token *tok)
{
	char	*line;

	signal(SIGINT, SIG_DFL);
	close(pipefd[READ]);
	while (true)
	{
		line = readline_prompt_heredoc();
		if (line != NULL && *line == '\0')
		{
			free(line);
			line = NULL;
			continue ;
		}
		else if (line == NULL || is_limiter(line, tok->str->text) == true)
			exit(EXIT_SUCCESS);
		write(pipefd[WRITE], line, ft_strlen(line));
		write(pipefd[WRITE], "\n", 2);
		free(line);
	}
}

static int	open_heredoc(t_token *tok)
{
	int		pipefd[2];
	pid_t	pid;
	int		status;

	status = SUCCESS;
	if (pipe(pipefd) == PIPE_ERROR)
	{
		ft_perror("pipe error");
		return (ERROR);
	}
	pid = fork();
	if (pid == FORK_ERROR)
	{
		ft_perror("fork error");
		return (ERROR);
	}
	if (pid == CHILD)
		child_process(pipefd, tok);
	else
		status = parent_process(pipefd, pid, tok);
	return (status);
}

int	set_heredoc(t_list *tokens)
{
	t_list	*cur;
	t_token	*tok;

	cur = tokens;
	while (cur)
	{
		tok = cur->content;
		if (tok->type == E_TYPE_REDIR_HEREDOC)
		{
			cur = cur->next;
			tok = cur->content;
			expand_token(tok);
			if (open_heredoc(tok) == ERROR)
				return (ERROR);
		}
		cur = cur->next;
	}
	return (SUCCESS);
}
