/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:40:28 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/17 14:08:23 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_sqrt_1(int nb)
{
	long long	sqrt;

	sqrt = 0;
	if (nb <= 0)
		return (0);
	while (sqrt * sqrt != (long long)nb)
	{
		if (sqrt * sqrt > (long long)nb)
			return (sqrt - 1);
		++sqrt;
	}
	return ((int)sqrt);
}

int	my_is_prime(int nb)
{
	int	sqrt;
	int	i;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	i = 2;
	sqrt = my_sqrt_1(nb);
	while (i <= sqrt)
	{
		if (nb % i == 0)
			return (0);
		else
			++i;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb < 1)
		return (2);
	i = nb;
	while (!my_is_prime(i))
		++i;
	return (i);
}
