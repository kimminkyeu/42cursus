/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:18:58 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/13 16:41:19 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 /** The memchr() function locates the first occurrence of c (converted to an
   *     unsigned char) in string s. */

// TODO: 왜 int로 받고, unsigned char로 캐스팅해서 대입할까??

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s_uchar;

	s_uchar = (unsigned char *)s;
	while (n > 0)
	{
		if (*s_uchar == (unsigned char)c)
			return ((void *)s_uchar);
		--n;
		++s_uchar;
	}
	return (0);
}

/** Error log
 * : memchr는 문자열 비교가 아니다. 값 0을 널문자로 보지 않는다.*/
