/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:45:30 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/16 12:07:27 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"
// TODO : 왜 UNSIGNED CHAR로 해야 할까? 비트 확장성이 보장이 정말일까?
// TODO : 일단 ft_memcpy는 char로 복사함.

// 아래 조건 참고한 사이트
// https://stackoverflow.com/questions/13095488/how-to-implement-overlap-checking-memcpy-in-c
// 출처 : http://git.musl-libc.org/cgit/musl/tree/src/string/memmove.c
/** (2) malloc 안쓰고 overlapp의 경우에 한한 구현 방식 */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t		idx;

	d = dst;
	s = src;

	if (d == s)
		return (dst);
	idx = 0;
	if (d > s)
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

/** (1) malloc을 이용한 구현 방식
 *
  * void	*ft_memmove(void *dst, const void *src, size_t len)
  * {
  *     unsigned char	*tmp;
  *
  *     if (!dst && !src)
  *         return (dst);
  *     tmp = malloc(sizeof(*tmp) * len);
  *     if (!tmp)
  *         return (NULL);
  *     ft_memcpy(tmp, src, len);
  *     ft_memcpy(dst, tmp, len);
  *     free(tmp);
  *     tmp = NULL;
  *     return (dst);
  * } */


/** Error logs 
 * (1) 이전 : buffer를 한 단어만 정했었음.
 * 바꾼 후 : 통째로 버퍼배열에 먼저 복사하고, 이걸 그대로 반영
 *
 * (2) NULL 입력에 대한 처리를 안함 + 128 이상의 데이터는 처리를 하지 못한다? -> ㄱ이거 때매 unsigned char 쓰는겨?
 *
 *
 * */

