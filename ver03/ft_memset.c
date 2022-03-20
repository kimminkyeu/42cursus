/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:31:14 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/11 14:47:34 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** memset function writes len bytes of value c (converted to an unsigned char) 
 * to the string b. 
 * return value is its first argument pointer*/

// TODO: 얘도 어차피 unsigned char로 캐스팅해서 대입할 꺼면, 뭐하러 int로 받는겨?
// TODO : 답 : https://stackoverflow.com/questions/5919735/why-does-memset-take-an-int-instead-of-a-char
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_char;

	b_char = (unsigned char *)b;
	while (len > 0)
	{
		*b_char = (unsigned char)c;
		++b_char;
		--len;
	}
	return (b);
}
