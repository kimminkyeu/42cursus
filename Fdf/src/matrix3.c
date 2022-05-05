/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:34:54 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 14:05:12 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/matrix.h"

/* FIXME : handle matrix accordingly  */
t_mat4x4	shear_x_3d(float degree)
{
	t_mat4x4	mat;

	mat.m[0][0] = 1.0f;
	mat.m[0][1] = tanf(get_radian(degree));
	mat.m[1][1] = 1.0f;
	mat.m[2][2] = 1.0f;
	mat.m[3][3] = 1.0f;
	return (mat);
}

/* FIXME : handle matrix accordingly  */
t_mat4x4	shear_y_3d(float degree)
{
	t_mat4x4	mat;

	mat.m[0][0] = 1.0f;
	mat.m[1][0] = tanf(get_radian(degree));
	mat.m[1][1] = 1.0f;
	mat.m[2][2] = 1.0f;
	mat.m[3][3] = 1.0f;
	return (mat);
}

/* FIXME : handle matrix accordingly  */
t_mat4x4	shear_z_3d(float degree)
{
	t_mat4x4	mat;

	mat.m[0][0] = 1.0f;
	mat.m[1][1] = 1.0f;
	mat.m[2][1] = tanf(get_radian(degree));
	mat.m[2][2] = 1.0f;
	mat.m[3][3] = 1.0f;
	return (mat);
}
