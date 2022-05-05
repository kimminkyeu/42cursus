/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:12:53 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/03 20:22:15 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/draw_functions.h"
#include "../include/color.h"


extern t_mat4x4	fit_to_viewport(t_mlx *fdf);
extern t_mat4x4	camera_tranform(t_mlx *fdf);
extern t_mat4x4	translate_3d(float _x, float _y, float _z);
extern t_mat4x4 rotate_z_3d(float _degree);
extern t_mat4x4 rotate_x_3d(float _degree);
extern t_mat4x4 rotate_y_3d(float _degree);

float get_radian(float degree)
{
	return (degree / 180.0f * 3.141592f);
}

t_point3d create_point3d(int _x, int _y, int _z, int _color) {
	t_point3d   p;

	p.cord.x = _x;
	p.cord.y = _y;
	p.cord.z = _z;
	p.cord.w = 1;
	p.color = _color;
	return (p);
}

/* ----------------------------------------------
 * * TODO : 반드시 엔디안과 비트 쉬프트 부분을 이해할 것!  */
void draw_pixel(t_mlx *data, t_point3d p)
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

void draw_background(t_mlx *data, int width, int height, int color)
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

/* TODO: libft에 추가.. 언더플로우나 오버플로우 우째? */
unsigned int    ft_abs(int n)
{
	unsigned int	result;
	if (n < 0)
		result = -n;
	else
		result = n;
	return (result);
}

/* =============================
 * |   Line Drawing Equations   |
 * =============================*/
/* TODO : 원리 공부 --> 이해하지 못했다면 내꺼 쓰자. bezier linear! */
void	bresenham_line(t_mlx *fdf, t_point3d _s, t_point3d _f)
{
	t_point3d delta;
	t_point3d sign;
	t_point3d cur;
	int error[2];

	delta.cord.x = ft_abs(_s.cord.x - _f.cord.x);
	delta.cord.y = ft_abs(_s.cord.y - _f.cord.y);
	if (_f.cord.x < _s.cord.x)
		sign.cord.x = 1;
	else
		sign.cord.x = -1;
	if (_f.cord.y < _s.cord.y)
		sign.cord.y = 1;
	else
		sign.cord.y = -1;
	error[0] = delta.cord.x - delta.cord.y;
	cur = _f;
	while (cur.cord.x != _s.cord.x || cur.cord.y != _s.cord.y)
	{
		draw_pixel(fdf, cur);
		error[1] = error[0] * 2;
		if (error[1] > -delta.cord.y)
		{
			error[0] -= delta.cord.y;
			cur.cord.x += sign.cord.x;
		}
		if (error[1] < delta.cord.x)
		{
			error[0] += delta.cord.x;
			cur.cord.y += sign.cord.y;
		}
	}
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

/* NOTE : Linear Bezier Curve 응용 [ (1-t)P1 + tP2 (0<=t<=1) ] */
void	bezier_linear(t_mlx *data, t_point3d p1, t_point3d p2)
{
	unsigned int	ndots;
	float			t;
	float			offset;
	t_point3d		point;
	t_vector4		vec_p1p2;

	vec_p1p2 = create_vector4(p2.cord.x - p1.cord.x, p2.cord.y - p1.cord.y, 0, 0);
	ndots = get_magnitude_vec4(vec_p1p2);
	t = 0;
	while (t < ndots)
	{
		offset = t / ndots;
		point.cord.x = ((1 - offset) * p1.cord.x) + (offset * p2.cord.x);
		point.cord.y = ((1 - offset) * p1.cord.y) + (offset * p2.cord.y);
		point.color = get_cord_color(p1, p2, offset);
		draw_pixel(data, point);
		t += 1;
	}
}

void	draw_line(t_mlx *fdf, t_point3d _p1, t_point3d _p2)
{
	/** bresenham_line(fdf, _p1, _p2); */
	bezier_linear(fdf, _p1, _p2);
}

t_point3d 	get_point_x_y(t_mlx *fdf, size_t x, size_t y)
{
	size_t		index;
	t_point3d	result;

	index = (y * (fdf->map_info.max_x + 1)) + x;
	result = *((t_point3d *)(fdf->map->data[index]));
	return (result);
}

t_point3d 	get_point_idx(t_darray *map, int index)
{
	return (*(t_point3d *)(map->data[index]));
}

t_line	apply_matrix(t_mat4x4 matrix, t_line line)
{
	t_line	result;

	result.data[0] = multiply_matrix_vec4(matrix, line.data[0]);
	result.data[1] = multiply_matrix_vec4(matrix, line.data[1]);
	return (result);
}

/* NOTE : first translation (-max_x/y) is to move rotation axis to center of the map  */
void	draw_vertical(t_mlx *fdf, int x, int y, t_mat4x4 projection_matrix)
{
	t_line	line;

	if ((y < 0 || y + 1 > fdf->map_info.max_y))
		return ;
	line.data[0] = get_point_x_y(fdf, x, y);
	line.data[1] = get_point_x_y(fdf, x, y + 1);
	line = apply_matrix(translate_3d(-fdf->map_info.max_x / 2, -fdf->map_info.max_y / 2, 0), line);
	line = apply_matrix(camera_tranform(fdf), line);
	line = apply_matrix(projection_matrix, line);
	line = apply_matrix(fit_to_viewport(fdf), line);
	draw_line(fdf, line.data[0], line.data[1]);
}

void	draw_horizontal(t_mlx *fdf, int x, int y, t_mat4x4 projection_matrix)
{
	t_line	line;

	if ((x < 0 || x + 1 > fdf->map_info.max_x))
		return ;
	line.data[0] = get_point_x_y(fdf, x, y);
	line.data[1] = get_point_x_y(fdf, x + 1, y);
	line = apply_matrix(translate_3d(-fdf->map_info.max_x / 2, -fdf->map_info.max_y / 2, 0), line);
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
