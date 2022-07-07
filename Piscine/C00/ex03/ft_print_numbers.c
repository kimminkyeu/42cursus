/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:05:43 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/07 11:07:25 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	char	buf;
	char	cnt;

	cnt = 0;
	buf = 48;
	while (cnt < 10)
	{
		write(1, &buf, 1);
		++cnt;
		++buf;
	}
}
