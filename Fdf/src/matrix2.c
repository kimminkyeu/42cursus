/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:40:02 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 10:27:03 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/matrix.h"

t_mat4x4	multiply_matrix4x4(t_mat4x4 m1, t_mat4x4 m2)
{
	t_mat4x4	mat;
	int			i;
	int			j;
	int			k;

	i = -1;
	while (++i < 16)
		*(*(mat.m) + i) = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
				mat.m[i][j] += m1.m[i][k] * m2.m[k][j];
		}
	}
	return (mat);
}

t_mat4x4	set_z_unit(float _z_unit)
{
	static t_mat4x4	mat;

	mat.m[0][0] = 1.0f;
	mat.m[1][1] = 1.0f;
	mat.m[2][2] = _z_unit;
	mat.m[3][3] = 1.0f;
	return (mat);
}

/* scale from (0.0) */
t_mat4x4	scale_origin_3d(float _scale_rate)
{
	static t_mat4x4	mat;

	mat.m[0][0] = _scale_rate;
	mat.m[1][1] = _scale_rate;
	mat.m[2][2] = _scale_rate;
	mat.m[3][3] = 1.0f;
	return (mat);
}

/* sclae from (x, y, z) */
t_mat4x4	scale_point_3d(float _x, float _y, float _z, float _scale_rate)
{
	static t_mat4x4	mat;

	mat = multiply_matrix4x4(scale_origin_3d(_scale_rate), \
			translate_3d(-_x, -_y, -_z));
	mat = multiply_matrix4x4(translate_3d(_x, _y, _z), mat);
	return (mat);
}

t_mat4x4	fit_to_viewport(t_mlx *fdf)
{
	static t_mat4x4	mat;
	float			offset_x;
	float			offset_y;

	offset_x = (WIN_WIDTH - fdf->map_info.max_x) / 2;
	offset_y = (WIN_HEIGHT - fdf->map_info.max_y) / 2;
	mat = translate_3d(offset_x, offset_y, 0);
	return (mat);
}
