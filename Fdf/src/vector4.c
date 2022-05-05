/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:07:11 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/03 22:29:52 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector4.h"
#include "../include/defines.h"

extern t_point3d	create_point3d(int _x, int _y, int _z, int _color);

t_vector4	create_vector4(int _x, int _y, int _z, int _w)
{
	t_vector4	pos4;

	pos4.x = _x;
	pos4.y = _y;
	pos4.z = _z;
	pos4.w = _w;
	return (pos4);
}

float	get_dot_product_vec4(t_vector4 dst, t_vector4 src)
{
	return (dst.x * src.x + dst.y * src.y + dst.z * src.z + dst.w * src.w);
}

float	get_magnitude_vec4(t_vector4 v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w)));
}

/** NOTE : float 0.0f is not exactly 0. that's why i used epsilon */
t_point3d	multiply_matrix_vec4(t_mat4x4 m, t_point3d v)
{
	t_vector4	o;
	float		epsilon;

	epsilon = 0.00001f;
	o.x = v.cord.x * m.m[0][0] + v.cord.y * m.m[0][1] + v.cord.z * \
		m.m[0][2] + v.cord.w * m.m[0][3];
	o.y = v.cord.x * m.m[1][0] + v.cord.y * m.m[1][1] + v.cord.z * \
		m.m[1][2] + v.cord.w * m.m[1][3];
	o.z = v.cord.x * m.m[2][0] + v.cord.y * m.m[2][1] + v.cord.z * \
		m.m[2][2] + v.cord.w * m.m[2][3];
	o.w = v.cord.x * m.m[3][0] + v.cord.y * m.m[3][1] + v.cord.z * \
		m.m[3][2] + v.cord.w * m.m[3][3];
	if (!(o.w < epsilon && o.w > -epsilon) \
			&& !(o.w < 1.0f + epsilon && o.w > 1.0f - epsilon))
	{
		o.x /= o.w;
		o.y /= o.w;
		o.z /= o.w;
	}
	return (create_point3d(o.x, o.y, o.z, v.color));
}
