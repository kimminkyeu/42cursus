/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:45:30 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/13 16:41:40 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// TODO: memmove 는 정말 따로 공부 꼭 해야 겠다. 


// TODO : 하다보니... ft_memcpy의 overlap undefined behavior 와 이 memmove의 차이가 뭐지?
// TODO : 차이는 MEMORY OVERLAPP이 일어날 때 생긴덴다. 이 부분 직접 눈으로 봐야한다. 
//
// TODO :memmove 구현관련 유투브 https://www.youtube.com/watch?v=nFl1cNXk85s

// A : memcpy의 경우에는 자기 자신의 내용을 복사하여 덮어쓸 때, 인접한 메모리에 의해 겹침현상(overlap)이 일어난다. memmove 의 경우, 임시 저장소에 저장한 후 복사한다.

// memmove 와 memcpy는 꼭 공부하고 하자. 

// TODO : 공부 한 후에 구현 진행. (버퍼에 먼저 복사) 이거 하고, 테스트 오류도 똑같이 나는지 한번 검사.

#include <stddef.h>

/** TODO : https://student.cs.uwaterloo.ca/~cs350/common/os161-src-html/doxygen/html/memmove_8c_source.html
 *
 *		상단 링크 여기서 공부하자.
 *
 * */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*dst_tmp;
	const unsigned char		*src_tmp;
	size_t					buffer[len];
	size_t					i;

	// --TODO: 왜 아래 조건이 필요한가?? ---
	if (!dst && !src)
		return (dst);
	// ---------------------------------
	dst_tmp = (unsigned char *)dst;
	src_tmp = (const unsigned char *)src;

	i = 0;
	while (i < len)
	{
		buffer[i] = src_tmp[i];
		++i;
	}
	i = 0;
	while (i < len)
	{
		dst_tmp[i] = buffer[i];
		++i;
	}
	return (dst);
}


/** Error logs 
 * (1) 이전 : buffer를 한 단어만 정했었음.
 * 바꾼 후 : 통째로 버퍼배열에 먼저 복사하고, 이걸 그대로 반영
 *
 * (2) NULL 입력에 대한 처리를 안함 + 128 이상의 데이터는 처리를 하지 못한다? -> ㄱ이거 때매 unsigned char 쓰는겨?
 *
 *
 * */

