/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:37:28 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 10:40:05 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "vector4.h"
# include "defines.h"
# include "draw_functions.h"

/* multiply two matrices and returns result */
extern t_mat4x4	multiply_matrix4x4(t_mat4x4 m1, t_mat4x4 m2);

/* translate on x-axis or y-axis or z-axis */
extern t_mat4x4	translate_3d(float _x, float _y, float _z);

/* roate on x-axis or y-axis or z-axis */
extern t_mat4x4	rotate_x_3d(float _degree);
extern t_mat4x4	rotate_y_3d(float _degree);
extern t_mat4x4	rotate_z_3d(float _degree);

/* shear on x-direction or y-direction or z-direction */
extern t_mat4x4	shear_x_3d(float _degree);
extern t_mat4x4	shear_y_3d(float _degree);
extern t_mat4x4	shear_z_3d(float _degree);

/* scale from origin (0,0,0) */
extern t_mat4x4	scale_origin_3d(float _scale_rate);
/* scale from point (x, y, z) */
extern t_mat4x4	scale_point_3d(float _x, float _y, float _z, float _scale_rate);

extern t_mat4x4	set_z_unit(float _z_unit);
extern t_mat4x4	fit_to_viewport(t_mlx *fdf);

#endif /* MATRIX_H */
