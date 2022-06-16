/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:52:19 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/16 14:33:02 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // for exit
#include <unistd.h> // for read, write

#include "push_swap.h"

#define SAME (0);

void handle_cmd(char *cmd, t_push_swap *data)
{
	if (cmd[0] == 's')
	{
		if (cmd[1] == 'a')
			swap(data->stack_a, data->cmd);
		else if (cmd[1] == 'b')
			swap(data->stack_b, data->cmd);
		else if (cmd[1] == 's')
			swap_both(data->stack_a, data->stack_b, data->cmd);
		else
			ft_printf("Error\n");
	}
	else if (cmd[0] == 'p')
	{
		if (cmd[1] == 'a')
			push(data->stack_a, data->stack_b, data->cmd);
		else if (cmd[1] == 'b')
			push(data->stack_b, data->stack_a, data->cmd);
		else
			ft_printf("Error\n");
	}
	else if (ft_strlen(cmd) == 3 && cmd[0] == 'r')
	{
		if (cmd[1] == 'a')
			shift_up(data->stack_a, data->cmd);
		else if (cmd[1] == 'b')
			shift_up(data->stack_b, data->cmd);
		else if (cmd[1] == 'r')
			shift_up_both(data->stack_a, data->stack_b, data->cmd);
		else
			ft_printf("Error\n");
	}
	else if (ft_strlen(cmd) == 4 && cmd[0] == 'r' && cmd[1] == 'r')
	{
		if (cmd[2] == 'a')
			shift_down(data->stack_a, data->cmd);
		else if (cmd[2] == 'b')
			shift_down(data->stack_b, data->cmd);
		else if (cmd[2] == 'r')
			shift_down_both(data->stack_a, data->stack_b, data->cmd);
	}
	else
		exit_program("Error\n", EXIT_FAILURE, data);
}

void	check_result(t_push_swap *data)
{
	t_list	*cur;
	t_list	*next;

	// if everything is done, check b is emty and a is full, and a is sorted
	if (data->stack_a->stack->size != (size_t)data->total_input_cnt)
		exit_program("KO\n", EXIT_SUCCESS, data);
	cur = data->stack_a->stack->bottom;
	next = cur->next;
	while (next != NULL)
	{
		if (*(int *)cur->content < *(int *)next->content)
			exit_program("KO\n", EXIT_SUCCESS, data);
		cur = cur->next;
		next = cur->next;
	}
}

int main(int ac, char **av)
{
	/** " " and each + from stdin */
	t_push_swap	data;
	char		*cmd;

	/* init stack a and b */
	data.stack_a = init_stack2(A);
	data.stack_b = init_stack2(B);
	data.cmd = new_darray_malloc(256);

	/* NOTE : for visualizer, copy stack  */
	data.stack_a_copy = init_stack2(A);
	data.stack_b_copy = init_stack2(B);

	/* if argument is in single line  */
	if (ac < 2)
		exit_program("Error\n", EXIT_FAILURE, &data);
	else if (ac == 2)
		check_single_arg_and_push(av, &data);
	else
		check_num_and_push(ac, 1, av, &data);
	render_stack(data.stack_a, data.stack_b);
	cmd = get_next_line(STDIN_FILENO);
	while (cmd[0] != '\n') // while nothing input (\n)
	{
		handle_cmd(cmd, &data);
		render_stack(data.stack_a, data.stack_b);
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
	free(cmd);
	check_result(&data);
	exit_program("OK\n", EXIT_SUCCESS, &data);
	return (0);
}
