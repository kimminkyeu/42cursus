/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:47:48 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/24 19:56:38 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	do_operator(int a, int b, char *operator)
{
	void	(*f[5])(int, int);

	f[0] = operator_add;
	f[1] = operator_sub;
	f[2] = operator_mul;
	f[3] = operator_div;
	f[4] = operator_mod;
	if (*operator == '+')
		(f[0])(a, b);
	if (*operator == '-')
		(f[1])(a, b);
	if (*operator == '*')
		(f[2])(a, b);
	if (*operator == '/')
		(f[3])(a, b);
	if (*operator == '%')
		(f[4])(a, b);
}
