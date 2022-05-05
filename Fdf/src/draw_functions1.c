/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:12:53 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 15:48:39 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/draw_functions.h"

void	draw_pixel(t_mlx *data, t_point3d p)
{
	char	*pixel;

	if (p.cord.x < WIN_WIDTH && p.cord.x > 0 && \
			p.cord.y < WIN_HEIGHT && p.cord.y > 0)
	{
		pixel = data->frame.addr + (p.cord.y * data->frame.line_length \
				+ p.cord.x * (data->frame.bits_per_pixel / 8));
		*(unsigned int *)pixel = p.color;
	}
}

void	draw_background(t_mlx *data, int width, int height, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			draw_pixel(data, create_point3d(x, y, 0, color));
			x += 1;
		}
		y += 1;
	}
}

void	bezier_linear(t_mlx *fdf, t_point3d p1, t_point3d p2)
{
	unsigned int	ndots;
	float			t;
	float			offset;
	t_point3d		point;
	t_vector4		vec_p1p2;

	vec_p1p2 = create_vector4(p2.cord.x - p1.cord.x, \
			p2.cord.y - p1.cord.y, p2.cord.z - p1.cord.z, 0);
	ndots = get_magnitude_vec4(vec_p1p2);
	t = 0;
	while (t < ndots)
	{
		offset = t / ndots;
		point.cord.x = ((1 - offset) * p1.cord.x) + (offset * p2.cord.x);
		point.cord.y = ((1 - offset) * p1.cord.y) + (offset * p2.cord.y);
		point.cord.z = ((1 - offset) * p1.cord.z) + (offset * p2.cord.z);
		point.color = color_shader(fdf, get_cord_color(p1, p2, offset), \
				point.cord.z);
		draw_pixel(fdf, point);
		t += 1;
	}
}

void	draw_line(t_mlx *fdf, t_point3d _p1, t_point3d _p2)
{
	bezier_linear(fdf, _p1, _p2);
}
