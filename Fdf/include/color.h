/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:54:46 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 09:26:26 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

/* -----------------------------
 * * Create and return 4byte data of single A(t)RGB color.
 * t : alpha(transparency).
 * r : red.
 * g : green.
 * b : blue. */
extern int				create_trgb_color(int alpha, int r, int g, int b);

extern unsigned char	get_alpha_color(int trgb);

extern unsigned char	get_red_color(int trgb);

extern unsigned char	get_green_color(int trgb);

extern unsigned char	get_blue_color(int trgb);

/* ------------------------------
 * * Shading : RGB decreases, black if 0.
 * Gets Darker if shade_factor increases. */
extern int				get_shaded_color(double shade_factor, int color);

/* NOTE : Inverts alpha and color, and return */
extern int				get_opposite_color(int trgb);

#endif /* COLOR_H */
