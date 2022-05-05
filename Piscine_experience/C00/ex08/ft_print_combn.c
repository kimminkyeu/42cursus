/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:06:44 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/07 13:53:19 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_input[10];
char	g_tmp[10];

void	print_recur(int start, int end, int index, int comb_size)
{
	if (index == comb_size)
	{
		write(1, g_tmp, comb_size);
		if (g_tmp[0] != g_input[end - comb_size + 1])
		{
			write(1, ", ", 2);
		}
	}
	while ((start <= end) && (index < comb_size))
	{
		g_tmp[index] = g_input[start];
		print_recur(start + 1, end, index + 1, comb_size);
		++start;
	}
}

void	ft_print_combn(int n);

void	ft_print_combn(int n)
{
	int		cnt;

	cnt = 0;
	while (cnt < 10)
	{
		g_input[cnt] = (char)cnt + '0';
		++cnt;
	}
	print_recur(0, 9, 0, n);
}
