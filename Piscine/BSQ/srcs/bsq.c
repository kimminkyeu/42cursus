/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:07:52 by yonghlee          #+#    #+#             */
/*   Updated: 2022/02/23 18:59:57 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_map.h"
#include "bsq.h"
#include <unistd.h>

int	ft_min(int num1, int num2, int num3)
{
	int	min;

	min = 0;
	if (num1 < num2)
		min = num1;
	else
		min = num2;
	if (min < num3)
		return (min);
	else
		min = num3;
	return (min);
}

void	free_field(t_map *map, char **field)
{
	int	i;

	i = -1;
	while (++i < (map -> rows))
	{
		free(field[i]);
	}
	free(field);
}

void	fill_field(t_map *map)
{
	int		i;
	int		j;
	char	**field;

	field = malloc(sizeof(char *) * (map -> rows));
	i = -1;
	while (++i < (map -> rows))
		field[i] = malloc(sizeof(char) * (map -> cols) + 1);
	i = -1;
	while (++i < (map -> rows))
	{
		j = -1;
		while (++j < (map -> cols))
		{
			if (map -> data[i][j] != 0)
				field[i][j] = map -> c_empty;
			else
				field[i][j] = map -> c_obstacle;
		}
		field[i][j] = '\0';
	}
	final_square(map, field);
}

void	final_square(t_map *map, char **field)
{
	int	i;
	int	j;

	i = map -> square_y;
	while (i != map -> square_y - map -> max_len)
	{
		j = map -> square_x;
		while (j != map -> square_x - map -> max_len)
		{
			field[i][j] = map -> c_full;
			j--;
		}
		i--;
	}
	i = -1;
	while (++i < map -> rows)
	{
		j = -1;
		while (++j < map -> cols)
		{
			write(1, &field[i][j], 1);
		}
		write(1, "\n", 1);
	}
	free_field(map, field);
}
