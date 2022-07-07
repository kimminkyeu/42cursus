/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:14:54 by djeong            #+#    #+#             */
/*   Updated: 2022/02/20 19:08:21 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

void	tr_itoa(char *str, int num, int idx)
{
	str[idx--] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return ;
	}
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		str[idx--] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	n;
	int		i;

	n = nb;
	i = ft_len(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	tr_itoa(str, nb, i);
	return (str);
}

void	ft_write_number_power(int size, char *buffer)
{
	char	*power_size_char;
	int		i;

	if (size < 3)
		return ;
	power_size_char = (char *)malloc(size + 2);
	i = 0;
	power_size_char[i++] = '1';
	while (i < size + 1)
		power_size_char[i++] = '0';
	power_size_char[i] = '\0';
	write(1, " ", 1);
	ft_write_nbr_into_ltrs(ft_strstr(buffer, power_size_char), buffer);
	free(power_size_char);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			break ;
	}
	return (*s1 - *s2);
}
