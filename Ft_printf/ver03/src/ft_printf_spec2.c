/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:40:13 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/12 22:40:33 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	handle_spec_uint(va_list argp, t_print *INFO)
{
	/* TODO : Exeption handling  */
	int num = va_arg(argp, int);
	ft_putnbr_uint_fd((unsigned int)num, STDOUT);
	INFO->print_cnt += ft_nbrlen_uint(num);
	INFO->state = PRINTF_DONE;
}

void	handle_spec_lower_hex(va_list argp, t_print *INFO)
{
	/* TODO : Exeption handling  */
	unsigned int num = va_arg(argp, unsigned int);
	INFO->print_cnt += (print_to_hex_fit((size_t)num, 0));
	INFO->state = PRINTF_DONE;
}

void	handle_spec_upper_hex(va_list argp, t_print *INFO)
{
	/* TODO : Exeption handling  */
	unsigned int num = va_arg(argp, unsigned int);
	INFO->print_cnt += (print_to_hex_fit((size_t)num, 1));
	INFO->state = PRINTF_DONE;
}

int get_spec_func_idx(const char *fmt)
{
	int			idx;
	const char	*specifier;

	specifier = "c%spdiuxX";
	idx = 0;
	while (specifier[idx] != '\0')
	{
		if (specifier[idx] == *fmt)
		{
			return idx;
		}
		idx += 1;
	}
	return (-1);
}

void set_spec_func_table(void (*spec_func_table[])(va_list, t_print *))
{
	spec_func_table[0] = handle_spec_char;
	spec_func_table[1] = handle_spec_percent;
	spec_func_table[2] = handle_spec_str;
	spec_func_table[3] = handle_spec_addr;
	spec_func_table[4] = handle_spec_int;
	spec_func_table[5] = handle_spec_int;
	spec_func_table[6] = handle_spec_uint;
	spec_func_table[7] = handle_spec_lower_hex;
	spec_func_table[8] = handle_spec_upper_hex;
}
