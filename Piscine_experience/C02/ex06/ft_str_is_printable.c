/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:28:23 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/12 19:59:43 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int				is_printable;
	unsigned char	*tmp;

	is_printable = 1;
	tmp = (unsigned char *)str;
	while (*tmp != '\0')
	{
		if (*tmp < 32 || *tmp >= 127)
		{
			is_printable = 0;
			return (is_printable);
		}
		++tmp;
	}
	return (is_printable);
}
