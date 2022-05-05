/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:16:30 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/28 16:21:40 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/engine.h"
#include "../include/draw_functions.h"
#include "../include/defines.h"
#include "../include/circle.h"

/** void	darray_iterate(t_darray *arr, void (*f)(void *))
  * {
  *     size_t	i;
  *
  *     i = 0;
  *     while (i < arr->size)
  *     {
  *         f(arr->data[i]);
  *         i++;
  *     }
  * }
  *  */
/* iterate given object darray and draw them.  */
/* NOTE : Move this to header  */

int	engine_render(t_mlx *fdf)
{
	draw_background_on_image(fdf, WIN_WIDTH, WIN_HEIGHT, DEFAULT_BG_COLOR);

	/** printf("engin_render:%zd\n", fdf->object->size); */


	// TODO : draw functions here ...
	
	/* NOTE : 객체를 순회하면서, draw를 적용한다면... 객체에 추가할 때 마다 그리게 되는 건가? */
	/** draw_circle_objects(fdf); */
	
	draw_circle_objects(fdf);




	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->frame.img, 0, 0);
	return (0);
}


/* close engine, free image fdf.  */
/* FIXME : Segmentation fault here? */
void	engine_exit(t_mlx *fdf, bool is_error)
{
	if (fdf->frame.img != NULL)
	{
		ft_putstr_fd("-destroying image...\n", STDOUT);
		mlx_destroy_image(fdf->mlx, fdf->frame.img);
	}
	if (fdf->map != NULL)
	{
		ft_putstr_fd("-deleting map data...\n", STDOUT);
		delete_darray(&fdf->map);
	}
	if (fdf->object != NULL)
	{
		ft_putstr_fd("-deleting object datas...\n", STDOUT);
		delete_darray(&fdf->object);
	}
	if (fdf->mlx != NULL)
	{
		ft_putstr_fd("-freeing mlx memory...\n", STDOUT);
		free(fdf->mlx);
	}
	ft_putstr_fd("-freeing fdf memory...\n", STDOUT);
	free(fdf);
	if (is_error == ERROR)
	{
		perror("Error :");
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}

int	handle_exit(t_mlx *fdf)
{
	ft_putstr_fd("Closing Programm....\n", STDOUT);
	engine_exit(fdf, SUCCESS);

	return (0);
}

/* ==============================================
 * TODO : handle input key here                 |
 * ==============================================
 * */
int	handle_key_move(int key_code, void *param)
{
	t_mlx	*fdf = (t_mlx *)param;

	t_circle *obj = (t_circle *)(fdf->object->data[0]);

	if (key_code == KEY_UP)
	{
		ft_putstr_fd("move_up key pressed \n", STDOUT);
		obj->y -= 10;
		printf("y : %d\n", obj->y);
		engine_render(fdf);
		// TODO : make events accordingly
	}
	else if (key_code == KEY_DOWN)
	{
		ft_putstr_fd("move_down key pressed \n", STDOUT);
		obj->y += 10;
		printf("y : %d\n", obj->y);
		engine_render(fdf);
		// TODO : make events accordingly
	}
	else if (key_code == KEY_LEFT)
	{
		ft_putstr_fd("move_left key pressed \n", STDOUT);
		// TODO : make events accordingly
		obj->x -= 10;
		printf("x : %d\n", obj->y);
		engine_render(fdf);
	}
	else if (key_code == KEY_RIGHT)
	{
		ft_putstr_fd("move_right key pressed \n", STDOUT);
		// TODO : make events accordingly
		obj->x += 10;
		printf("x : %d\n", obj->y);
		engine_render(fdf);
	}


	return (0);
}

int	handle_key_rotate(int key_code, void *param)
{
	t_mlx	*fdf = (t_mlx *)param;

	(void)fdf;

	if (key_code == KEY_W) // rotate up
	{
		ft_putstr_fd("rotate_left key pressed \n", STDOUT);
		// TODO : make events accordingly
	}
	else if (key_code == KEY_S) // rotate down
	{
		ft_putstr_fd("rotate_right key pressed \n", STDOUT);
		// TODO : make events accordingly
	}
	else if (key_code == KEY_A) // rotate left
	{
		ft_putstr_fd("rotate_up key pressed \n", STDOUT);
		// TODO : make events accordingly
	}
	else if (key_code == KEY_D) // rotate right
	{
		ft_putstr_fd("rotate_down key pressed \n", STDOUT);
		// TODO : make events accordingly
	}

	return (0);
}

int	handle_key_esc(int key_code, void *param)
{
	t_mlx	*fdf = (t_mlx *)param;

	if (key_code == KEY_ESC)
	{
		ft_putstr_fd("Exit key pressed, Closing Programm...\n", STDOUT);
		engine_exit(fdf, SUCCESS);
	}
		return (0);
}

/* TODO : what about using Enum Type ?  */
int	handle_key_press(int key_code, void *param)
{
	if (key_code == KEY_ESC)
		handle_key_esc(key_code, param);
	else if (key_code < 14)
		handle_key_rotate(key_code, param);
	else
		handle_key_move(key_code, param);
	return (0);
}


/* NOTE : 어떤 이벤트냐에 따라 파라미터가 달라짐....
 * 이거때매 오류 생김 ㅋ 이건 w11 메뉴얼을 볼 것.  */
int handle_mouse_press(int key_code, int x, int y, void *param)
{
	t_mlx	*fdf = (t_mlx *)param;

	(void)fdf;
	(void)x;
	(void)y;

	if (key_code == MOUSE_SCROLL_UP)
	{
		ft_putstr_fd("mouse zoom_in\n", STDOUT);
		// TODO : make events accordingly
	}
	else if (key_code == MOUSE_SCROLL_DOWN)
	{
		ft_putstr_fd("mouse zoom_out\n", STDOUT);
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

void	engine_set_event_loop(t_mlx *fdf)
{
	/* destroy window event  */
	mlx_hook(fdf->win, ON_DESTROY, 0, handle_exit, fdf);

	/* key click event  */
	mlx_hook(fdf->win, ON_KEY_PRESS, 0, handle_key_press, fdf);
	
	/* mouse click event  */
	mlx_hook(fdf->win, ON_MOUSE_PRESS, 0, handle_mouse_press, fdf);
}

/* init_engine, detect error */
t_mlx	*engine_init(int _win_width, int _win_height, char *title)
{
	t_mlx	*fdf;

	/* TODO : free fdf!   */
	fdf = ft_calloc(1, sizeof(*fdf));
	if (fdf == NULL)
		engine_exit(fdf, ERROR);
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		engine_exit(fdf, ERROR);
	fdf->win = mlx_new_window(fdf->mlx, _win_width, _win_height, title);
	if (fdf->win == NULL)
		engine_exit(fdf, ERROR);

	/* init image  */
	fdf->frame.img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->frame.addr = mlx_get_data_addr(fdf->frame.img, &(fdf->frame.bits_per_pixel), &(fdf->frame.line_length), &(fdf->frame.endian));

	return (fdf);
}
