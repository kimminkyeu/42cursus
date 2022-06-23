/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:30:26 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/23 12:37:13 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_cmd_optimizable(int cmd_code1, int cmd_code2)
{
	if ((cmd_code1 == SA && cmd_code2 == SB) \
			|| (cmd_code1 == SB && cmd_code2 == SA))
		return (1);
	else if ((cmd_code1 == RA && cmd_code2 == RB) \
			|| (cmd_code1 == RB && cmd_code2 == RA))
		return (2);
	else if ((cmd_code1 == RRA && cmd_code2 == RRB) \
			|| (cmd_code1 == RRB && cmd_code2 == RRA))
		return (3);
	else if ((cmd_code1 == RRA && cmd_code2 == RA) \
			|| (cmd_code1 == RRB && cmd_code2 == RB) \
			|| (cmd_code1 == RA && cmd_code2 == RRA) \
			|| (cmd_code1 == RB && cmd_code2 == RRB) \
			|| (cmd_code1 == PA && cmd_code2 == PB) \
			|| (cmd_code1 == PB && cmd_code2 == PA))
		return (4);
	else
		return (0);
}

void	check_2cmd(int cmd_code1, int cmd_code2, t_darray *new_cmd, size_t *i)
{
	if (is_cmd_optimizable(cmd_code1, cmd_code2) == 1)
	{
		push_cmd(new_cmd, SS);
		*i += 1;
	}
	else if (is_cmd_optimizable(cmd_code1, cmd_code2) == 2)
	{
		push_cmd(new_cmd, RR);
		*i += 1;
	}
	else if (is_cmd_optimizable(cmd_code1, cmd_code2) == 3)
	{
		push_cmd(new_cmd, RRR);
		*i += 1;
	}
	else if (is_cmd_optimizable(cmd_code1, cmd_code2) == 4)
		*i += 1;
	else
		push_cmd(new_cmd, cmd_code1);
	*i += 1;
}

size_t	optimize_2cmd(t_darray *prev_cmd, t_darray *new_cmd)
{
	size_t	i;
	int		cmd_code1;
	int		cmd_code2;

	i = 0;
	while (i < prev_cmd->size - 1)
	{
		cmd_code1 = *(int *)(prev_cmd->data)[i];
		cmd_code2 = *(int *)(prev_cmd->data)[i + 1];
		check_2cmd(cmd_code1, cmd_code2, new_cmd, &i);
	}
	if (i == prev_cmd->size - 1)
		push_cmd(new_cmd, cmd_code2);
	return (new_cmd->size);
}

void	check_3cmd(int *cmd_code, t_darray *new_cmd, size_t *i)
{
	if (cmd_code[0] == RA && cmd_code[1] == PB && cmd_code[2] == RRA)
	{
		push_cmd(new_cmd, SA);
		push_cmd(new_cmd, PB);
		*i += 3;
	}
	else if (cmd_code[0] == RB && cmd_code[1] == PA && cmd_code[2] == RRB)
	{
		push_cmd(new_cmd, SB);
		push_cmd(new_cmd, PA);
		*i += 3;
	}
	else
	{
		push_cmd(new_cmd, cmd_code[0]);
		*i += 1;
	}
}

size_t	optimize_3cmd(t_darray *prev_cmd, t_darray *new_cmd)
{
	size_t	i;
	int		cmd_code[3];

	i = 0;
	while (i < prev_cmd->size - 2)
	{
		cmd_code[0] = *(int *)(prev_cmd->data)[i];
		cmd_code[1] = *(int *)(prev_cmd->data)[i + 1];
		cmd_code[2] = *(int *)(prev_cmd->data)[i + 2];
		check_3cmd(cmd_code, new_cmd, &i);
	}
	if (i == prev_cmd->size - 2)
	{
		push_cmd(new_cmd, cmd_code[1]);
		push_cmd(new_cmd, cmd_code[2]);
	}
	return (new_cmd->size);
}
