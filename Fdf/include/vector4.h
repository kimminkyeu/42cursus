/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:48:41 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 09:38:51 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR4_H
# define VECTOR4_H

# include <math.h>

typedef union s_vector4 {
	struct {
		int	x;
		int	y;
		int	z;
		int	w;
	};
	float	data[4];
}	t_vector4;

/* NOTE : create R-value position and return! */
extern t_vector4	create_vector4(int _x, int _y, int _z, int _w);

extern float		get_dot_product_vec4(t_vector4 dst, t_vector4 src);

extern float		get_magnitude_vec4(t_vector4 v);

#endif /* VECTOR4_H */
