/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:32:23 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/11 14:30:53 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO : strcmp와 거의 똑같은데.... 뭐가 다른 걸까...?
// A : 차이는 null 문자 인식에 대해서임. 
/** returns the difference between the first two differing bytes 
 *
 * TODO: 왜 unsigned char로 비교하라고 man에 적혀있는 거야?? 
 */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s1_uchar;
	const unsigned char *s2_uchar;

	s1_uchar = (const unsigned char *)s1;
	s2_uchar = (const unsigned char *)s2;
	while ((n > 0) && (*s1_uchar == *s2_uchar))
	{
		++s1_uchar;
		++s2_uchar;
		--n;
	}
	if (n == 0)
		return (0);
	else
		return ((int)*s1_uchar - (int)*s2_uchar);
}

/** Error log:
  * TODO : error code 가 발생한 이유!
  * 데이터가 n까지 비교해서 같을 때 반환이 0이 나와야함. */

