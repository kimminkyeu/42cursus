/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:04:14 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/27 15:26:10 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map_parser.h"

int	mp_open_file(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_putstr_fd("Error : wrong argument input\n", STDOUT);
		exit (EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error : file open error\n", STDOUT);
		exit (EXIT_FAILURE);
	}
	else
		return (fd);
}

/* -----------------------------------------
 * * Allocate t_vector4 data and return. */
static t_vector4	*create_data_malloc(int _x, int _y, int _z, int _color)
{
	t_vector4	*pa_result;

	pa_result = malloc(sizeof(*pa_result));
	if (pa_result != NULL)
	{
		pa_result->x = _x;
		pa_result->y = _y;
		pa_result->z = _z;
		pa_result->color = _color;
	}
	return (pa_result);
}

/* -----------------------------------------
 * * Convert map data to vector4(x y z color), then push to D-array */
static void	mp_convert_and_push(char **strs, t_darray *pa_map, int x, int y)
{
	char	*str;
	int		z;

	str = strs[x];
	z = ft_atoi(str);
	if (str[0] == '-' && ft_strlen(str) > 2)
	{
		darray_push_back(pa_map, create_data_malloc(x, y, z, \
					ft_atoi_base(str + 5, "0123456789abcdef")));
	}
	else if (ft_strlen(str) > 1)
	{
		darray_push_back(pa_map, create_data_malloc(x, y, z, \
					ft_atoi_base(str + 4, "0123456789abcdef")));
	}
	else
	{
		darray_push_back(pa_map, create_data_malloc(x, y, z, \
					DEFAULT_PT_COLOR));
	}
}

static void	free_both(void	*pa1, void	*pa2)
{
	free(pa1);
	free(pa2);
}

t_darray	*mp_parse_file_malloc(int fd, size_t arr_init_size)
{
	t_darray	*pa_map;
	char		*pa_line;
	char		**pa_line_split;
	int			x;
	int			y;

	pa_map = new_darray_malloc(arr_init_size);
	pa_line = get_next_line(fd);
	y = 0;
	while (pa_map != NULL && pa_line != NULL)
	{
		*ft_strrchr(pa_line, '\n') = '\0';	// Remove '\n' in line.
		pa_line_split = ft_split(pa_line, ' ');
		x = 0;
		while (pa_line_split[x] != NULL)
		{
			mp_convert_and_push(pa_line_split, pa_map, x, y);
			free(pa_line_split[x++]);
		}
		free_both(pa_line, pa_line_split);
		y += 1;
		pa_line = get_next_line(fd);
	}
	close(fd); // if parsing is done, close fd.
	return (pa_map);
}
