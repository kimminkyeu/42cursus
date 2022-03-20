/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:49:37 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/11 15:19:40 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_size;

	src_size = 0;
	while (src[src_size])
		++src_size;
	if (dstsize == 0)
		return (src_size);
	i = 0;
	while (src[i] && (i + 1 < dstsize))
	{
		dst[i] = src[i];
		++i;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (src_size);
}

/** 
  * unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size)
  * {
  *     unsigned int	len;
  *     char			*ptr;
  *
  *     len = 0;
  *     ptr = src;
  *     while (*ptr != '\0')
  *     {
  *         ++len;
  *         ++ptr;
  *     }
  *     if (size == 0)
  *         return (len);
  *     while (size - 1 > 0 && *src != '\0')
  *     {
  *         *dst = *src;
  *         ++dst;
  *         ++src;
  *         --size;
  *     }
  *     if (size != 0)
  *     {
  *         *dst = '\0';
  *     }
  *     return (len);
  * } */
