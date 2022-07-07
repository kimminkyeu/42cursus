/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:56:18 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/09 15:44:18 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_size(long long num)
{
	int	count;

	if (num == 0)
	{
		return (1);
	}
	count = 0;
	while (num != 0)
	{
		num = num / 10;
		++count;
	}
	return (count);
}

void	itoa(long long num, int size)
{
	long long	num_next;
	char		data[10];
	int			index;

	index = 0;
	num_next = num;
	while (index < size)
	{
		num = num_next % 10;
		data[index] = (char)num + '0';
		num_next = num_next / 10;
		++index;
	}
	index = 0;
	while (index < size)
	{
		write(1, &data[size - index - 1], sizeof (*data));
		++index;
	}
}

void	ft_putnbr(int nb);

void	ft_putnbr(int nb)
{
	long long	tmp;
	int			size;

	tmp = nb;
	size = get_size(tmp);
	if (nb < 0)
	{
		tmp = -tmp;
		write(1, "-", 1);
		itoa(tmp, size);
	}
	else
	{
		itoa(tmp, size);
	}
}
