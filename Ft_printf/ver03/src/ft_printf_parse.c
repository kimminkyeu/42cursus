/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:50:39 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/12 22:46:52 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	parse_format(const char **fmt, va_list argp, t_print *INFO)
{
	/* NOTE : state이 PRINTF_DONE이 될 때까지 무한루프.  */
	// -------------------------------------------------------------
	static void (*spec_func_table[9])(va_list argp, t_print *INFO);
	if (spec_func_table[8] == NULL)
		set_spec_func_table(spec_func_table);
	// -------------------------------------------------------------
	
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
				(spec_func_table[get_spec_func_idx(*fmt)])(argp, INFO);
				(*fmt) += 1;
			}
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
