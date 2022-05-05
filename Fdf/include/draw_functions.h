/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:04:45 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 14:25:55 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_FUNCTIONS_H
# define DRAW_FUNCTIONS_H

# include "../include/defines.h"
# include "../include/camera.h"
# include "../include/matrix.h"
# include "../include/color.h"

extern void			draw_pixel(t_mlx *data, t_point3d p);
extern void			draw_line(t_mlx *fdf, t_point3d _p1, t_point3d _p2);
extern void			draw_background(t_mlx *data, \
		int width, int height, int color);

extern void			draw_map_objects(t_mlx *fdf, t_mat4x4 projection_matrix);

extern void			draw_vertical(t_mlx *fdf, \
		int x, int y, t_mat4x4 projection_matrix);
extern void			draw_horizontal(t_mlx *fdf, \
		int x, int y, t_mat4x4 projection_matrix);

/* Line drawing function */
extern void			bezier_linear(t_mlx *data, t_point3d p1, t_point3d p2);

extern float		get_radian(float degree);
extern t_point3d	create_point3d(int _x, int _y, int _z, int _color);
extern t_point3d	multiply_matrix_vec4(t_mat4x4 m, t_point3d v);
extern t_line		apply_matrix(t_mat4x4 matrix, t_line line);

extern int			get_cord_color(t_point3d p1, t_point3d p2, float offset);
extern t_point3d	get_point_x_y(t_mlx *fdf, size_t x, size_t y);
extern t_point3d	get_point_idx(t_darray *map, int index);

/* color shader includes Z-depth color shading */
extern int			color_shader(t_mlx *fdf, int color, int z_depth);

#endif /* DRAW_FUNCTIONS_H */
