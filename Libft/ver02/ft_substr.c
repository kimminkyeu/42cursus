/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:00:25 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/13 16:45:05 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// TODO: assert의 장점은 dedug모드에서만 작동하고 release모드시 포함이 안된다는 점 + 에러 위치까지 잘 표시된다는점.
// Q : malloc 실패는 release모드에서도 발생할 수 있는 거 아닌가...? 그럼 assert쓰면 안되지 않나?
// A : 그렇다. 이런 경우는 assert가 아닌 exit()을 쓰는게 좋다.
// https://stackoverflow.com/questions/34486414/handling-error-checking-with-assert

// TODO: 충격적인건, 어떤 시스템(ex Mac) 의 경우 malloc 함수 내부에서 null 반환시 errno를 지가 설정해 준데...
// 그럼 나는 따로 할 필요가 없는 거 아니냐? 
// https://www.reddit.com/r/C_Programming/comments/pgeivx/do_malloccallocrealloc_set_errno/

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	// allocate and return a substring from the string "s"
	
	// TODO: 예외처리
	// (1) if len is 0, if start is negetive, if start is out of index...	
	// (2) if *s 가 start ~ len보다 짧을 경우.
	
	// s[start] ~ s[start + len - 1]
	size_t	total_len;
	char	*pa_str;

	total_len = 0;
	while (s[start + total_len] && total_len <= len) // 우선 길이부터 재자. 
		++total_len;
	pa_str = malloc(sizeof(*pa_str) * (total_len + 1)); // null 포함 1개 더
	if (!pa_str)
		return (NULL);
	while (total_len-- > 0)
		*(pa_str++) = s[start++];
	*pa_str = '\0';
	return (pa_str);
}
