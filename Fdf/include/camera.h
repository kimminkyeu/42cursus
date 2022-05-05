/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:25:27 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 12:29:04 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "defines.h"
# include "draw_functions.h"
# include "../include/matrix.h"

/* Returns NULL on error */
extern t_camera	*camera_init(void);

extern t_mat4x4	isometric(void);
extern t_mat4x4	perspective(void);
extern t_mat4x4	parallel(void);
extern t_mat4x4	camera_tranform(t_mlx *fdf);
extern void		set_camera(t_camera *camera);

#endif /* CAMERA_H */
