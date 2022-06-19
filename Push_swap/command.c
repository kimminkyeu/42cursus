/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:13:56 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/17 15:26:52 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	optimize_2cmd(t_darray *prev_cmd, t_darray *new_cmd);
size_t	optimize_3cmd(t_darray *prev_cmd, t_darray *new_cmd);

const char	*get_cmd_string(int cmd_code)
{
	if (cmd_code == PA)
		return ("pa");
	else if (cmd_code == PB)
		return ("pb");
	else if (cmd_code == SA)
		return ("sa");
	else if (cmd_code == SB)
		return ("sb");
	else if (cmd_code == RA)
		return ("ra");
	else if (cmd_code == RB)
		return ("rb");
	else if (cmd_code == RRA)
		return ("rra");
	else if (cmd_code == RRB)
		return ("rrb");
	else if (cmd_code == SS)
		return ("ss");
	else if (cmd_code == RR)
		return ("rr");
	else if (cmd_code == RRR)
		return ("rrr");
	else
		return ("???");
}

void	print_cmd(t_darray *cmd)
{
	size_t	i;
	int		cmd_code;

	i = -1;
	while (++i < cmd->size)
	{
		cmd_code = *((int *)(cmd->data[i]));
		ft_printf("%s\n", get_cmd_string(cmd_code));
	}
}

void	push_cmd(t_darray *cmd, int cmd_code)
{
	int	*cmd_info;

	cmd_info = malloc(sizeof(*cmd_info));
	*cmd_info = cmd_code;
	darray_push_back(cmd, cmd_info);
}

void	optimize_cmd(t_darray **prev_cmd)
{
	t_darray	*new_cmd;

	new_cmd = new_darray_malloc((*prev_cmd)->size);
	while ((*prev_cmd)->size >= 2 && \
			optimize_2cmd(*prev_cmd, new_cmd) != (*prev_cmd)->size)
	{
		delete_darray(prev_cmd);
		*prev_cmd = new_cmd;
		new_cmd = new_darray_malloc((*prev_cmd)->size);
	}
	if (new_cmd->size != 0)
		darray_reset(new_cmd);
	while ((*prev_cmd)->size >= 3 && \
			optimize_3cmd(*prev_cmd, new_cmd) != (*prev_cmd)->size)
	{
		delete_darray(prev_cmd);
		*prev_cmd = new_cmd;
		new_cmd = new_darray_malloc((*prev_cmd)->size);
	}
	delete_darray(&new_cmd);
}
