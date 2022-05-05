/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:07:11 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/26 19:10:02 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector3.h"

t_vector3	create_data_vec3(int _x, int _y, int _w_or_color)
{
	t_vector3	data;

	data.x = _x;
	data.y = _y;
	data.color = _w_or_color;
	return (data);
}

int	get_dot_product_vec3(t_vector3 dst, t_vector3 src)
{
	return (dst.x * src.x + dst.y * src.y + dst.w * src.w);
}

int	get_magnitude_vec3(t_vector3 v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.w * v.w)));
}
