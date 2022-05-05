/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:46:17 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 14:56:06 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*  */
# include "vector4.h"
# include "keymap_macos.h"
# include "libft.h"

# define ERROR				(1)
# define SUCCESS			(0)

# define ON					(1)
# define OFF				(-1)

# define BLACK				(0x00111111)
# define WHITE				(0x00ffffff)
# define RED				(0x00ee3333)
# define ORANGE				(0x00ff9900)
# define YELLOW				(0x00ffee00)
# define LIME				(0x00aacc11)
# define GREEN				(0x0044aa77)
# define CYAN				(0x000099ee)
# define BLUE				(0x000066bb)
# define VIOLETT			(0x00443388)
# define PURPLE				(0x00992288)
# define MAGENTA			(0x00ee0077)
# define GRAY				(0x00949494)

/* NOTE : Basic Settings for FDF
 * ========================================================= */
/* Window TITLE */
# define WIN_TITLE			("--- Minkyeki's 3D Engine ---")
/* Window Width */
# define WIN_WIDTH			(1920)
/* Window Height */
# define WIN_HEIGHT			(1080)
/* Window Point Color */
# define DEFAULT_PT_COLOR	(WHITE)
/* Window Background Color */
# define VIEWPORT_BG_COLOR	(BLACK)
/* Font Color */
# define FONT_COLOR			(GRAY)
/* ========================================================= */

/* Key maps defined in keymap_macos.h */
/* KEY_A | KEY_S | KEY_D | KEY_W | KEY_Q | KEY_E
 * KEY_UP | KEY_DOWN | KEY_LEFT | KEY_RIGHT 
 * KEY_ESC */

/* Projection Number */
# define ISOMETRIC		(1)
# define PARALLEL		(2)
# define PERSPECTIVE	(3)

/* ----------------------------------------------
 * * Point includes coordinate and color */
typedef struct s_point3d {
	t_vector4	cord;
	int			color;
}	t_point3d;

/* ----------------------------------------------
 * * line is an array of 2 points */
typedef union s_line {
	struct {
		t_point3d	p1;
		t_point3d	p2;
	};
	t_point3d		data[2];
}	t_line;

/* ----------------------------------------------
 * * Trangle is an array of 3 points */
typedef struct s_triangle {
	t_point3d	p[4];
}	t_triangle;

/* ----------------------------------------------
 * * Mesh is an array of trangles */
typedef struct s_mesh {
	t_darray	*trangles;
}	t_mesh;

/* ----------------------------------------------
 * * Matrix 4x4 */
typedef struct s_mat4x4 {
	float	m[4][4];
}	t_mat4x4;

/* ----------------------------------------------
 * * Structure for IMAGE */
typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

/* ----------------------------------------------
 * * For while loop in draw_function */
typedef struct s_map_info {
	int	max_x;
	int	max_y;
}	t_map_info;

/* ----------------------------------------------
 * * Camera Tranform data */
typedef struct s_camera {
	t_vector4		pos;
	t_vector4		angle;
	float			move_speed;
	float			rotation_speed;
	float			zoom_rate;
	float			zoom_speed;
	float			z_unit;
	float			z_shade_factor;
	t_mat4x4		projection_matrix;
	unsigned int	projection_num;
}	t_camera;

/* ----------------------------------------------
 * * For fdf data */
typedef struct s_mlx {
	void		*mlx;
	void		*win;
	t_darray	*map;
	t_map_info	map_info;
	t_image		frame;
	t_camera	*camera;
}	t_mlx;

#endif /* DEFINES_H */
