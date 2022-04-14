/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:50:39 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/12 21:29:06 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	handler(const char *fmt)
{
	size_t	idx;
	const char	*specifier;

	specifier = "c%spdiuxX";
	idx = 0;
	while (specifier[idx] == '\0')
	{
		if (specifier[idx] == *fmt)
		{
			return idx;
		}
		idx += 1;
	}
	return 0; // TODO : change this !!
}

void	func(void)
{
	return ;
}

void set()
{
	void (*spec_func_table[9])(void);
	spec_func_table[0] = func;
	spec_func_table[1] = func; 
	spec_func_table[2] = func; 
	spec_func_table[3] = func; 
	spec_func_table[4] = func; 
	spec_func_table[5] = func; 
	spec_func_table[6] = func; 
	spec_func_table[7] = func; 
	spec_func_table[8] = func; 
}

void	parse_format(const char **fmt, va_list argp, t_print *INFO)
{
	/* NOTE : state이 PRINTF_DONE이 될 때까지 무한루프.  */

	while (INFO->state != PRINTF_DONE)
	{

		if (INFO->state == PRINTF_FLAG) 
		{
			//...
		}
		else if (INFO->state == PRINTF_WIDTH)
		{

			/* NOTE : handle width, store width data in INFO set state to PRECISION or LENGTH*/
			//...
		}
		else if (INFO->state == PRINTF_PRECISION)
		{
			/* NOTE : handle precision, store precision data in INFO set state to LEGNTH*/
			//...
		}
		else if (INFO->state == PRINTF_LENGTH)
		{
			/* NOTE : hande LENGTH, set state to LENGTH_SHORT or LENGTH_LONG or SPEC */
			//...
		}
		else if (INFO->state == PRINTF_SPEC)
		{

			while (INFO->state != PRINTF_DONE)
			{

				if (**fmt == 'c')	// --> %c
				{
					/* TODO : Exeption handling  */
					char c = va_arg(argp, int);
					ft_putchar_fd(c, STDOUT);
					INFO->print_cnt += 1; 
					INFO->state = PRINTF_DONE;
				}
				else if (**fmt == '%')	// --> %%
				{
					/* TODO : Exeption handling  */
					ft_putchar_fd('%', STDOUT);
					INFO->print_cnt += 1; 
					INFO->state = PRINTF_DONE;
				}
				else if (**fmt == 's') // --> %s
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
				else if (**fmt == 'p') // --> %p
				{
					/* TODO : Exeption handling  */
					void *addr_decimal = va_arg(argp, void *);
					ft_putstr_fd("0x", STDOUT);
					INFO->print_cnt += (print_to_hex_fit((size_t)addr_decimal, 0) + 2);
					INFO->state = PRINTF_DONE;
				}
				else if (**fmt == 'd' || **fmt == 'i') // --> %d
				{
					/* TODO : Exeption handling  */
					int num = va_arg(argp, int);
					ft_putnbr_fd(num, STDOUT);
					INFO->print_cnt += ft_nbrlen(num);
					INFO->state = PRINTF_DONE;
				}
				else if (**fmt == 'u') // --> %u
				{
					/* TODO : Exeption handling  */
					int num = va_arg(argp, int);
					ft_putnbr_uint_fd((unsigned int)num, STDOUT);
					INFO->print_cnt += ft_nbrlen_uint(num);
					INFO->state = PRINTF_DONE;

				}
				else if (**fmt == 'x') // --> %x
				{
					/* TODO : Exeption handling  */
					unsigned int num = va_arg(argp, unsigned int);
					INFO->print_cnt += (print_to_hex_fit((size_t)num, 0));
					INFO->state = PRINTF_DONE;
				}
				else if (**fmt == 'X') // --> %X
				{
					/* TODO : Exeption handling  */
					unsigned int num = va_arg(argp, unsigned int);
					INFO->print_cnt += (print_to_hex_fit((size_t)num, 1));
					INFO->state = PRINTF_DONE;
				}
				(*fmt) += 1;
			}
			/* NOTE : handle SPECIFIER, set state to DONE and print argument via INFO_data */
			//...
		}
		else if (INFO->state == PRINTF_ERROR)
		{
			return ;
			/* NOTE : if state machine error, then set state to ERROR, return  */
			//...
		}

	}
	/* NOTE : if nothing happens (state machine), return. */
}


t_print*	init_info_malloc()
{
	t_print	*pa_info;

	/* TODO : add additionals  */
	pa_info = malloc(sizeof(*pa_info));
	pa_info->state = PRINTF_NORMAL;
	pa_info->print_cnt = 0;
	return (pa_info);
}

void	reset_state(t_print *INFO) // reset if one %.. is done
{
	INFO->state = PRINTF_NORMAL;
}

