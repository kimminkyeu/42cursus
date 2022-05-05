/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:12:53 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/28 11:14:31 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/draw_functions.h"

/* ----------------------------------------------
 * * Convert Degree to Radian */

float get_radian(float degree)
{
	return (degree / 180.0f * 3.141592f);
}

/* ----------------------------------------------
 * * TODO : 반드시 엔디안과 비트 쉬프트 부분을 이해할 것!  */
void	draw_pixel_on_image(t_mlx *data, t_vector3 pos_and_color)
{
	char	*pixel;

	if (pos_and_color.x < WIN_WIDTH && pos_and_color.x > 0 && \
			pos_and_color.y < WIN_HEIGHT && pos_and_color.y > 0)
	{
		/* NOTE : dst의 주소를 알아내는 연산.
		 * 쉽게 보면 이미지의 2차원 배열의 1차원 index를 알아내는 거임! */
		pixel = data->frame.addr + (pos_and_color.y * data->frame.line_length + pos_and_color.x * (data->frame.bits_per_pixel / 8));

		*(unsigned int *)pixel = pos_and_color.color;
		/* NOTE : 계산한 dst에 색 정보 저장 */
		/** int i = data->frame.bits_per_pixel - 8; */
		/** while (i >= 0) */
		/** { */
		/**     // Big endian, MSB is the leftmost bit */
		/**     if (data->frame.endian != 0) */
		/**     { */
		/**         *pixel++ = (pos_and_color.color >> i) & 0xFF; */
		/**     } */
		/**     // Little endian, LSB is the leftmost bit */
		/**     else */
		/**     { */
		/**         *pixel++ = (pos_and_color.color >> (data->frame.bits_per_pixel - 8 - i)) & 0xFF; */
		/**     } */
		/**     i -= 8; */
		/** } */
	}
}

/* ----------------------------------------------
 * * */
void	draw_background_on_image(t_mlx *data, int width, int height, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			draw_pixel_on_image(data, create_data_vec3(j, i, color));
			j += 1;
		}
		i += 1;
	}
}


/* ----------------------------------------------
 * * */


/* =============================
 * |   Line Drawing Equations   |
 * =============================*/

void	dda_line(t_mlx *data, t_vector3 _pos1, t_vector3 _pos2)
{
	int			dx;
	int			dy;
	int			steps;
	t_vector3	point;

	dx = _pos2.x - _pos1.x;
	dy = _pos2.y - _pos1.y;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	point.x = _pos1.x;
	point.y = _pos1.y;
	point.color = _pos1.color;
	while (steps > 0)
	{
		draw_pixel_on_image(data, point);
		point.x += (float)(dx / (float)steps);
		point.y += (float)(dy / (float)steps);
		point.color += (float)(dy / (float)steps);
		steps -= 1;
	}
}

	/* FIXME : 지금 알고리즘 굉장히 이상함. 선을 못그림.  */
void	bresenham_line(t_mlx *data, t_vector3 _pos1, t_vector3 _pos2)
{
	int			m_new;
	int			slope_error_new;
	t_vector3	point;

	m_new = 2 * (_pos2.y - _pos1.y);
	slope_error_new = m_new - (_pos2.x - _pos1.x);

	point.x = _pos1.x;
	point.y = _pos1.y;
	point.color = _pos1.color;
	while (point.x < _pos2.x)
	{
		draw_pixel_on_image(data, point);
		slope_error_new += m_new;
		if (slope_error_new >= 0)
		{
			point.y += 1;
			point.color += 1;
			slope_error_new -= 2 * (_pos2.x - _pos1.x);
		}
		point.x += 1;
	}
}


/* NOTE : Linear Bezier Curve 응용 [ (1-t)P1 + tP2 (0<=t<=1) ] */
void	bezier_linear(t_mlx *data, t_vector3 _pos1, t_vector3 _pos2)
{
	int				ndots;
	float			t;
	float			offset;
	t_vector3		point;

	ndots = 2000;
	t = 0;
	while (t < ndots)
	{
		offset = t / ndots;
		point.x = ((1 - offset) * _pos1.x) + (offset * _pos2.x);
		point.y = ((1 - offset) * _pos1.y) + (offset * _pos2.y);
		point.color = ((1 - offset) * _pos1.color) + (offset * _pos2.color);
		draw_pixel_on_image(data, point);
		t += 1;
	}
}

/* TODO : 꼭 이 함수도 완성하기!  */
// void	bezier_quadratic();
// void	bezier_cubic();


