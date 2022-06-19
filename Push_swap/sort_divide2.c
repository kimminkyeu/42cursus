/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_divide2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:29:44 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/18 23:41:57 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_triangle	*create_triangle(int _inc_or_dec, int _size, int _a_or_b)
{
	t_triangle	*tmp;

	tmp = ft_calloc(1, sizeof(*tmp));
	if (tmp != NULL)
	{
		tmp->size = _size;
		tmp->inc_or_dec = _inc_or_dec;
		tmp->a_or_b = _a_or_b;
	}
	return (tmp);
}

int	get_total_step(int total_num)
{
	int	i;

	i = 0;
	while (total_num > TRI_MAX)
	{
		total_num /= 3;
		i++;
	}
	return (i);
}

void	push_tri(int size, t_triangle *tri, t_push_swap *data)
{
	int	*p;
	int	i;

	p = ft_calloc(size, sizeof(int));
	i = -1;
	while (++i < size)
		p[i] = *stack_get_data(data->stack_a->stack, \
				data->stack_a->stack->size - i - 1);
	if (tri->inc_or_dec == INC)
		bubble_sort(p, 0, size - 1, DEC);
	else
		bubble_sort(p, 0, size - 1, INC);
	i = 0;
	while (i < size)
	{
		set_target_to_top(p[i], data->stack_a, data->cmd);
		push(data->stack_b, data->stack_a, data->cmd);
		i++;
	}
	free(p);
}

void	push_2_tri(t_triangle *tri, t_push_swap *data)
{
	int	p1;
	int	p2;

	p1 = *stack_get_data(data->stack_a->stack, data->stack_a->stack->size - 1);
	p2 = *stack_get_data(data->stack_a->stack, data->stack_a->stack->size - 2);
	if (tri->inc_or_dec == INC && p1 < p2)
		swap(data->stack_a, data->cmd);
	if (tri->inc_or_dec == DEC && p1 > p2)
		swap(data->stack_a, data->cmd);
	push(data->stack_b, data->stack_a, data->cmd);
	push(data->stack_b, data->stack_a, data->cmd);
}

void	push_as_triangle(t_triangle *tri, t_push_swap *data)
{
	if (tri->size > 2)
		push_tri(tri->size, tri, data);
	else if (tri->size == 2)
		push_2_tri(tri, data);
	else if (tri->size == 1)
		push(data->stack_b, data->stack_a, data->cmd);
}
