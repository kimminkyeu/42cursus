/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:01:24 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/14 11:34:31 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	char			*ptr;

	len = 0;
	ptr = src;
	while (*ptr != '\0')
	{
		++len;
		++ptr;
	}
	if (size == 0)
		return (len);
	while (size - 1 > 0 && *src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
		--size;
	}
	if (size != 0)
	{
		*dest = '\0';
	}
	return (len);
}
