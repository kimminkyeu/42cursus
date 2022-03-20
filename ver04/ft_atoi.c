/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:22:31 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/11 13:40:07 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>  

static bool	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' \
			|| c == '\f' || c == '\r' || c == ' ')
		return (true);
	else
		return (false);
}

int	ft_atoi(const char *str)
{
	long long sum;
	long long sign;

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

/** Error log
 *
 *		-> "초반에 들어간 모든 공백문자를 무시해야 하는데, 이 부분을 구현하지 않음:"
 *
 *
 * */
