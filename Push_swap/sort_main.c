/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:19:21 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/19 15:53:23 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack2 *stack, t_darray *cmd)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)stack->stack->top->content;
	b = *stack_get_data(stack->stack, stack->stack->size - 2);
	c = *stack_get_data(stack->stack, stack->stack->size - 3);
	if (a < b && b > c && a > c)
		shift_down(stack, cmd);
	if (a < b && b > c && a < c)
	{
		shift_down(stack, cmd);
		swap(stack, cmd);
	}
	if (a > b && b < c && a < c)
		swap(stack, cmd);
	if (a > b && b < c && a > c)
		shift_up(stack, cmd);
	if (a > b && b > c && a > c)
	{
		swap(stack, cmd);
		shift_down(stack, cmd);
	}
}

void	sort_five(t_push_swap *data)
{
	push(data->stack_b, data->stack_a, data->cmd);
	push(data->stack_b, data->stack_a, data->cmd);
	sort_three(data->stack_a, data->cmd);
	insert_to_fit(data->stack_a, data->stack_b, data->cmd);
	insert_to_fit(data->stack_a, data->stack_b, data->cmd);
	set_target_to_top(data->min, data->stack_a, data->cmd);
}

void	sort_under_three(t_push_swap *data)
{
	if (data->stack_a->stack->size == 2)
		if (*stack_get_data(data->stack_a->stack, 0) \
				< *stack_get_data(data->stack_a->stack, 1))
			swap(data->stack_a, data->cmd);
	if (data->stack_a->stack->size == 3)
		sort_three(data->stack_a, data->cmd);
}

void	sort_stack(t_push_swap *data)
{
	if (data->stack_a->stack->size <= 3)
		sort_under_three(data);
	else if (data->stack_a->stack->size == 5)
		sort_five(data);
	else
	{
		data->tri_map = make_tri_map(data->stack_a->stack->size);
		tringify(data);
		while (((t_triangle *)data->tri_map->data[0])->size \
				< data->total_input_cnt)
			merge(data);
		if (data->stack_a->stack->size == 0)
		{
			while (data->stack_a->stack->size < (size_t)data->total_input_cnt)
				push(data->stack_a, data->stack_b, data->cmd);
		}
		delete_darray(&data->tri_map);
	}
}
