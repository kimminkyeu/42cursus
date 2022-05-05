/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <yonghlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:11:52 by yonghlee          #+#    #+#             */
/*   Updated: 2022/02/23 19:07:46 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "t_map.h"
#include "t_array.h"
#include "bsq.h"

int	is_number(char *str, int len)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (i < len)
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num);
}

int	parse_initial_line(int fd, t_map *map)
{
	char	cache[100];
	int		len;

	len = 0;
	while (read(fd, cache + 99, 1) == 1)
	{
		if (cache[99] == '\n')
			break ;
		cache[len++] = cache[99];
		if (len >= 99)
			return (0);
	}
	if (len < 4)
		return (0);
	if (is_number(cache, len - 3) < 1)
		return (0);
	if (cache[len - 1] == cache[len - 2] || cache[len - 1] == cache[len - 3]
		|| cache[len - 2] == cache[len - 3])
		return (0);
	map->rows = is_number(cache, len - 3);
	map->c_empty = cache[len - 3];
	map->c_obstacle = cache[len - 2];
	map->c_full = cache[len - 1];
	return (1);
}

int	parse(int fd, t_map *map, t_array *array)
{
	char	c;
	int		row_idx;

	row_idx = 0;
	while (read(fd, &c, 1) == 1)
	{
		if (row_idx > map->rows)
			return (0);
		if (c == '\n')
		{
			if ((array->len != map->cols && map->cols != 0) || array->len == 0)
				return (0);
			map->cols = array->len;
			append_map(map, array, row_idx++);
			clear_arrary(array);
			continue ;
		}
		if (c != map->c_empty && c != map->c_obstacle)
			return (0);
		append_array(array, c);
	}
	if (row_idx != map->rows)
		return (0);
	return (1);
}

int	parse_n_solve(int fd)
{
	t_map	*map;
	t_array	*array;

	map = init_map();
	array = init_array();
	if (!parse_initial_line(fd, map))
		return (0);
	set_map(map);
	if (!parse(fd, map, array))
		return (0);
	find_square(map);
	free_array(array);
	free_map(map);
	free(map);
	free(array);
	return (1);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	if (argc == 1)
	{
		if (parse_n_solve(0) == 0)
			write(2, "map error\n", 10);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i++], O_RDONLY);
			if (fd == -1 || parse_n_solve(fd) == 0)
				write(2, "map error\n", 10);
			if (i < argc)
				write(1, "\n", 1);
		}
	}
	return (0);
}
