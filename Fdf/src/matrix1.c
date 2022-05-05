/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:31:29 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 10:33:08 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/matrix.h"

t_mat4x4	translate_3d(float _x, float _y, float _z)
{
	static t_mat4x4	mat;

	mat.m[0][0] = 1.0f;
	mat.m[1][1] = 1.0f;
	mat.m[2][2] = 1.0f;
	mat.m[3][3] = 1.0f;
	mat.m[0][3] = _x;
	mat.m[1][3] = _y;
	mat.m[2][3] = _z;
	return (mat);
}

t_mat4x4	rotate_z_3d(float _degree)
{
	static t_mat4x4	mat;

	mat.m[0][0] = cosf(get_radian(_degree));
	mat.m[0][1] = -sinf(get_radian(_degree));
	mat.m[1][0] = sinf(get_radian(_degree));
	mat.m[1][1] = cosf(get_radian(_degree));
	mat.m[2][2] = 1.0f;
	mat.m[3][3] = 1.0f;
	return (mat);
}

t_mat4x4	rotate_x_3d(float _degree)
{
	static t_mat4x4	mat;

	mat.m[0][0] = 1.0f;
	mat.m[1][1] = cosf(get_radian(_degree));
	mat.m[1][2] = -sinf(get_radian(_degree));
	mat.m[2][1] = sinf(get_radian(_degree));
	mat.m[2][2] = cosf(get_radian(_degree));
	mat.m[3][3] = 1.0f;
	return (mat);
}

t_mat4x4	rotate_y_3d(float _degree)
{
	static t_mat4x4	mat;

	mat.m[0][0] = cosf(get_radian(_degree));
	mat.m[0][2] = -sinf(get_radian(_degree));
	mat.m[1][1] = 1.0f;
	mat.m[2][0] = sinf(get_radian(_degree));
	mat.m[2][2] = cosf(get_radian(_degree));
	mat.m[3][3] = 1.0f;
	return (mat);
}
