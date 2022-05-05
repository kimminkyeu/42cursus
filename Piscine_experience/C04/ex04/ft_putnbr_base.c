/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:27:46 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/15 16:28:19 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	get_base_size(char *base)
{
	int	size;

	size = 0;
	while (*base++)
		size++;
	return (size);
}

int	has_same(char *base)
{
	char	*pivot;
	char	*compare;

	while (*(base + 1))
	{
		pivot = base;
		compare = pivot + 1;
		while (*compare)
		{
			if (*pivot == *compare)
				return (0);
			++compare;
		}
		++base;
	}
	return (1);
}

int	is_valid(char *base)
{
	char	*p_base;

	p_base = base;
	if (*base == '\0')
		return (0);
	while (*p_base != '\0')
	{
		if (*p_base == '+' || *p_base == '-')
			return (0);
		++p_base;
	}
	if (!has_same(base))
		return (0);
	return (1);
}

void	put_nbr_recur(int nb, char *base, unsigned int base_len)
{
	if (nb == 0)
		return ;
	put_nbr_recur(nb / base_len, base, base_len);
	write(1, &base[nb % base_len], 1);
}

void	ft_putnbr_base(int nb, char *base)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = get_base_size(base);
	if (size < 2 || !is_valid(base))
		return ;
	else if (nb < 0)
	{
		write(1, "-", 1);
		put_nbr_recur((unsigned int)(-nb), base, size);
	}
	else if (nb == 0)
		write(1, &base[0], 1);
	else
		put_nbr_recur(nb, base, size);
}
