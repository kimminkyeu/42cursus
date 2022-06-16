/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:26:43 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/16 15:34:20 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_program(char *err_messege, int is_error, t_push_swap *data)
{
	ft_printf("%s", err_messege);
	delete_stack2(data->stack_a);
	delete_stack2(data->stack_b);
	delete_darray(&(data->cmd));
	system("leaks push_swap > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	exit(is_error);
}

/* helper : check if data is sorted in tmp  */
void	check_if_sorted(int *tmp, size_t nmemb, t_push_swap *data)
{
	size_t	i;
	bool	is_sorted;

	i = 0;
	is_sorted = true;
	while(i < nmemb - 1)
	{
		/* check if data increments. if already sorted, then no print */
		/** ft_printf("nmemb:%d, i:%d (%d,%d)\n", nmemb, i, tmp[i], tmp[i + 1]); */
		if (tmp[i] > tmp[i + 1])
		{
			is_sorted = false;
			break;
		}
		i++;
	}
	if (is_sorted)
		exit_program("", EXIT_FAILURE, data);
}

/* helper : sort tmp, and check if number has same values  */
void	check_if_same_number(int *tmp, size_t nmemb, t_push_swap *data)
{
	size_t	i;
	int		tmp_sort[nmemb];

	ft_memmove(tmp_sort, tmp, nmemb * sizeof(int));
	quick_sort(tmp_sort, 0, nmemb - 1, INC);
	i = 0;
	while(i < nmemb)
	{
		if (tmp_sort[i] == tmp_sort[i + 1])
			exit_program("Error\n", EXIT_FAILURE, data);
		i++;
	}
	data->min = tmp_sort[0];
	data->max = tmp_sort[nmemb - 1];
}

void	push_argument_to_stack(int *tmp, size_t nmemb, t_stack2 *stack)
{
	while (nmemb > 0)
	{
		stack_push(stack->stack, tmp[nmemb - 1]);
		nmemb--;
	}
}

void	check_num_and_push(size_t nmemb, int start_idx, char **strs, t_push_swap *data)
{
	size_t	i;
	size_t	j;
	int		tmp[nmemb];

	i = start_idx; // if multi_arg, then i = 1, nmemb is ac
	j = 0;
	while (i < nmemb)
	{
		// check if arguments are integers.
		if (strs[i][0] == '\0' || !ft_isinteger(strs[i]))
			exit_program("Error\n", EXIT_FAILURE, data);
		// store to temp arr (for sorting to check duplicates)
		tmp[j++] = ft_atoi(strs[i++]);
	}
	check_if_sorted(tmp, nmemb - start_idx, data);
	check_if_same_number(tmp, nmemb - start_idx, data);

	push_argument_to_stack(tmp, nmemb - start_idx, data->stack_a);
	data->total_input_cnt = data->stack_a->stack->size;
}

void	check_single_arg_and_push(char **av, t_push_swap *data)
{
	// a ^ b\n  : number of space = 1
	size_t	i;
	size_t	cnt;
	char	**strs;

	i = 0;
	cnt = 0;
	while (av[1][i] != '\0')
	{
		// check number of space
		if (av[1][i] == ' ')
			cnt++;
		++i;
	}
	if (cnt + 1 >= 2) // if at least two number
	{
		strs = ft_split(av[1], ' ');
		if (strs == NULL)
			exit_program("ft_split error\n", EXIT_FAILURE, data);
		check_num_and_push(cnt + 1, 0, strs, data);

		i = -1;
		while (strs[++i] != NULL)
			free(strs[i]);
		free(strs);
	}
	else
		exit_program("Error\n", EXIT_FAILURE, data);
}

