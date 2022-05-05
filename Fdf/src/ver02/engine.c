/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:16:30 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/27 22:13:16 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/engine.h"
#include "../include/draw_functions.h"
#include "../include/defines.h"

int	engine_render(t_mlx *data)
{
	draw_background_on_image(data, WIN_WIDTH, WIN_HEIGHT, DEFAULT_BG_COLOR);

	// TODO : draw functions here ...
	draw_triangle_on_image(data, data->map);
	
	





	mlx_put_image_to_window(data->mlx, data->win, data->frame.img, 0, 0);
	return (0);
}


/* close engine, free image data.  */
/* FIXME : Segmentation fault */
void	engine_exit(t_mlx *fdf, bool is_error)
{
	if (fdf->frame.img != NULL)
		mlx_destroy_image(fdf->mlx, fdf->frame.img);
	if (fdf->mlx != NULL)
		free(fdf->mlx);
	if (fdf->map != NULL)
		delete_darray(&fdf->map);
	free(fdf);
	if (is_error == ERROR)
	{
		perror("Error :");
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}

int	handle_exit(t_mlx *data)
{
	ft_putstr_fd("Closing Programm....\n", STDOUT);
	engine_exit(data, SUCCESS);

	return (0);
}

/* ==============================================
 * TODO : handle input key here                 |
 * ==============================================
 * */

int	handle_key_press(int key_code, void *param)
{
	t_mlx	*data = (t_mlx *)param;
	if (key_code == data->setting.key_exit)
	{
		ft_putstr_fd("Exit key pressed, Closing Programm...\n", STDOUT);
		engine_exit(data, SUCCESS);
	}
	else if (key_code == data->setting.rotate_left)
	{
		ft_putstr_fd("rotate_left key pressed \n", STDOUT);
		// TODO : make events accordingly
	}
	else if (key_code == data->setting.rotate_right)
	{
		ft_putstr_fd("rotate_right key pressed \n", STDOUT);
		// TODO : make events accordingly
	}
	else if (key_code == data->setting.rotate_up)
	{
		ft_putstr_fd("rotate_up key pressed \n", STDOUT);
		// TODO : make events accordingly
	}
	else if (key_code == data->setting.rotate_down)
	{
		ft_putstr_fd("rotate_down key pressed \n", STDOUT);
		// TODO : make events accordingly
	}
	else if (key_code == data->setting.move_up)
	{
		ft_putstr_fd("move_up key pressed \n", STDOUT);
		// TODO : make events accordingly
	}
	else if (key_code == data->setting.move_down)
	{
		ft_putstr_fd("move_down key pressed \n", STDOUT);
		// TODO : make events accordingly
	}
	else if (key_code == data->setting.move_left)
	{
		ft_putstr_fd("move_left key pressed \n", STDOUT);
		// TODO : make events accordingly
	}
	else if (key_code == data->setting.move_right)
	{
		ft_putstr_fd("move_right key pressed \n", STDOUT);
		// TODO : make events accordingly
	}
	return (0);
}

/* NOTE : 어떤 이벤트냐에 따라 파라미터가 달라짐....
 * 이거때매 오류 생김 ㅋ 이건 w11 메뉴얼을 볼 것.  */
int handle_mouse_press(int key_code, int x, int y, void *param)
{
	t_mlx	*data = (t_mlx *)param;

	(void)x;
	(void)y;

	if (key_code == data->setting.zoom_in)
	{
		ft_putstr_fd("zoom_in pressed\n", STDOUT);
		// TODO : make events accordingly
	}
	else if (key_code == data->setting.zoom_out)
	{
		ft_putstr_fd("zoom_out pressed\n", STDOUT);
		// TODO : make events accordingly
	}
	else if (key_code == MOUSE_LEFT_CLICK)
	{
		ft_putstr_fd("mouse left click pressed\n", STDOUT);
		// TODO : make events accordingly
	}
	else if (key_code == MOUSE_RIGHT_CLICK)
	{
		ft_putstr_fd("mouse right click pressed\n", STDOUT);
		// TODO : make events accordingly
	}
	return (0);
}

void	engine_set_event(t_mlx *data)
{
	/* destroy window event  */
	mlx_hook(data->win, ON_DESTROY, 0, handle_exit, data);

	/* key click event  */
	mlx_hook(data->win, ON_KEY_PRESS, 0, handle_key_press, data);
	
	/* mouse click event  */
	mlx_hook(data->win, ON_MOUSE_PRESS, 0, handle_mouse_press, data);
	/** mlx_mouse_hook(data->win, handle_mouse_press, data); */

	/* loop engine  */
	mlx_loop(data->mlx);
}

/* init_engine, detect error */
t_mlx	*engine_init(int _win_width, int _win_height, char *title)
{
	t_mlx	*fdf;

	/* TODO : free fdf!   */
	fdf = ft_calloc(1, sizeof(*fdf));
	fdf->mlx = mlx_init();

	if (fdf->mlx == NULL)
		engine_exit(fdf, ERROR);
	fdf->win = mlx_new_window(fdf->mlx, _win_width, _win_height, title);
	if (fdf->win == NULL)
		engine_exit(fdf, ERROR);

	/* Settings  */
	fdf->setting.win_width = _win_width;
	fdf->setting.win_height = _win_height;

	/* Init image  */
	fdf->frame.img = mlx_new_image(fdf->mlx, fdf->setting.win_width, fdf->setting.win_height);
	fdf->frame.addr = mlx_get_data_addr(fdf->frame.img, &(fdf->frame.bits_per_pixel), &(fdf->frame.line_length), &(fdf->frame.endian));

	return (fdf);
}
