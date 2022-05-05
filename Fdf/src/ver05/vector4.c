/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:07:11 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/03 16:15:07 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector4.h"
#include "../include/defines.h"

extern t_point3d create_point3d(int _x, int _y, int _z, int _color);

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

/** NOTE : float은 0이 실제 0이 아니기 때문에 epsilon을 이용해야 안전. */
t_point3d 	multiply_matrix_vec4(t_mat4x4 m, t_point3d v)
{
	float		epsilon = 0.00001f;
	t_vector4	o;
	/*
	 *  |  10  11  12  13  | | y | = | x10 + y11 + z12 + 13 | == > 마지막 w로 나눠줌
	 *  |  20  21  22  23  | | z |   | x20 + y21 + z22 + 23 |
	 *  |  30  31  32  33  | | 1 |   | x30 + y31 + z32 + 33 |
	 *  --               --  -   -   --                    --
	 *
	 * */
	o.x = v.cord.x * m.m[0][0] + v.cord.y * m.m[0][1] + v.cord.z * m.m[0][2] + v.cord.w * m.m[0][3];
	o.y = v.cord.x * m.m[1][0] + v.cord.y * m.m[1][1] + v.cord.z * m.m[1][2] + v.cord.w * m.m[1][3];
	o.z = v.cord.x * m.m[2][0] + v.cord.y * m.m[2][1] + v.cord.z * m.m[2][2] + v.cord.w * m.m[2][3];
	o.w = v.cord.x * m.m[3][0] + v.cord.y * m.m[3][1] + v.cord.z * m.m[3][2] + v.cord.w * m.m[3][3];

	if (!(o.w < epsilon && o.w > -epsilon) && !(o.w < 1.0f + epsilon && o.w > 1.0f - epsilon))
	{
		o.x /= o.w;
		o.y /= o.w;
		o.z /= o.w;
	}
	return (create_point3d(o.x, o.y, o.z, v.color));
}

t_mat4x4  multiply_matrix4x4(t_mat4x4 m1, t_mat4x4 m2)
{
	t_mat4x4	mat;
	int         i;
	int         j;
	int         k;

	i = 0;
	while (i < 16)
	{
		*(*(mat.m) + i) = 0;
		i++;
	}

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				mat.m[i][j] += m1.m[i][k] * m2.m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (mat);
}
