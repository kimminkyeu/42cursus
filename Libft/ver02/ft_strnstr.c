/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:39:26 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/13 16:44:33 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

// 정해진 길이 내에서 문자열을 찾는 함수. -> 혹시 strcmp 써도 되나?
// strcmp가 만약 0이라면, 두 문자열이 동일하다는 의미 아닐까?
// TODO : 수정사항 : 굳이 복사를 해야 할까? 그냥 그대로 쓰면 안되나?
#include "libft.h"

static int is_same(const char *s1, const char *tofind)
{
	while (*s1 && *tofind && (*s1 == *tofind))
	{
		s1++;
		tofind++;
	}
	if (*tofind == '\0')
		return (1);
	return (0);
}

/** static size_t	ft_strlen(const char *str)
  * {
  *     size_t	size;
  *
  *     size = 0;
  *     while (str[size])
  *         size++;
  *     return (size);
  * } */
// return value : 찾은 대상 문자열의 시작점 포인터.
// 만약 little 값이 비어 있으면 big를 반환한다.
// big 문자열에서 little 문자열을 찾지 못하면 NULL을 반환한다.
// little 문자열을 찾으면 big에 little 문자열 시작 부분 위치 주소를 반환한다.

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_size;
	size_t	haystack_size;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_size = ft_strlen(needle);
	haystack_size = ft_strlen(haystack);
	while (*haystack && (len >= needle_size) && (haystack_size >= needle_size))
	{
		if (is_same(haystack, needle))
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}

/** 
 * error log. 틀린 이유 : needle size에 대한 부분과, strcmp가 아닌 그냥 같냐만 보면 됨...
 * 정렬이 아닌 이상 strcmp를 쓰면 잘못된 값이 나옴...
 *
 *
 * */
