/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:05:27 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/16 15:31:17 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_push_swap	data;

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

	/* (1) Main algorithm of stack sort */
	ft_printf("------------------------------\n");
	ft_printf("|   (0) Triangle Map         |\n");
	ft_printf("------------------------------\n");
	sort_stack(&data);

	/* (2) render stack result */
	ft_printf("------------------------------\n");
	ft_printf("|   (1) Merge Sort Result    |\n");
	ft_printf("------------------------------\n");
	render_stack(data.stack_a, data.stack_b);

	ft_printf("------------------------------\n");
	ft_printf("|   (2) Before Optimization  |\n");
	ft_printf("------------------------------\n");
	print_cmd(data.cmd);

	ft_printf("------------------------------\n");
	ft_printf("|   (3) After Optimization   |\n");
	ft_printf("------------------------------\n");
	optimize_cmd(&data.cmd);
	print_cmd(data.cmd);
	exit_program("", EXIT_SUCCESS, &data);
	return (0);
}
