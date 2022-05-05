/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:07:11 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/26 19:38:02 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector4.h"

t_vector4	create_data_vec4(int _x, int _y, int _z, int _w_or_color)
{
	t_vector4	pos4;

	pos4.x = _x;
	pos4.y = _y;
	pos4.z = _z;
	pos4.color = _w_or_color;
	return (pos4);
}

int	get_dot_product_vec4(t_vector4 dst, t_vector4 src)
{
	return (dst.x * src.x + dst.y * src.y + dst.z * src.z + dst.w * src.w);
}

int	get_magnitude_vec4(t_vector4 v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w)));
}
