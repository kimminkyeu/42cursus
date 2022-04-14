/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:58:36 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/13 10:54:32 by kyeu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	argp;
	int		done;

	va_start(argp, fmt);
	done = ft_vprintf(fmt, argp);
	va_end(argp);
	return (done);
}
