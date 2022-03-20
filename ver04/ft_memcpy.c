/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:39:40 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/11 17:37:51 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

// TODO : Q : unsinged char 를 써야 하는가, 아님 char를 써야 하는가?
//		--> 내 생각엔 "상관 없다" --> 단 반드시!! 반드시 체크하자!
//
// TODO : CHAR* 를 쓰기에 1BYTE씩 i가 증가하게 된다. 
// TODO : N이 개수가 아니라 SIZE다. 복사할 바이트 사이즈.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*u_dst;
	const char		*u_src;
	size_t			i;

	u_dst = (char *)dst;
	u_src = (const char *)src;
	// ------------------------------------------------
	// TODO: 난 요 아래 조건이 이해가 안감. 왜 둘다 null일때만이지? (src만 해도 안되고, dst만 해도 안되더라...)
	if (!dst && !src)
		return (dst);
	// -------------------------------------------------
	i = 0;
	while (i < n)
	{
		u_dst[i] = u_src[i];	
		++i;
	}
	return (dst);
}
