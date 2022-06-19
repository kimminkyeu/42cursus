/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:47:47 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/16 21:06:17 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge(t_push_swap *data)
{
	size_t		i;
	t_triangle	*t[3];
	size_t		map_size_prev;

	i = -1;
	while (++i < (data->tri_map->size / 3))
	{
		t[2] = data->tri_map->data[data->tri_map->size - 1 - i];
		push_top_tri_to_opposite(t[2], data);
	}
	i = -1;
	while (++i < (data->tri_map->size / 3))
	{
		t[0] = data->tri_map->data[i];
		t[1] = data->tri_map->data[((data->tri_map->size / 3) * 2) - 1 - i];
		t[2] = data->tri_map->data[data->tri_map->size - 1 - i];
		merge_3tri_each(t[0], t[1], t[2], data);
		t[0]->a_or_b *= -1;
		t[0]->size = t[0]->size + t[1]->size + t[2]->size;
	}
	i = -1;
	map_size_prev = data->tri_map->size;
	while (++i < (map_size_prev / 3) * 2)
		darray_pop_back(data->tri_map);
}

void	push_top_tri_to_opposite(t_triangle *t3, t_push_swap *data)
{
	int	i;

	i = 0;
	while (i < t3->size)
	{
		if (t3->a_or_b == B)
			push(data->stack_a, data->stack_b, data->cmd);
		else
			push(data->stack_b, data->stack_a, data->cmd);
		i++;
	}
	t3->inc_or_dec *= -1;
	t3->a_or_b *= -1;
}

int	find_max_or_min(int *arr, int size, int max_or_min)
{
	int	i;
	int	target;

	i = -1;
	target = arr[0];
	if (max_or_min == MAX)
	{
		while (++i < size - 1)
		{
			if (arr[i + 1] > target)
				target = arr[i + 1];
		}
	}
	else
	{
		while (++i < size - 1)
		{
			if (arr[i + 1] < target)
				target = arr[i + 1];
		}
	}
	return (target);
}

int	find_max_or_min_2(int a, int b, int max_or_min)
{
	int	target;

	target = a;
	if ((max_or_min == MAX && a < b) || (max_or_min == MIN && a > b))
		target = b;
	return (target);
}
