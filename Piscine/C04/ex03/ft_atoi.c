/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:27:20 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/15 20:01:14 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		sign;
	int		sum;

	sign = 1;
	sum = 0;
	while (*str && ((*str == ' ') || (*str >= 9 && *str <= 13)))
		++str;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}	
	while (*str && *str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (int)(*str - '0');
		++str;
	}
	return (sum * sign);
}
