/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ /*   Created: 2022/04/28 11:12:17 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/28 14:34:57 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/circle.h"
#include "../include/vector3.h"
#include "../include/engine.h"

t_circle	*init_circle(int _x, int _y, int _color, float _size)
{
	t_circle	*circle;

	circle = ft_calloc(1, sizeof(*circle));
	if (circle != NULL)
	{
		circle->x = _x;
		circle->y = _y;
		circle->color = _color;
		circle->size = _size;
	}
	return (circle);
}

#include <stdio.h>



/** FIXME : 아래의 에러가 발생. 매우 불안정함.
 * * thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=1, address=0x0) */
/**     frame #0: 0x0000000100006210 fdf`draw_circle(data=0x0000000100308720, obj=0x0000000000000000) at circle.c:116:50 */
/**    113 	void	draw_circle(t_mlx *data, void *obj) */
/**    114 	{ */
/**    115 		t_circle	*circle = (t_circle *)obj; */
/** -> 116 		bresenham_circle(data, create_data_vec3(circle->x, circle->y, circle->color), circle->size); */
/**    117 		printf("circle color=%d pos=[%d,%d] size=%f \n", circle->color, circle->x, circle->y, circle->size); */
/**    118 	} */
/** Target 0: (fdf) stopped. */

void bresenham_cliplot(t_mlx *data, t_vector3 ctr, t_vector3 p)
{
	draw_pixel_on_image(data, create_data_vec3(ctr.x + p.x, ctr.y + p.y, ctr.color));
	draw_pixel_on_image(data, create_data_vec3(ctr.x - p.x, ctr.y + p.y, ctr.color));
	draw_pixel_on_image(data, create_data_vec3(ctr.x + p.x, ctr.y - p.y, ctr.color));
	draw_pixel_on_image(data, create_data_vec3(ctr.x - p.x, ctr.y - p.y, ctr.color));
	draw_pixel_on_image(data, create_data_vec3(ctr.x + p.y, ctr.y + p.x, ctr.color));
	draw_pixel_on_image(data, create_data_vec3(ctr.x - p.y, ctr.y + p.x, ctr.color));
	draw_pixel_on_image(data, create_data_vec3(ctr.x + p.y, ctr.y - p.x, ctr.color));
	draw_pixel_on_image(data, create_data_vec3(ctr.x - p.y, ctr.y - p.x, ctr.color));
}

/* NOTE : https://www.geeksforgeeks.org/bresenhams-circle-drawing-algorithm/ */
void bresenham_circle(t_mlx *data, t_vector3 p1, float radius)
{
	t_vector3	p2;
	int		p;

	p = 1 - radius;

	p2.x = 0;
	p2.y = radius;
	bresenham_cliplot(data, p1, p2);
	while (p2.x < p2.y) {
		p2.x++;
		if (p < 0)
			p += 2 * p2.x + 1;
		else {
			p2.y--;
			p += 2 * (p2.x - p2.y) + 1;
		}
		bresenham_cliplot(data, p1, p2);
	}
}

/* void	draw_filled_Circle_on_image(t_image *img, t_pos3d _pos, float radius, int color)
 * {
 *
 * } */

/* ----------------------------------------------
 * * */
/* NOTE : 점 개수에 관계없이 반지름이 길면 드문드문 나옴 */
void	draw_wired_circle_on_image(t_mlx *data, t_vector3 _pos, float radius)
{
	float	degree;
	float	radian;
	float	x;
	float	y;

	degree = 0;
	while (degree < 360)
	{
		radian = get_radian(degree);
		x = _pos.x + radius * cosf(radian);
		y = _pos.y + radius * sinf(radian);
		draw_pixel_on_image(data, create_data_vec3(x, y, _pos.color));
		degree += 1;
	}
}

/* NOTE: 점 개수에 따라 출력되게 하는 것. 그러나 점 개수가 작으면 드문드문 나옴 */
void	draw_wired_circle_on_image2(t_mlx *data, t_vector3 _pos, float radius)
{
	int	nPoints = 40;
	int	i = 0;

	while (i < nPoints)
	{
		float x = _pos.x + radius * cosf(i / (float)(nPoints - 1) * 2.0f * 3.14159f);
		float y = _pos.y + radius * sinf(i / (float)(nPoints - 1) * 2.0f * 3.14159f);
		draw_pixel_on_image(data, create_data_vec3(x, y, _pos.color));
		i += 1;
	}
}

#include <stdio.h>

void	draw_circle(t_mlx *fdf, void *circle)
{
	t_circle *c = (t_circle *)circle;
	printf("color=%d pos=[%d,%d] size=%f \n", c->color, c->x, c->y, c->size);
	bresenham_circle(fdf, create_data_vec3(c->x, c->y, c->color), c->size);
}

/* Iterate drawing */
/* TODO : change object to circles  */
void	draw_circle_objects(t_mlx *fdf)
{
	size_t		i;
	t_circle	*c;

	i = 0;
	printf("size :%zd\n", fdf->object->size);
	while (i < fdf->object->size)
	{
		printf("check\n");
		c = (t_circle *)(fdf->object->data[i]);
		draw_circle(fdf, c);
		i++;
	}
}

