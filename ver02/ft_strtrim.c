/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:10:06 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/13 16:44:51 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

// TODO : 예외처리 사항
//			(1) 주의해야할 점은 원본 문자열 전체가 set에 포함되는 문자일 때이다.
//			--> 내 코드에선 이 경우 빈 문자열이 반환된다. 

static bool	is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (true);
	}
	return (false);
}

char *ft_strtrim(char const *s1, char const *set)
{
	size_t	w_cnt;
	char	*pa_str;

	w_cnt = 0;
	while (*s1)
		if (!is_set(*s1, set))
			++w_cnt;
	pa_str = malloc(sizeof(*pa_str) * (w_cnt + 1));
	if (!pa_str)
		return (NULL);
	while (w_cnt-- > 0)
	{
		if (!is_set(*s1, set))
		{
			*pa_str = *s1;
			++pa_str;
		}
		++s1;
	}
	*pa_str = '\0';
	return (pa_str);
}
