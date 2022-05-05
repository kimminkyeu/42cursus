/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:54:43 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/03 18:28:31 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Map Reader */
# include "../include/map_parser.h"
/* for engine */
# include "../include/engine.h"
/* For define settings */
# include "../include/camera.h"
# include "../include/control_panel.h"

int	main(int ac, char **av)
{
	t_mlx		*fdf;
	int			fd;

	/* (0) allocate fdf object (t_mlx) */
	fdf = engine_init(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);

	/* (0) parse and store map data. */
	fd = mp_open_file(ac, av);
	fdf->map = mp_parse_file_malloc(fd, 256);
	close(fd);
	fdf->map_info.max_x = ((t_point3d *)fdf->map->data[fdf->map->size - 1])->cord.x;
	fdf->map_info.max_y = ((t_point3d *)fdf->map->data[fdf->map->size - 1])->cord.y;

	engine_render(fdf);

	/* (2) set key macro to close window. you can change this in fdf.h header */
	engine_set_event_loop(fdf);

	return (0);
}
