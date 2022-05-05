/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:26:48 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/23 20:22:18 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

unsigned int	itoa(char *data, unsigned int tmp)
{
	int	i;

	i = 0;
	while (tmp > 0)
	{
		data[i++] = (char)(tmp % 10) + '0';
		tmp /= 10;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	char			data[10];
	unsigned int	size;

	if (nb < 0)
	{
		size = itoa(data, (unsigned int)(-nb));
		write(1, "-", 1);
		while (size > 0)
			write(1, &data[(size--) - 1], 1);
	}
	else if (nb == 0)
		write(1, "0", 1);
	else
	{
		size = itoa(data, nb);
		while (size > 0)
			write(1, &data[(size--) - 1], 1);
	}
	write(1, "\n", 1);
}
