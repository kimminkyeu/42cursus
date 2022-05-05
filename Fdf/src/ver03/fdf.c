/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:54:43 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/28 16:09:26 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Libft */
# include "../include/libft.h"
/* Map Reader */
# include "../include/map_parser.h"
/* for engine */
# include "../include/engine.h"
/* For define settings */
# include "../include/defines.h"

/* NOTE : test for animation and control */
# include "../include/circle.h"

int	main(int ac, char **av)
{
	t_mlx		*fdf;

	/* (0) allocate fdf object (t_mlx) */
	fdf = engine_init(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);


	/* (1) parse and store to D-array. Second paramter is init_size of D-array */
	fdf->map = mp_parse_file_malloc(mp_open_file(ac, av), 1024);


	/* (2) make object data array for animation --> this would turn to trangles 
	 * Warning : darray objects must include allocated pointer */
	t_circle	*c1 = init_circle(WIN_WIDTH / 2, WIN_HEIGHT / 2, BLACK, WIN_HEIGHT / 4);

	fdf->object = new_darray_malloc(10);
	/** printf("color=%d pos=[%d,%d] size=%f \n", c1->color, c1->x, c1->y, c1->size); */
	darray_push_back(fdf->object, c1);
	/** printf("size in main : %zd\n", fdf->object->size); */

	/* (4) main rendering function. */
	engine_render(fdf);

	/* (3) set key macro to close window. you can change this in fdf.h header */
	engine_set_event_loop(fdf);

	/* (Important!) loop engine for animation */
	mlx_loop(fdf->mlx);

	return (0);
}
