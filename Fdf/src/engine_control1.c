/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_control1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:54:25 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 12:30:17 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/engine.h"

void	handle_key_move(int key_code, t_mlx *fdf)
{
	if (key_code == KEY_UP)
		fdf->camera->pos.y -= fdf->camera->move_speed;
	else if (key_code == KEY_DOWN)
		fdf->camera->pos.y += fdf->camera->move_speed;
	else if (key_code == KEY_LEFT)
		fdf->camera->pos.x -= fdf->camera->move_speed;
	else if (key_code == KEY_RIGHT)
		fdf->camera->pos.x += fdf->camera->move_speed;
	engine_render(fdf);
}

void	handle_key_esc(int key_code, t_mlx *fdf)
{
	if (key_code == KEY_ESC)
		engine_exit(fdf, SUCCESS);
}

void	handle_key_rotate(int key_code, t_mlx *fdf)
{
	if (key_code == KEY_A)
		fdf->camera->angle.y += fdf->camera->rotation_speed;
	if (key_code == KEY_D)
		fdf->camera->angle.y -= fdf->camera->rotation_speed;
	if (key_code == KEY_W)
		fdf->camera->angle.x += fdf->camera->rotation_speed;
	if (key_code == KEY_S)
		fdf->camera->angle.x -= fdf->camera->rotation_speed;
	if (key_code == KEY_Q)
		fdf->camera->angle.z += fdf->camera->rotation_speed;
	if (key_code == KEY_E)
		fdf->camera->angle.z -= fdf->camera->rotation_speed;
	engine_render(fdf);
}

int	handle_key_press(int key_code, void *param)
{
	t_mlx	*fdf;

	fdf = (t_mlx *)param;
	if (key_code == KEY_ESC)
		handle_key_esc(key_code, fdf);
	else if (key_code == KEY_UP || key_code == KEY_DOWN \
			|| key_code == KEY_LEFT || key_code == KEY_RIGHT)
		handle_key_move(key_code, fdf);
	else if (key_code == KEY_A || key_code == KEY_D \
			|| key_code == KEY_E || key_code == KEY_Q \
			|| key_code == KEY_S || key_code == KEY_W)
		handle_key_rotate(key_code, fdf);
	else if (key_code == KEY_INC || key_code == KEY_DEC)
		handle_key_change_z(key_code, fdf);
	else if (key_code == KEY_1 || key_code == KEY_2 || key_code == KEY_3)
		handle_key_change_projection(key_code, fdf);
	else if (key_code == KEY_R)
	{
		set_camera(fdf->camera);
		engine_render(fdf);
	}
	return (0);
}
