/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:16:30 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 12:29:46 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/engine.h"

void	engine_render(t_mlx *fdf)
{
	draw_background(fdf, WIN_WIDTH, WIN_HEIGHT, VIEWPORT_BG_COLOR);
	draw_map_objects(fdf, fdf->camera->projection_matrix);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->frame.img, 0, 0);
	draw_control_panel(fdf, FONT_COLOR);
}

void	engine_exit(t_mlx *fdf, bool is_error)
{
	if (fdf != NULL && fdf->frame.img != NULL)
		mlx_destroy_image(fdf->mlx, fdf->frame.img);
	if (fdf != NULL && fdf->map != NULL)
		delete_darray(&fdf->map);
	if (fdf != NULL && fdf->mlx != NULL)
		free(fdf->mlx);
	if (fdf != NULL && fdf->camera != NULL)
		free(fdf->camera);
	if (fdf != NULL)
		free(fdf);
	if (is_error == ERROR)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

t_mlx	*engine_init(int _win_width, int _win_height, char *title)
{
	t_mlx	*fdf;

	fdf = ft_calloc(1, sizeof(*fdf));
	if (fdf == NULL)
		engine_exit(fdf, ERROR);
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		engine_exit(fdf, ERROR);
	fdf->win = mlx_new_window(fdf->mlx, _win_width, _win_height, title);
	if (fdf->win == NULL)
		engine_exit(fdf, ERROR);
	fdf->camera = camera_init();
	if (fdf->camera == NULL)
		engine_exit(fdf, ERROR);
	if (fdf->frame.img == NULL)
	{
		fdf->frame.img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
		fdf->frame.addr = mlx_get_data_addr(fdf->frame.img, \
				&(fdf->frame.bits_per_pixel), \
				&(fdf->frame.line_length), &(fdf->frame.endian));
	}
	return (fdf);
}

void	engine_set_event_loop(t_mlx *fdf)
{
	mlx_hook(fdf->win, ON_DESTROY, 0, handle_exit, fdf);
	mlx_hook(fdf->win, ON_KEY_PRESS, 0, handle_key_press, fdf);
	mlx_hook(fdf->win, ON_MOUSE_PRESS, 0, handle_mouse_press, fdf);
	mlx_loop(fdf->mlx);
}
