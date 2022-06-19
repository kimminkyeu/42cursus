/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:05:27 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/19 20:08:34 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_program(char *err_messege, int is_error, t_push_swap *data)
{
	ft_printf("%s", err_messege);
	delete_stack2(data->stack_a);
	delete_stack2(data->stack_b);
	delete_darray(&(data->cmd));
	exit(is_error);
}

int	main(int ac, char **av)
{
	t_push_swap	data;

	data.stack_a = init_stack2(A);
	data.stack_b = init_stack2(B);
	data.is_checker = false;
	data.cmd = new_darray_malloc(256);
	if (ac < 2)
		exit_program("", EXIT_FAILURE, &data);
	else if (ac == 2)
		check_single_arg_and_push(av, &data);
	else
		check_num_and_push(ac, 1, av, &data);
	sort_stack(&data);
	if (data.stack_a->stack->size > 5)
		optimize_cmd(&data.cmd);
	print_cmd(data.cmd);
	exit_program("", EXIT_SUCCESS, &data);
	return (0);
}
