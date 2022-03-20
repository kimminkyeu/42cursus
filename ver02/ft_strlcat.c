/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:26:11 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/11 15:09:00 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// src 에서 dst 로 복사를 시작하는데, 특징은 dest + src 길이를 고려해서 dest를 생각해야 한다.

#include <stddef.h>

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	while (dst[dst_len])
		++dst_len;
	// (1) 먼저 dest 길이를 잰다
	// (2) dst길이 + src길이 + 1 < n) 조건이 될 때까지 src 인덱스를 증가
	//		위 과정 이후 src의 길이도 재야 한다.
	src_len = 0;
	while ((dst_len + src_len + 1 < dstsize) && src[src_len])
	{
		dst[dst_len + src_len] = src[src_len];
		src_len++;
	}

	// (2) 제일 마지막에 null termination을 진행한다. 
	dst[dst_len + src_len] = '\0';

	// (3) 위 과정이 끝나면 src_len을 다 잰게 아닐 수 있으므로 마저 재줌
	// 이게 안전한 이유는, 위 조건중 src[src_len]이 만약 널을 만나면 끝나는 조건이라서그럼.
	while (src[src_len])
		++src_len;

	// (3) 반환. 만약 dst_len + src_len + 1 < n 일 경우, 복사가 안됬다는 말이므로
	//		src_len + n 을 반환하고, 만약 반대라면 dst_len + src_len 을 반환한다.
	// (4) 근데 이제 와서 헷갈리는 듯 했지만 내가 반대로 생각했네 ㅋ 해결함
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	else
		return (src_len + dst_len);
}
