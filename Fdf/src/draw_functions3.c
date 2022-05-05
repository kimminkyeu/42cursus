/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:19:21 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 15:49:05 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/draw_functions.h"

float	get_radian(float degree)
{
	return (degree / 180.0f * 3.141592f);
}

t_point3d	get_point_idx(t_darray *map, int index)
{
	return (*(t_point3d *)(map->data[index]));
}

t_point3d	create_point3d(int _x, int _y, int _z, int _color)
{
	t_point3d	p;

	p.cord.x = _x;
	p.cord.y = _y;
	p.cord.z = _z;
	p.cord.w = 1;
	p.color = _color;
	return (p);
}

int	get_cord_color(t_point3d p1, t_point3d p2, float offset)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = get_red_color(p2.color) - get_red_color(p1.color);
	g = get_green_color(p2.color) - get_green_color(p1.color);
	b = get_blue_color(p2.color) - get_blue_color(p1.color);
	a = get_alpha_color(p2.color) - get_alpha_color(p1.color);
	r = get_red_color(p1.color) + r * offset;
	g = get_green_color(p1.color) + g * offset;
	b = get_blue_color(p1.color) + b * offset;
	a = get_alpha_color(p1.color) + a * offset;
	return (create_trgb_color(a, r, g, b));
}

/* Use get_shaded_color()  --> gets darker if shade_factor increases */
int	color_shader(t_mlx *fdf, int color, int z)
{
	double	shade_factor;
	double	z_max;
	double	zoom_rate;

	if (fdf->map_info.max_x > fdf->map_info.max_y)
		z_max = 1.0f * fdf->map_info.max_x;
	else
		z_max = 1.0f * fdf->map_info.max_y;
	zoom_rate = fdf->camera->zoom_rate;
	z /= zoom_rate;
	if (z_max > z)
		shade_factor = ((z_max - z) / z_max) - 1.0f \
			* fdf->camera->z_shade_factor;
	else
		shade_factor = ((z - z_max) / z_max) - 1.0f \
			* fdf->camera->z_shade_factor;
	return (get_shaded_color(shade_factor, color));
}
