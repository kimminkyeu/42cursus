/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <yonghlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:12:26 by yonghlee          #+#    #+#             */
/*   Updated: 2022/02/23 19:02:57 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "t_map.h"
#include "t_array.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->rows = 0;
	map->cols = 0;
	map->c_empty = 0;
	map->c_full = 0;
	map->c_obstacle = 0;
	map->data = 0;
	map->max_len = 0;
	map->square_x = 0;
	map->square_y = 0;
	return (map);
}

int	set_map(t_map *map)
{
	map->data = (int **)malloc(sizeof(int *) * map->rows);
	if (map->data == 0)
		return (0);
	return (1);
}

void	free_map(t_map *map)
{
	int	i;

	if (map->data)
	{
		i = 0;
		while (map->data[i] && i < map -> rows)
		{
			free(map->data[i]);
			i++;
		}
		free(map->data);
	}
}

int	append_map(t_map *map, t_array *array, int row_idx_to_append)
{
	int	i;

	i = 0;
	if (map->cols != array->len)
		return (0);
	map -> data[row_idx_to_append] = (int *)malloc(sizeof(int) * map->cols);
	if (map->data[row_idx_to_append] == 0)
		return (0);
	while (i < map->cols)
	{
		if (array->data[i] == map->c_empty)
			map->data[row_idx_to_append][i] = 1;
		else if (array->data[i] == map->c_obstacle)
			map->data[row_idx_to_append][i] = 0;
		i++;
	}
	return (1);
}
