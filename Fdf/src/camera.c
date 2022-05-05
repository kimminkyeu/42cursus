/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:36:47 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 15:47:25 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/camera.h"

extern void	engine_exit(t_mlx *data, bool is_error);

t_mat4x4	camera_tranform(t_mlx *fdf)
{
	static t_mat4x4	mat;

	mat = set_z_unit(fdf->camera->z_unit);
	mat = multiply_matrix4x4(rotate_x_3d(fdf->camera->angle.x), mat);
	mat = multiply_matrix4x4(rotate_y_3d(fdf->camera->angle.y), mat);
	mat = multiply_matrix4x4(rotate_z_3d(fdf->camera->angle.z), mat);
	mat = multiply_matrix4x4(translate_3d(fdf->camera->pos.x, \
				fdf->camera->pos.y, fdf->camera->pos.z), mat);
	mat = multiply_matrix4x4(scale_point_3d(fdf->camera->pos.x, \
				fdf->camera->pos.y, fdf->camera->pos.z, \
				fdf->camera->zoom_rate), mat);
	return (mat);
}

void	set_camera(t_camera *camera)
{
	camera->zoom_rate = 10.0f;
	camera->projection_matrix = isometric();
	camera->projection_num = ISOMETRIC;
	camera->angle.x = 0.0f;
	camera->angle.y = 0.0f;
	camera->angle.z = 0.0f;
	camera->pos.x = 0.0f;
	camera->pos.y = 0.0f;
	camera->pos.z = 0.0f;
	camera->z_unit = 0.1f;
	camera->z_shade_factor = 1.0f;
	camera->move_speed = 20.0f;
	camera->rotation_speed = 10.0f;
	camera->zoom_speed = 1.0f;
}

t_camera	*camera_init(void)
{
	t_camera	*camera;

	camera = ft_calloc(1, sizeof(*camera));
	if (camera != NULL)
		set_camera(camera);
	return (camera);
}
