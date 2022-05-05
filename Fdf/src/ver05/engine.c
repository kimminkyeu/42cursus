/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:16:30 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/03 16:34:16 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/engine.h"
#include "../include/draw_functions.h"
#include "../include/camera.h"

void engine_render(t_mlx *fdf)
{
	draw_background(fdf, DEFAULT_BG_COLOR);

	draw_map_objects(fdf, fdf->camera.projection_matrix);

	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->frame.img, 0, 0);
}

void engine_exit(t_mlx *fdf, bool is_error)
{
	if (fdf != NULL && fdf->frame.img != NULL)
	{
		ft_putstr_fd("-destroying image...\n", STDOUT);
		mlx_destroy_image(fdf->mlx, fdf->frame.img);
	}
	if (fdf != NULL && fdf->map != NULL)
	{
		ft_putstr_fd("-deleting map data...\n", STDOUT);
		delete_darray(&fdf->map);
	}
	if (fdf != NULL && fdf->mlx != NULL)
	{
		ft_putstr_fd("-freeing mlx memory...\n", STDOUT);
		free(fdf->mlx);
	}
	if (fdf != NULL)
	{
		ft_putstr_fd("-freeing fdf memory...\n", STDOUT);
		free(fdf);
	}
	if (is_error == ERROR)
	{
		perror("Error :");
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}

int handle_exit(t_mlx *fdf)
{
	ft_putstr_fd("Closing Programm....\n", STDOUT);
	engine_exit(fdf, SUCCESS);
	return (0);
}

/* ==============================================
 * TODO : handle input key here                 |
 * ==============================================
 * */
void handle_key_move(int key_code, t_mlx *fdf)
{
	if (key_code == KEY_UP)
	{
		ft_putstr_fd("move_up key pressed \n", STDOUT);
		fdf->camera.pos.y -= fdf->camera.move_speed;
	}
	else if (key_code == KEY_DOWN)
	{
		ft_putstr_fd("move_down key pressed \n", STDOUT);
		fdf->camera.pos.y += fdf->camera.move_speed;
	}
	else if (key_code == KEY_LEFT)
	{
		ft_putstr_fd("move_left key pressed \n", STDOUT);
		fdf->camera.pos.x -= fdf->camera.move_speed;
	}
	else if (key_code == KEY_RIGHT)
	{
		ft_putstr_fd("move_right key pressed \n", STDOUT);
		fdf->camera.pos.x += fdf->camera.move_speed;
	}
	ft_printf("camera position : x%d y%d z%d\n", fdf->camera.pos.x, fdf->camera.pos.y, fdf->camera.pos.z);
	engine_render(fdf);
}

void handle_key_esc(int key_code, t_mlx *fdf)
{
	if (key_code == KEY_ESC)
	{
		ft_putstr_fd("Exit key pressed, Closing Program...\n", STDOUT);
		engine_exit(fdf, SUCCESS);
	}
}

void handle_key_rotate(int key_code, t_mlx *fdf)
{
	if (key_code == KEY_A)
		fdf->camera.angle.y += fdf->camera.rotation_speed;
	if (key_code == KEY_D)
		fdf->camera.angle.y -= fdf->camera.rotation_speed;
	if (key_code == KEY_W)
		fdf->camera.angle.x += fdf->camera.rotation_speed;
	if (key_code == KEY_S)
		fdf->camera.angle.x -= fdf->camera.rotation_speed;
	if (key_code == KEY_Q)
		fdf->camera.angle.z += fdf->camera.rotation_speed;
	if (key_code == KEY_E)
		fdf->camera.angle.z -= fdf->camera.rotation_speed;
	ft_printf("camera angle : x%d y%d z%d\n", fdf->camera.angle.x, fdf->camera.angle.y, fdf->camera.angle.z);
	engine_render(fdf);
}


void handle_key_change_z(int key_code, t_mlx *fdf)
{
	if (key_code == KEY_INC)
	{
		if (fdf->camera.z_unit < 20.0f)
		{
			ft_printf("increasing Z-ratio...%d\n", (int)fdf->camera.z_unit);
			fdf->camera.z_unit += 0.1f;
		}
		else
			ft_printf("maximum Z-ratio\n");
	}
	else if (key_code == KEY_DEC)
	{
		if (fdf->camera.z_unit > 0.1f)
		{
			ft_printf("decreasing Z-ratio...%d\n", (int)fdf->camera.z_unit);
			fdf->camera.z_unit -= 0.1f;
		}
		else
			ft_printf("minimum Z-ratio\n");
	}
	engine_render(fdf);
}

/* TODO : what about using Enum Type ?  */
int handle_key_press(int key_code, void *param)
{
	t_mlx	*fdf = (t_mlx *)param;

	if (key_code == KEY_ESC)
		handle_key_esc(key_code, fdf);
	else if (key_code == KEY_UP || key_code == KEY_DOWN || key_code == KEY_LEFT || key_code == KEY_RIGHT)
		handle_key_move(key_code, fdf);
	else if (key_code == KEY_A || key_code == KEY_D || key_code == KEY_E || key_code == KEY_Q || key_code == KEY_S || key_code == KEY_W)
		handle_key_rotate(key_code, fdf);
	else if (key_code == KEY_INC || key_code == KEY_DEC)
		handle_key_change_z(key_code, fdf);
	else if (key_code == KEY_R)
	{
		ft_putstr_fd("Re-setting Camera... \n", STDOUT);
		camera_init(fdf);
		engine_render(fdf);
	}
	return (0);
}


void zoom_camera(int key_code, t_mlx *fdf)
{
	if (key_code == MOUSE_SCROLL_UP)
	{
		if (fdf->camera.zoom_rate < 50.0f)
		{
			ft_printf("zooming in...%d\n", (int)fdf->camera.zoom_rate);
			fdf->camera.zoom_rate += fdf->camera.zoom_speed;
		}
		else
			ft_printf("maximum zoom rate\n");
	}
	else if (key_code == MOUSE_SCROLL_DOWN)
	{
		if (fdf->camera.zoom_rate > 1.0f)
		{
			ft_printf("zooming out...%d\n", (int)fdf->camera.zoom_rate);
			fdf->camera.zoom_rate -= fdf->camera.zoom_speed;
		}
		else
			ft_printf("minimum zoom rate\n");
	}
	engine_render(fdf);
}

#include <stdio.h> // TODO : remove stdio header

int handle_mouse_press(int key_code, int x, int y, void *param)
{
	t_mlx       *fdf;

	fdf = (t_mlx *)param;
	(void)x;
	(void)y;
	if (key_code == MOUSE_SCROLL_UP || key_code == MOUSE_SCROLL_DOWN)
		zoom_camera(key_code, fdf);
	return (0);
}

void engine_set_event_loop(t_mlx *fdf)
{
	mlx_hook(fdf->win, ON_DESTROY, 0, handle_exit, fdf);
	mlx_hook(fdf->win, ON_KEY_PRESS, 0, handle_key_press, fdf);
	mlx_hook(fdf->win, ON_MOUSE_PRESS, 0, handle_mouse_press, fdf);
	mlx_loop(fdf->mlx);
}

t_mlx *engine_init(int _win_width, int _win_height, char *title)
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
	fdf->frame.img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->frame.addr = mlx_get_data_addr(fdf->frame.img, &(fdf->frame.bits_per_pixel), &(fdf->frame.line_length), &(fdf->frame.endian));
	camera_init(fdf);
	return (fdf);
}
