/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:52:40 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/11 16:14:51 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

// TODO: 코드가 좀 복잡해진 것 같다.
// 좀 깔끔하게 해야 하지 않을까....
/** 
 *
 * Error Logs
 *
 * (1) 예외처리 문제. 문자열에서 문자를 검색하되 가장 마지막으로 나타나는 위치를 찾는다.
 * (3) s가 빈문자열일 때, s의 첫 글자만 c일 때 NULL이 아니라 s의 첫글자를 반환해야 함.
 *
 * */
char	*ft_strrchr(const char *s, int c)
{
	// 길이를 재서 몇번 해야 할지부터 찾자.
	size_t	size;

	size = 0;
	while (*s)
	{
		s++;
		size++;
	}
	if (size == 0)
		return ((char *)s);
	while (size > 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		size--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
