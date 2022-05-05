/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:54:43 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/26 23:56:00 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	render_next_frame(t_mlx *fdf);

int	main(int ac, char **av)
{
	t_mlx		fdf;

	/* (1) parse and store to D-array. Second paramter is init_size of D-array */
	fdf.map = mp_parse_file_malloc(mp_open_file(ac, av), 1024);

	/* (2) start mlx_engine */
	engine_init(&fdf, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);

	/* (3) loop callback function until hook */
	mlx_loop_hook(fdf.mlx, render_next_frame, &fdf);

	/* (4) set key macro to close window. you can change this in fdf.h header */
	engine_run_until(WIN_EXIT_KEY, &fdf);

	/* (5) delete (free) map data. */
	delete_darray(&fdf.map);

	return (0);
}

void	draw_triangle(t_image *data, t_darray *map);

int	render_next_frame(t_mlx *fdf)
{
	/* (0) set image (get memory) */
	t_image	data;

	data.img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	/* (1) first set BACKGROUND */
	draw_background_on_image(&data, WIN_WIDTH, WIN_HEIGHT, DEFAULT_BG_COLOR);


	/* (2) get projection result via projection function;
	 * Hint. Use darray_map() or darray_iterate(), pass projection pointer to them */

	draw_triangle(&data, fdf->map);


	/* (4) put image to window */
	mlx_put_image_to_window(fdf->mlx, fdf->win, data.img, 0, 0);
	/* (5) destroy image  --> NOTE : really necessary? --> 맞음. 이거 안하면 메모리 릭 뜸!  */
	mlx_destroy_image(fdf->mlx, data.img);

	return (0);
}

t_vector4	get_point_vec4(t_darray *map, int x, int y)
{
	int	col_num;
	int	index;

	col_num = ((t_vector4 *)(map->data[map->size - 1]))->x + 1;
	index = y * col_num + x;

	return (*((t_vector4 *)(map->data[index])));
}

t_vector4	multiply_matrix_vec4(t_vector4 v, t_mat4x4 m)
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

/* retuns t_vector3 (x, y, color) data 
 * TODO : make this projection */
t_vector3	project_point_to_2d(t_vector4 point)
{
	/* 화면 중앙에 잘 분배. --> 중앙 지점을 기준으로  */
	/** WIN_WIDTH / 2;
	  * WIN_HEIGHT / 2; 
	  *
	  * aspect Radio (화면 비) 에 따라 점을 퍼뜨려야 함.
	  *  ++ 포커스를 중앙으로 배치해야 함. 그 얘기는, 중앙점을 구해서 해당 포인트 크기만큼
	  *  빼줄 것. 
	  *
	  *  50 x 50 이면, 25를 기준으로 
	  *       o o o -->  o    o    o
	  * (0 , 0) --> ()
	  * (2 , 2) --> WIN_WIDTH와 WIN_HEIGHT을 넘지 못하게 그려야 한다. 
	  *
	  * */

	float fNear = 0.1f;
	float fFar = 1000.0f;
	float fFov = 90.0f;
	float fAspectRatio = (float)WIN_HEIGHT / (float)WIN_WIDTH;
	float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.f * 3.14159f);

	t_mat4x4	mat_proj;

	int i = 0;
	int j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			mat_proj.m[i][j] = 0;
		}
	}
	mat_proj.m[0][0] = fAspectRatio * fFovRad;
	mat_proj.m[1][1] = fFovRad;
	mat_proj.m[2][2] = fFar / (fFar - fNear);
	mat_proj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
	mat_proj.m[2][3] = 1.0f;
	mat_proj.m[3][3] = 0.0f;

	t_vector4 result = multiply_matrix_vec4(point, mat_proj);

	return (create_data_vec3(result.x, result.y, point.color));
}



// Project each point. -> result will be 2d result (vec3)
void	draw_triangle(t_image *data, t_darray *map)
{
	int			i;
	int			j;
	t_vector4	last_point;

	(void)data;
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

	/* draw triangle by   */
	j = 0;
	while (j < last_point.y)
	{
		i = 0;
		while (i < last_point.x)
		{
			t_vector3 p1 = project_point_to_2d(get_point_vec4(map, i, j));
			t_vector3 p2 = project_point_to_2d(get_point_vec4(map, i + 1, j));
			t_vector3 p3 = project_point_to_2d(get_point_vec4(map, i, j + 1));
			t_vector3 p4 = project_point_to_2d(get_point_vec4(map, i + 1, j + 1));

			/** printf("p1(%d, %d)\n", p1.x, p1.y); */
			/** printf("p2(%d, %d)\n", p2.x, p2.y); */
			/** printf("p3(%d, %d)\n", p3.x, p3.y); */
			/** FIXME : Bresenham 알고리즘이 수직선을 못그림. */
			/** draw_line_on_image(data, create_data_vec3(280, 250, RED), create_data_vec3(250, 280, RED)); */

			/** trianle 1 */
			draw_line_on_image(data, p1, p2);
			draw_line_on_image(data, p2, p4);
			draw_line_on_image(data, p4, p1);

			/** triangle 2 */
			draw_line_on_image(data, p1, p4);
			draw_line_on_image(data, p4, p3);
			draw_line_on_image(data, p3, p1);

			i += 1;
		}
		j += 1;
	}
}
