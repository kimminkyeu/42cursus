/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:11:49 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/23 18:09:43 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_map.h"
#include "bsq.h"

void	square_info(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map -> rows)
	{
		j = 0;
		while (j < map -> cols)
		{
			if (map -> max_len < map -> data[i][j])
			{
				map -> max_len = map ->data[i][j];
				map -> square_y = i;
				map -> square_x = j;
			}
			j++;
		}
		i++;
	}
}

void	find_square(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map -> rows)
	{
		j = 1;
		while (j < map -> cols)
		{
			if (map -> data[i][j] != 0)
				map ->data[i][j] += ft_min(map ->data[i - 1][j - 1],
						map ->data[i - 1][j], map ->data[i][j - 1]);
			j++;
		}
		i++;
	}
	square_info(map);
	fill_field(map);
}