/* TODO : choose internal equations. enable gradient setting */
void	draw_line_on_image(t_mlx *data, t_vector3 _pos1, t_vector3 _pos2)
{
	bezier_linear(data, _pos1, _pos2);
	// bresenham_line(img, _pos1, _pos2);
	/* dda_line(img, _pos1, _pos2); */
}

// void drawGrid(int trgb, float dx)
// {
//     return ;
// }


/* NOTE : Affine transformations */
// void translate(float pos_x, float pos_y)
// {
//     return ;
// }
//
// void rotate(float degree)
// {
//     return ;
// }
//
// void scale(float scale_x, float scale_y)
// {
//     return ;
// }


/* NOTE : Other options */
// void setLineWidth(float width)
// {
//     return ;
// }


static t_vector4	get_point_vec4(t_darray *map, int x, int y)
{
	int	col_num;
	int	index;

	col_num = ((t_vector4 *)(map->data[map->size - 1]))->x + 1;
	index = y * col_num + x;

	return (*((t_vector4 *)(map->data[index])));
}

static t_vector4	multiply_matrix_vec4(t_vector4 v, t_mat4x4 m)
{
	t_vector4	o;
	float		w;

	o.x = v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0] + m.m[3][0];
	o.y = v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1] + m.m[3][1];
	o.z = v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] + m.m[3][2];
	w = v.x * m.m[0][3] + v.y * m.m[1][3] + v.z * m.m[2][3] + m.m[3][3];

	if (w != 0.0f)
	{
		o.x /= w;
		o.y /= w;
		o.z /= w;
	}
	return (o);
}

/* NOTE : used static variable to initializes only once  */
static t_mat4x4	get_perspective_matrix(void)
{
	static t_mat4x4	mat_proj;
	float fNear = 0.1f;
	float fFar = 1000.0f;
	float fFov = 90.0f;
	float fAspectRatio = (float)WIN_HEIGHT / (float)WIN_WIDTH;
	float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);

	mat_proj.m[0][0] = fAspectRatio * fFovRad;
	mat_proj.m[1][1] = fFovRad;
	mat_proj.m[2][2] = fFar / (fFar - fNear);
	mat_proj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
	mat_proj.m[2][3] = 1.0f;
	mat_proj.m[3][3] = 0.0f;

	return (mat_proj);
}

static t_mat4x4	get_rotate_x_matrix(float fTheta)
{
	static t_mat4x4	mat_proj;

	mat_proj.m[0][0] = 1;
	mat_proj.m[1][1] = cosf(fTheta * 0.5f);
	mat_proj.m[1][2] = sinf(fTheta * 0.5f);
	mat_proj.m[2][1] = -sinf(fTheta * 0.5f);
	mat_proj.m[2][2] = cosf(fTheta * 0.5f);
	mat_proj.m[3][3] = 1;

	return (mat_proj);
}

/** static t_mat4x4	get_rotate_y_matrix(float fTheta)
  * {
  *     static t_mat4x4	mat_proj;
  *
  *     mat_proj.m[0][0] =
  *     mat_proj.m[1][1] =
  *     mat_proj.m[2][2] =
  *     mat_proj.m[3][2] =
  *     mat_proj.m[2][3] =
  *     mat_proj.m[3][3] =
  *
  *     return (mat_proj);
  * } */

static t_mat4x4	get_rotate_z_matrix(float fTheta)
{
	static t_mat4x4	mat_proj;

	mat_proj.m[0][0] = cosf(fTheta);
	mat_proj.m[0][1] = sinf(fTheta);
	mat_proj.m[1][0] = -sinf(fTheta);
	mat_proj.m[1][1] = cosf(fTheta);
	mat_proj.m[2][2] = 1;
	mat_proj.m[3][3] = 1;

	return (mat_proj);
}

/* retuns t_vector3 (x, y, color) data 
 * TODO : make this projection */
t_vector3	project_point_to_2d(t_vector4 point, t_mat4x4 projection_matrix)
{	
	t_vector4	result;

	result = multiply_matrix_vec4(point, projection_matrix);
	return (create_data_vec3(result.x, result.y, point.color));
}


