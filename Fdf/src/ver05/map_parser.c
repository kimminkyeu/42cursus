/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:04:14 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/03 16:27:36 by minkyeki         ###   ########.fr       */
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
static t_point3d	*create_point_malloc(int _x, int _y, int _z, int _color)
{
	t_point3d	*pa_result;

	pa_result = malloc(sizeof(*pa_result));
	if (pa_result != NULL)
	{
		pa_result->cord.x = _x;
		pa_result->cord.y = _y;
		pa_result->cord.z = _z;
		pa_result->cord.w = 1;
		pa_result->color = _color;
	}
	return (pa_result);
}

/* -----------------------------------------
 * * Convert map data to vector4(x y z color), then push to D-array 
 * 10,0x00ff.. --> num_len(2), strlen(9)
 * */
static void	mp_convert_and_push(char **strs, t_darray *pa_map, int x, int y)
{
	char		*str;
	int			z;
	size_t		num_len;
	t_point3d	*data;

	str = strs[x];
	z = ft_atoi(str);
	num_len = ft_nbrlen(z);
	if (ft_strlen(str) > num_len)
		data = create_point_malloc(x, y, z, \
				ft_atoi_base(str + num_len + 3, "0123456789abcdef"));
	else
		data = create_point_malloc(x, y, z, DEFAULT_PT_COLOR);
	darray_push_back(pa_map, data);
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
		if (ft_strrchr(pa_line, '\n') != NULL)
			*ft_strrchr(pa_line, '\n') = '\0';
		pa_line_split = ft_split(pa_line, ' ');
		x = -1;
		while (pa_line_split[++x] != NULL)
		{
			mp_convert_and_push(pa_line_split, pa_map, x, y);
			free(pa_line_split[x]);
		}
		free_both(pa_line, pa_line_split);
		pa_line = get_next_line(fd);
		y++;
	}
	return (pa_map);
}
