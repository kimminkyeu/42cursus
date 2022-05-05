/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_control2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:04:04 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 11:32:43 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/engine.h"

int	handle_mouse_press(int key_code, int x, int y, void *param)
{
	t_mlx	*fdf;

	fdf = (t_mlx *)param;
	(void)x;
	(void)y;
	if (key_code == MOUSE_SCROLL_UP || key_code == MOUSE_SCROLL_DOWN)
		zoom_camera(key_code, fdf);
	return (0);
}

void	zoom_camera(int key_code, t_mlx *fdf)
{
	if (key_code == MOUSE_SCROLL_UP)
	{
		if (fdf->camera->zoom_rate < 50.0f)
			fdf->camera->zoom_rate += fdf->camera->zoom_speed;
		else
			ft_printf("maximum zoom rate\n");
	}
	else if (key_code == MOUSE_SCROLL_DOWN)
	{
		if (fdf->camera->zoom_rate > 1.0f)
			fdf->camera->zoom_rate -= fdf->camera->zoom_speed;
		else
			ft_printf("minimum zoom rate\n");
	}
	engine_render(fdf);
}

void	handle_key_change_z(int key_code, t_mlx *fdf)
{
	float	epsilon;

	epsilon = 0.00001f;
	if (key_code == KEY_INC)
	{
		if (fdf->camera->z_unit < (2.0f - epsilon))
			fdf->camera->z_unit += 0.1f;
		else
			ft_printf("maximum Z-ratio\n");
	}
	else if (key_code == KEY_DEC)
	{
		if (fdf->camera->z_unit > epsilon)
			fdf->camera->z_unit -= 0.1f;
		else
			ft_printf("minimum Z-ratio\n");
	}
	engine_render(fdf);
}

void	handle_key_change_projection(int key_code, t_mlx *fdf)
{
	if (key_code == KEY_1)
	{
		fdf->camera->projection_matrix = isometric();
		fdf->camera->projection_num = ISOMETRIC;
	}
	else if (key_code == KEY_2)
	{
		fdf->camera->projection_matrix = parallel();
		fdf->camera->projection_num = PARALLEL;
	}
	else if (key_code == KEY_3)
	{
		fdf->camera->projection_matrix = perspective();
		fdf->camera->projection_num = PERSPECTIVE;
	}
	engine_render(fdf);
}

int	handle_exit(t_mlx *fdf)
{
	ft_putstr_fd("Closing Programm....\n", STDOUT);
	engine_exit(fdf, SUCCESS);
	return (0);
}