// Project each point. -> result will be 2d result (vec3)
// NOTE : https://www.youtube.com/watch?v=ih20l3pJoeU&t=1841s --> study here
void	draw_triangle_on_image(t_mlx *data, t_darray *map)
{
	
	int			i;
	int			j;
	t_vector4	last_point;
	
	/* for x, y  calculation  */
	last_point = *((t_vector4 *)(map->data[map->size - 1]));

/** 
 *   p1  p2
 *    o--o  o  o
 *    |\ |
 *    | \|  
 *    o--o  o  o
 *   p3 p4
 *
 *    o  o  o  o
 * */



	t_mat4x4	perspective = get_perspective_matrix();

	j = 0;
	while (j < last_point.y)
	{
		i = 0;
		while (i < last_point.x)
		{
			t_vector4 p1_r = get_point_vec4(map, i, j);
			t_vector4 p2_r = get_point_vec4(map, i+1, j);
			t_vector4 p3_r = get_point_vec4(map, i, j+1);
			t_vector4 p4_r = get_point_vec4(map, i+1, j+1);
            /**  */

			float angle1 = 0.0f;
			p1_r = multiply_matrix_vec4(p1_r, (get_rotate_x_matrix(angle1)));
			p2_r = multiply_matrix_vec4(p2_r, (get_rotate_x_matrix(angle1)));
			p3_r = multiply_matrix_vec4(p3_r, (get_rotate_x_matrix(angle1)));
			p4_r = multiply_matrix_vec4(p4_r, (get_rotate_x_matrix(angle1)));
            /**  */
			float fTheta = 0.0f;
			p1_r = multiply_matrix_vec4(p1_r, get_rotate_z_matrix(fTheta));
			p2_r = multiply_matrix_vec4(p2_r, get_rotate_z_matrix(fTheta));
			p3_r = multiply_matrix_vec4(p3_r, get_rotate_z_matrix(fTheta));
			p4_r = multiply_matrix_vec4(p4_r, get_rotate_z_matrix(fTheta));

            /**  */
			/** t_vector4 p1_f = p1_r; */
			/** p1_f.z += 1.0f; */
			/** t_vector4 p2_f = p2_r; */
			/** p2_f.z += 1.0f; */
			/** t_vector4 p3_f = p3_r; */
			/** p3_f.z += 1.0f; */
			/** t_vector4 p4_f = p4_r; */
			/** p4_f.z += 1.0f; */
            /**  */
            /**  */
			/** t_vector3 p1 = project_point_to_2d(p1_f, perspective); */
			/** t_vector3 p2 = project_point_to_2d(p2_f, perspective); */
			/** t_vector3 p3 = project_point_to_2d(p3_f, perspective); */
			/** t_vector3 p4 = project_point_to_2d(p4_f, perspective); */
            /**  */
			t_vector3 p1 = project_point_to_2d(p1_r, perspective);
			t_vector3 p2 = project_point_to_2d(p2_r, perspective);
			t_vector3 p3 = project_point_to_2d(p3_r, perspective);
			t_vector3 p4 = project_point_to_2d(p4_r, perspective);

			/**  */
			/** printf("p1(%d, %d)\n", p1.x, p1.y); */
			/** printf("p2(%d, %d)\n", p2.x, p2.y); */
			/** printf("p3(%d, %d)\n", p3.x, p3.y); */
			/** FIXME : Bresenham 알고리즘이 수직선을 못그림. */
			/** draw_line_on_image(data, create_data_vec3(280, 250, RED), create_data_vec3(250, 280, RED)); */


			/* Scale into View  */
			float move_x = 20.0f;
			float move_y = 20.0f;
			p1.x += move_x; p1.y += move_y;
			p2.x += move_x; p2.y += move_y;
			p3.x += move_x; p3.y += move_y;
			p4.x += move_x; p4.y += move_y;
            /**  */
			p1.x *= 0.08f * (float)WIN_WIDTH;
			p1.y *= 0.08f * (float)WIN_HEIGHT;
			p2.x *= 0.08f * (float)WIN_WIDTH;
			p2.y *= 0.08f * (float)WIN_HEIGHT;
			p3.x *= 0.08f * (float)WIN_WIDTH;
			p3.y *= 0.08f * (float)WIN_HEIGHT;
			p4.x *= 0.08f * (float)WIN_WIDTH;
			p4.y *= 0.08f * (float)WIN_HEIGHT;
            /**  */
            /**  */
			/** trianle 1 */
			draw_line_on_image(data, p1, p2);
			draw_line_on_image(data, p2, p4);
			/** draw_line_on_image(data, p4, p1); */

			/** triangle 2 */
			/** draw_line_on_image(data, p1, p4); */
			draw_line_on_image(data, p4, p3);
			draw_line_on_image(data, p3, p1);

			i += 1;
		}
		j += 1;
	}
}
