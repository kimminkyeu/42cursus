/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:36:38 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 14:06:15 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/matrix.h"

t_mat4x4	parallel(void)
{
	static t_mat4x4	mat;

	mat.m[0][0] = 1.0f;
	mat.m[1][1] = 1.0f;
	mat.m[2][2] = 1.0f;
	mat.m[3][3] = 1.0f;
	return (mat);
}

t_mat4x4	isometric(void)
{
	static t_mat4x4	mat;

	mat.m[0][0] = cosf(get_radian(30.0f));
	mat.m[0][1] = -cosf(get_radian(30.0f));
	mat.m[1][0] = sinf(get_radian(30.0f));
	mat.m[1][1] = sinf(get_radian(30.0f));
	mat.m[1][2] = -1.0f;
	mat.m[2][2] = 1.0f;
	mat.m[3][3] = 1.0f;
	return (mat);
}

t_mat4x4	perspective(void)
{
	static t_mat4x4	mat;

	mat.m[0][0] = 1.0f;
	mat.m[1][1] = 1.0f;
	mat.m[2][2] = 1.0f;
	mat.m[3][3] = 1.0f;
	return (mat);
}
