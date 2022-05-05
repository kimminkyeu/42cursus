/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:03:43 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/03 21:52:27 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/color.h"

int	create_trgb_color(int alpha, int r, int g, int b)
{
	unsigned char	color[4];

	color[0] = b;
	color[1] = g;
	color[2] = r;
	color[3] = alpha;
	return (*(int *)(color));
}

/* get_shaded_color is a function that accepts a double (distance) 
 * and a int (color) as arguments, 0 will add no shading to the color, 
 * whilst 1 will make the color completely dark. 
 * 0.5 will dim it halfway, and .25 a quarter way.  */
/* ------------------------------
 * * Shading : RGB decreases, black if 0.
 * Gets Darker if shade_factor increases. */
int	get_shaded_color(double shade_factor, int color)
{
	unsigned char	shaded_red;
	unsigned char	shaded_green;
	unsigned char	shaded_blue;
	unsigned char	alpha;

	if (shade_factor <= 0)
		return (color);
	shaded_red = get_red_color(color) * (1 - shade_factor);
	shaded_green = get_green_color(color) * (1 - shade_factor);
	shaded_blue = get_blue_color(color) * (1 - shade_factor);
	alpha = get_alpha_color(color);
	return (create_trgb_color(alpha, shaded_red, shaded_green, shaded_blue));
}

/* NOTE : Inverts alpha and color, and return */
int	get_opposite_color(int trgb)
{
	unsigned char	oppo[4];

	oppo[3] = 0xFF - get_alpha_color(trgb);
	oppo[2] = 0xFF - get_red_color(trgb);
	oppo[1] = 0xFF - get_green_color(trgb);
	oppo[0] = 0xFF - get_blue_color(trgb);
	return (*(int *)oppo);
}
