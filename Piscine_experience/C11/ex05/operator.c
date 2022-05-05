/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:44:42 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/24 19:51:49 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	operator_add(int a, int b)
{
	ft_putnbr(a + b);
}

void	operator_sub(int a, int b)
{
	ft_putnbr(a - b);
}

void	operator_mul(int a, int b)
{
	ft_putnbr(a * b);
}

void	operator_div(int a, int b)
{
	if (b == 0)
		write(1, "Stop : division by zero\n", 24);
	else
		ft_putnbr(a / b);
}

void	operator_mod(int a, int b)
{
	if (b == 0)
		write(1, "Stop : modulo by zero\n", 22);
	else
		ft_putnbr(a % b);
}
