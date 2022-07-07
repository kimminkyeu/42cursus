/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:02:59 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/26 19:40:49 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *messege)
{
	printf("%s\n", messege);
	return (ERROR);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

bool	ft_is_positive_integer(char *s)
{
	size_t		sum;

	sum = 0;
	if (s[0] == '-')
		return (false);
	while (*s != '\0')
	{
		if (ft_isdigit(*s) == false)
			return (false);
		sum *= 10;
		sum += (*s - '0');
		s++;
	}
	if (sum > (size_t)INT_MAX)
		return (false);
	else
		return (true);
}

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
	size_t			sum;
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
	if (sign > 0 && sum > LONG_MAX + 0)
		return (-1);
	else if (sign < 0 && sum > (size_t)LONG_MAX + 1)
		return (0);
	return ((int)(sum * sign));
}
