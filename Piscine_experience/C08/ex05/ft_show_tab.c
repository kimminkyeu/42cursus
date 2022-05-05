/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:35:48 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/22 09:14:36 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	itoa_print_recur(int num)
{
	char	tmp;

	if (num == 0)
		return ;
	itoa_print_recur(num / 10);
	tmp = (char)(num % 10) + '0';
	write(1, &tmp, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		++str;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		if (par[i].size == 0)
			write(1, "0", 1);
		else
			itoa_print_recur(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		++i;
	}
}
