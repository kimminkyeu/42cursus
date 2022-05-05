/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:50:02 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/07 12:57:50 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

void	print(int num)
{
	char	tmp;

	if (num < 10)
	{
		write(1, "0", 1);
		tmp = num + 48;
		write(1, &tmp, 1);
	}
	else
	{
		tmp = (num / 10) + 48;
		write(1, &tmp, 1);
		tmp = (num % 10) + 48;
		write(1, &tmp, 1);
	}
}

void	ft_print_comb2(void)
{
	int	max;
	int	i;
	int	j;

	i = 0;
	max = 99;
	while (i <= max)
	{
		j = 0;
		while (j <= max)
		{
			if (i < j)
			{
				print(i);
				write(1, " ", 1);
				print(j);
				if (i != 98)
				{
					write(1, ", ", 2);
				}
			}
			++j;
		}
		++i;
	}
}
