/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_divide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:25:32 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/16 21:03:16 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mirror_tri_part1(t_darray *tri_map, int map_size_prev)
{
	int			i;
	t_triangle	*tmp;

	i = -1;
	while (++i < map_size_prev)
	{
		tmp = ((t_triangle *)(tri_map->data[map_size_prev - 1 - i]));
		darray_push_back(tri_map, \
				create_triangle(tmp->inc_or_dec * -1, \
					tmp->size / 3 + tmp->size % 3, tmp->a_or_b * -1));
		tmp->size /= 3;
		tmp->a_or_b *= -1;
	}
}

void	mirror_tri_part2(t_darray *tri_map, int map_size_prev)
{
	int			i;
	t_triangle	*tmp;

	i = -1;
	while (++i < map_size_prev)
	{
		tmp = ((t_triangle *)(tri_map->data[map_size_prev - 1 - i]));
		darray_push_back(tri_map, \
				create_triangle(tmp->inc_or_dec * -1, tmp->size, tmp->a_or_b));
	}
}

t_darray	*make_tri_map(int total_num)
{
	t_darray	*tri_map;
	int			map_size_prev;

	tri_map = new_darray_malloc(30);
	if (get_total_step(total_num) % 2 == 1)
		darray_push_back(tri_map, create_triangle(INC, total_num, A));
	else
		darray_push_back(tri_map, create_triangle(DEC, total_num, B));
	while (((t_triangle *)(tri_map->data[0]))->size > TRI_MAX)
	{
		map_size_prev = tri_map->size;
		mirror_tri_part1(tri_map, map_size_prev);
		mirror_tri_part2(tri_map, map_size_prev);
	}
	return (tri_map);
}

void	tringify(t_push_swap *data)
{
	size_t		i;
	t_triangle	*tmp;

	i = 0;
	while (i < data->tri_map->size)
	{
		tmp = data->tri_map->data[i];
		push_as_triangle(tmp, data);
		i++;
	}
}
