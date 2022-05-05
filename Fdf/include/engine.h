/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:48:11 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 09:37:37 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

/* for Exit */
# include <stdlib.h>
/* for Perror */
# include <stdio.h>
/* for isError flag */
# include <stdbool.h>

# include "../include/libft.h"
# include "../mlx_mms/mlx.h"
# include "../include/defines.h"
# include "../include/camera.h"
# include "../include/matrix.h"

# define STDOUT (1)

extern t_mlx	*engine_init(int win_width, int win_height, char *title);
extern void		engine_render(t_mlx *data);
extern void		engine_exit(t_mlx *data, bool is_error);
extern void		engine_set_event_loop(t_mlx *data);

extern int		handle_exit(t_mlx *fdf);
extern void		handle_key_move(int key_code, t_mlx *fdf);
extern void		handle_key_esc(int key_code, t_mlx *fdf);
extern void		handle_key_rotate(int key_code, t_mlx *fdf);
extern void		handle_key_change_z(int key_code, t_mlx *fdf);
extern void		handle_key_change_projection(int key_code, t_mlx *fdf);
extern int		handle_key_press(int key_code, void *param);
extern int		handle_mouse_press(int key_code, int x, int y, void *param);
extern void		zoom_camera(int key_code, t_mlx *fdf);

extern void		draw_control_panel(t_mlx *fdf, int font_color);

#endif /* ENGINE_H */
