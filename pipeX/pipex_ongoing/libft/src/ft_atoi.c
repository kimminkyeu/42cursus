/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:22:31 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/22 15:34:33 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>  

extern bool	ft_isspace(char c);

int	ft_atoi(const char *str)
{
	unsigned int	sum;
	int				sign;

	sum = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		++str;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		sum *= 10;
		sum += (*str - '0');
		++str;
	}
	return ((int)(sum * sign));
}
