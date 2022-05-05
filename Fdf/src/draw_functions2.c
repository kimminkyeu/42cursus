/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:16:49 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 10:13:39 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/draw_functions.h"

t_point3d	get_point_x_y(t_mlx *fdf, size_t x, size_t y)
{
	size_t		index;
	t_point3d	result;

	index = (y * (fdf->map_info.max_x + 1)) + x;
	result = *((t_point3d *)(fdf->map->data[index]));
	return (result);
}

t_line	apply_matrix(t_mat4x4 matrix, t_line line)
{
	t_line	result;

	result.data[0] = multiply_matrix_vec4(matrix, line.data[0]);
	result.data[1] = multiply_matrix_vec4(matrix, line.data[1]);
	return (result);
}

/* NOTE : first translation (-max_x/y) is to move 
 * rotation axis to center of the map  */
void	draw_vertical(t_mlx *fdf, int x, int y, t_mat4x4 projection_matrix)
{
	t_line	line;

	if ((y < 0 || y + 1 > fdf->map_info.max_y))
		return ;
	line.data[0] = get_point_x_y(fdf, x, y);
	line.data[1] = get_point_x_y(fdf, x, y + 1);
	ft_printf("origin(x:%d y:%d z:%d)   --> ", \
			line.p1.cord.x, line.p1.cord.y, line.p1.cord.z);
	line = apply_matrix(translate_3d(-fdf->map_info.max_x / 2 \
				, -fdf->map_info.max_y / 2, 0), line);
	line = apply_matrix(camera_tranform(fdf), line);
	ft_printf("camera-transform(x:%d y:%d z:%d)   --> ", \
			line.p1.cord.x, line.p1.cord.y, line.p1.cord.z);
	line = apply_matrix(projection_matrix, line);
	ft_printf("project(x:%d y:%d z:%d)   --> ", \
			line.p1.cord.x, line.p1.cord.y, line.p1.cord.z);
	line = apply_matrix(fit_to_viewport(fdf), line);
	ft_printf("fit-view(x:%d y:%d z:%d)\n", \
			line.p1.cord.x, line.p1.cord.y, line.p1.cord.z);
	draw_line(fdf, line.data[0], line.data[1]);
}

void	draw_horizontal(t_mlx *fdf, int x, int y, t_mat4x4 projection_matrix)
{
	t_line	line;

	if ((x < 0 || x + 1 > fdf->map_info.max_x))
		return ;
	line.data[0] = get_point_x_y(fdf, x, y);
	line.data[1] = get_point_x_y(fdf, x + 1, y);
	line = apply_matrix(translate_3d(-fdf->map_info.max_x / 2, \
				-fdf->map_info.max_y / 2, 0), line);
	line = apply_matrix(camera_tranform(fdf), line);
	line = apply_matrix(projection_matrix, line);
	line = apply_matrix(fit_to_viewport(fdf), line);
	draw_line(fdf, line.data[0], line.data[1]);
}

void	draw_map_objects(t_mlx *fdf, t_mat4x4 projection_matrix)
{
	int	x;
	int	y;

	y = 0;
	while (y <= fdf->map_info.max_y)
	{
		x = 0;
		while (x <= fdf->map_info.max_x)
		{
			draw_vertical(fdf, x, y, projection_matrix);
			draw_horizontal(fdf, x, y, projection_matrix);
			++x;
		}
		++y;
	}
}
