/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:26:43 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/18 23:41:42 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_sorted(int *tmp, size_t nmemb, t_push_swap *data)
{
	size_t	i;
	bool	is_sorted;

	i = 0;
	is_sorted = true;
	while (i < nmemb - 1)
	{
		if (tmp[i] > tmp[i + 1])
		{
			is_sorted = false;
			break ;
		}
		i++;
	}
	if (is_sorted)
		exit_program("", EXIT_FAILURE, data);
}

void	check_if_same_number(int *tmp, size_t nmemb, t_push_swap *data)
{
	size_t	i;
	int		*tmp_sort;

	tmp_sort = ft_calloc(nmemb, sizeof(*tmp_sort));
	if (tmp_sort == NULL)
		exit_program("Error\n", EXIT_FAILURE, data);
	ft_memmove(tmp_sort, tmp, nmemb * sizeof(int));
	bubble_sort(tmp_sort, 0, nmemb - 1, INC);
	i = 0;
	while (i < nmemb - 1)
	{
		if (tmp_sort[i] == tmp_sort[i + 1])
			exit_program("Error\n", EXIT_FAILURE, data);
		i++;
	}
	data->min = tmp_sort[0];
	data->max = tmp_sort[nmemb - 1];
	free(tmp_sort);
}

void	push_argument_to_stack(int *tmp, size_t nmemb, t_stack2 *stack)
{
	while (nmemb > 0)
	{
		stack_push(stack->stack, tmp[nmemb - 1]);
		nmemb--;
	}
}

void	check_num_and_push(size_t nmemb, int start_idx, \
		char **strs, t_push_swap *data)
{
	size_t	i;
	size_t	j;
	int		*tmp;

	tmp = ft_calloc(nmemb - start_idx, sizeof(int));
	i = start_idx;
	j = 0;
	while (i < nmemb)
	{
		if (strs[i][0] == '\0' || !ft_isinteger(strs[i]))
			exit_program("Error\n", EXIT_FAILURE, data);
		tmp[j++] = ft_atoi(strs[i++]);
	}
	check_if_same_number(tmp, nmemb - start_idx, data);
	if (data->is_checker == false)
		check_if_sorted(tmp, nmemb - start_idx, data);
	push_argument_to_stack(tmp, nmemb - start_idx, data->stack_a);
	data->total_input_cnt = data->stack_a->stack->size;
	free(tmp);
}

void	check_single_arg_and_push(char **av, t_push_swap *data)
{
	size_t	i;
	size_t	w_cnt;
	char	**strs;

	i = -1;
	w_cnt = 0;
	strs = ft_split(av[1], ' ');
	if (strs == NULL)
		exit_program("ft_split error\n", EXIT_FAILURE, data);
	while (strs[++i] != NULL)
		w_cnt++;
	check_num_and_push(w_cnt, 0, strs, data);
	i = -1;
	while (strs[++i] != NULL)
		free(strs[i]);
	free(strs);
}
