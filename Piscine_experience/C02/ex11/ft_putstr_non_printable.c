/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:41:58 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/10 20:15:25 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char			tmp1;
	char			tmp2;
	char			*hex;
	unsigned char	*ptr;

	hex = "0123456789abcdef";
	ptr = (unsigned char *)str;
	while (*ptr != '\0')
	{
		if (*ptr >= 32 && *ptr <= 126)
		{
			write(1, ptr, 1);
		}
		else if (*ptr <= 255)
		{
			tmp1 = hex[*ptr / 16];
			tmp2 = hex[*ptr % 16];
			write(1, "\\", 1);
			write(1, &tmp1, 1);
			write(1, &tmp2, 1);
		}
		++ptr;
	}
}
