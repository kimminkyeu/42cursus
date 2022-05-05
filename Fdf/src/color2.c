/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:52:02 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/03 21:52:22 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/color.h"

/* TODO : 
 * ======================================
 * ints are stored from right to left!! |
 * ====================================== */
unsigned char	get_alpha_color(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_red_color(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_green_color(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_blue_color(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}
