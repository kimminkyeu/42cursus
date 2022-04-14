/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:58:36 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/12 21:04:00 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	print_string_until(const char *str, char stopper, t_print *INFO)
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

static int	ft_vprintf(const char *fmt, va_list argp)
{
	int		print_cnt;
	t_print	*INFO; 

	INFO = init_info_malloc();
	while (*fmt != '\0')
	{
		fmt += print_string_until(fmt, '%', INFO);
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

int	ft_printf(const char *fmt, ...)
{
	va_list	argp;
	int		done;

	va_start(argp, fmt);
	done = ft_vprintf(fmt, argp);
	va_end(argp);
	return (done);
}
