/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:31:27 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/07 17:54:43 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

int	write_digits(char first_digit, char second_digit, char third_digit)
{
	char	buf[3];

	buf[0] = first_digit;
	buf[1] = second_digit;
	buf[2] = third_digit;
	if (buf[0] == '7' && buf[1] == '9' && buf[2] == '0')
		return (-1);
	if (buf[0] < buf[1] && buf[1] < buf[2])
	{
		write(1, buf, 3);
		if (!(buf[0] == '7' && buf[1] == '8' && buf[2] == '9'))
		{
			write(1, ", ", 2);
		}
	}
	return (0);
}

void	ft_print_comb(void)
{
	char	digit_1;
	char	digit_2;
	char	digit_3;

	digit_1 = 48;
	digit_2 = 49;
	digit_3 = 50;
	while (write_digits(digit_1, digit_2, digit_3) != -1)
	{
		++digit_3;
		if (digit_3 > 57)
		{
			digit_3 = 48;
			++digit_2;
		}
		else if (digit_2 > 57)
		{
			digit_2 = 48;
			++digit_1;
		}
	}
}
