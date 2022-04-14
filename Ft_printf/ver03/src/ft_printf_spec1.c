/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:39:06 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/12 22:39:23 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	handle_spec_char(va_list argp, t_print *INFO)
{
	char c = va_arg(argp, int);
	ft_putchar_fd(c, STDOUT);
	INFO->print_cnt += 1; 
	INFO->state = PRINTF_DONE;
}

void	handle_spec_percent(va_list argp, t_print *INFO)
{
	/* TODO : Exeption handling  */
	(void)argp;
	ft_putchar_fd('%', STDOUT);
	INFO->print_cnt += 1; 
	INFO->state = PRINTF_DONE;

}

void	handle_spec_str(va_list argp, t_print *INFO)
{
	/* TODO : Exeption handling  */
	char *s = va_arg(argp, char *);
	if (s == NULL)
	{
		ft_putstr_fd("(null)", STDOUT);
		INFO->print_cnt += 6;
	}
	else
	{
		ft_putstr_fd(s, STDOUT);
		INFO->print_cnt += ft_strlen(s);
	}
	INFO->state = PRINTF_DONE;
}

void	handle_spec_addr(va_list argp, t_print *INFO)
{
	/* TODO : Exeption handling  */
	void *addr_decimal = va_arg(argp, void *);
	ft_putstr_fd("0x", STDOUT);
	INFO->print_cnt += (print_to_hex_fit((size_t)addr_decimal, 0) + 2);
	INFO->state = PRINTF_DONE;

}

void	handle_spec_int(va_list argp, t_print *INFO)
{
	/* TODO : Exeption handling  */
	int num = va_arg(argp, int);
	ft_putnbr_fd(num, STDOUT);
	INFO->print_cnt += ft_nbrlen(num);
	INFO->state = PRINTF_DONE;
}
