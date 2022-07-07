/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:55:24 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/17 13:58:34 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	sqrt;

	sqrt = 1;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (sqrt * sqrt != (long long)nb)
	{
		if (sqrt * sqrt > (long long)nb)
			return (0);
		++sqrt;
	}
	return ((int)sqrt);
}
