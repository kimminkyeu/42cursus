/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:52:19 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/18 18:15:50 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 
#include <unistd.h>
#include "push_swap.h"

void	handle_cmd(char *cmd, t_push_swap *data);
void	render_stack(t_stack2 *stack_a, t_stack2 *stack_b);

void	exit_program(char *err_messege, int is_error, t_push_swap *data)
{
	ft_printf("%s", err_messege);
	delete_stack2(data->stack_a);
	delete_stack2(data->stack_b);
	delete_darray(&(data->cmd));
	exit(is_error);
}

void	check_result(t_push_swap *data)
{
	t_list	*cur;
	t_list	*next;

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

void	handle_stdin(t_push_swap *data)
{
	char		*cmd;

	cmd = get_next_line(STDIN_FILENO);
	if (cmd == NULL)
		return ;
	while (cmd[0] != '\n')
	{
		handle_cmd(cmd, data);
		render_stack(data->stack_a, data->stack_b);
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
		if (cmd == NULL)
			return ;
	}
	free(cmd);
}

int	main(int ac, char **av)
{
	t_push_swap	data;

	data.stack_a = init_stack2(A);
	data.stack_b = init_stack2(B);
	data.is_checker = true;
	data.cmd = new_darray_malloc(256);
	if (ac < 2)
		exit_program("", EXIT_FAILURE, &data);
	else if (ac == 2)
		check_single_arg_and_push(av, &data);
	else
		check_num_and_push(ac, 1, av, &data);
	render_stack(data.stack_a, data.stack_b);
	handle_stdin(&data);
	check_result(&data);
	exit_program("OK\n", EXIT_SUCCESS, &data);
	return (0);
}
