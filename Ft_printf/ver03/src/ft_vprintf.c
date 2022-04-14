/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:50:40 by kyeu              #+#    #+#             */
/*   Updated: 2022/04/13 11:33:23 by kyeu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_putstr_until(const char *str, char stopper, t_print *INFO)
{
	size_t		len;
	const char	*str_cpy;

	len = 0;
	str_cpy = str;
	while (*str_cpy != stopper && *str_cpy != '\0')
	{
		len += 1;
		str_cpy += 1;
	}
	ft_nputstr_fd(str, STDOUT, len);
	INFO->print_cnt += len;
	return (len);
}

int	ft_vprintf(const char *fmt, va_list argp)
{
	int		print_cnt;
	t_print	*INFO; 

	INFO = init_info_malloc();
	while (*fmt != '\0')
	{
		fmt += ft_putstr_until(fmt, '%', INFO);
		if (*fmt == '%')
		{
			INFO->state = PRINTF_SPEC;
			fmt += 1;
			parse_format(&fmt, argp, INFO);
			reset_state(INFO);
		}
	}
	print_cnt = INFO->print_cnt;
	free(INFO);
	return (print_cnt);
}
