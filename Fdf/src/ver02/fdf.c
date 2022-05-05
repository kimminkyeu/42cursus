/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:54:43 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/27 22:07:38 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Libft */
# include "libft.h"
/* Map Reader */
# include "map_parser.h"
/* for engine */
# include "engine.h"
/* For define settings */
# include "defines.h"

int	main(int ac, char **av)
{
	t_mlx		*fdf;

	/* (0) allocate fdf object (t_mlx) */
	fdf = engine_init(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);

	/* (1) parse and store to D-array. Second paramter is init_size of D-array */
	fdf->map = mp_parse_file_malloc(mp_open_file(ac, av), 1024);


	/* (2) set_event --> key_settings  */
	fdf->setting.move_left = KEY_LEFT;
	fdf->setting.move_right = KEY_RIGHT;
	fdf->setting.move_up = KEY_UP;
	fdf->setting.move_down = KEY_DOWN;

	fdf->setting.rotate_left = KEY_A;
	fdf->setting.rotate_right = KEY_D;
	fdf->setting.rotate_up = KEY_W;
	fdf->setting.rotate_down = KEY_S;

	fdf->setting.zoom_in = MOUSE_SCROLL_UP;
	fdf->setting.zoom_out = MOUSE_SCROLL_DOWN;

	fdf->setting.key_exit = KEY_ESC;
	


	/* (4) main rendering function. */
	engine_render(fdf);


	/* (3) set key macro to close window. you can change this in fdf.h header */
	engine_set_event(fdf);


	return (0);
}
