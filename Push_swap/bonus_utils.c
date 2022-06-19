/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:07:07 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/19 16:08:55 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_s(char *cmd, t_push_swap *data)
{
	if (cmd[1] == 'a')
		swap(data->stack_a, data->cmd);
	else if (cmd[1] == 'b')
		swap(data->stack_b, data->cmd);
	else if (cmd[1] == 's')
		swap_both(data->stack_a, data->stack_b, data->cmd);
	else
		exit_program("Error\n", EXIT_FAILURE, data);
}

void	handle_p(char *cmd, t_push_swap *data)
{
	if (cmd[1] == 'a')
		push(data->stack_a, data->stack_b, data->cmd);
	else if (cmd[1] == 'b')
		push(data->stack_b, data->stack_a, data->cmd);
	else
		exit_program("Error\n", EXIT_FAILURE, data);
}

void	handle_r(char *cmd, t_push_swap *data)
{
	if (cmd[1] == 'a')
		shift_up(data->stack_a, data->cmd);
	else if (cmd[1] == 'b')
		shift_up(data->stack_b, data->cmd);
	else if (cmd[1] == 'r')
		shift_up_both(data->stack_a, data->stack_b, data->cmd);
	else
		exit_program("Error\n", EXIT_FAILURE, data);
}

void	handle_rr(char *cmd, t_push_swap *data)
{
	if (cmd[2] == 'a')
		shift_down(data->stack_a, data->cmd);
	else if (cmd[2] == 'b')
		shift_down(data->stack_b, data->cmd);
	else if (cmd[2] == 'r')
		shift_down_both(data->stack_a, data->stack_b, data->cmd);
	else
		exit_program("Error\n", EXIT_FAILURE, data);
}

void	handle_cmd(char *cmd, t_push_swap *data)
{
	if (cmd[0] == 's' && ft_strlen(cmd) == 3)
		handle_s(cmd, data);
	else if (cmd[0] == 'p' && ft_strlen(cmd) == 3)
		handle_p(cmd, data);
	else if (cmd[0] == 'r' && ft_strlen(cmd) == 3)
		handle_r(cmd, data);
	else if (cmd[0] == 'r' && ft_strlen(cmd) == 4 && cmd[1] == 'r')
		handle_rr(cmd, data);
	else
		exit_program("Error\n", EXIT_FAILURE, data);
}
