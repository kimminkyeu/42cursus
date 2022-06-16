/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:05:27 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/16 14:26:23 by minkyeki         ###   ########.fr       */
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
	sort_stack(&data);

	/* (2) render stack result */
	ft_printf("------------------------------\n");
	ft_printf("|   (1) Merge Sort Result    |\n");
	ft_printf("------------------------------\n");
	render_stack(data.stack_a, data.stack_b);

	/* Final Result of Push Swap commands 
	 * TODO : 명령어가 줄바꿈과 함께 출력되게 수정 */

	ft_printf("------------------------------\n");
	ft_printf("|   (2) Before Optimization  |\n");
	ft_printf("------------------------------\n");
	print_cmd(data.cmd);

	ft_printf("------------------------------\n");
	ft_printf("|   (3) After Optimization   |\n");
	ft_printf("------------------------------\n");
	optimize_cmd(&data.cmd);
	print_cmd(data.cmd);



	/* -------------------------------------------------------  */
	/** TODO : 명령어 최적화는 최소 3번이상 진행할 것. until 최적화 전과 후가 차이가 없을 때 까지. */
	/* -------------------------------------------------------  */

	/* TODO : delete here after everything has been checked  */
	/* -------------------------------------------------------  */
	/* NOTE : role of cmd_copy is for optimization  */
	/** data.cmd_copy = new_darray_malloc(256); */
	/** visualize_push_swap(&data); */
	/** print_cmd(data.cmd_copy); // optimized cmd */
    /**  */
	/** delete_darray(&data.cmd_copy); */
	/** delete_stack2(data.stack_a_copy); */
	/** delete_stack2(data.stack_b_copy); */
	/* -------------------------------------------------------  */

	exit_program("", EXIT_SUCCESS, &data);

	return (0);
}
