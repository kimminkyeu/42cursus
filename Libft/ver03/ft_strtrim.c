/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:10:06 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/14 13:52:41 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"

// TODO : 예외처리 사항
//			(1) 주의해야할 점은 원본 문자열 전체가 set에 포함되는 문자일 때이다.
//			--> 내 코드에선 이 경우 빈 문자열이 반환된다. 
// error : 요구사항과 다르게 구현함. 시작과 끝을 없애주는 애임. 
// 시작점에서 set 문자가 아닐때 까지
// 끝점에서 set문자가 아닐때까지

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*pa_str;
	size_t		start_idx;
	size_t		end_idx;

	start_idx = 0;
	end_idx = ft_strlen(s1); //TODO : 1을 빼줘?
	if (!s1 || !set)
		return (NULL);
	// (1) 포인터 위치를 반환하는 함수 사용. 
	while (s1[start_idx] && ft_strchr(set, s1[start_idx]))
		++start_idx;
	while (ft_strrchr(set, s1[end_idx]) && start_idx < end_idx)
		--end_idx;
	pa_str = malloc(sizeof(*pa_str) * (end_idx - start_idx + 2)); // TODO : CHECK!
	ft_strlcpy(pa_str, &s1[start_idx], end_idx - start_idx + 2);
	return (pa_str);
}

/** int main(int ac, char *av[])
  * {
  *     if (ac != 3)
  *         return 0;
  *     char *s = ft_strtrim(av[1], av[2]);
  *     printf("%s", s);
  *     return (0);
  * } */
