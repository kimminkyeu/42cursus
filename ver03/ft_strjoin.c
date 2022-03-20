/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:49:28 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/14 14:02:25 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// TODO: 아니 설마 ft_strlen 이거 때문에 그런거임??
// 아래 처럼 그냥 정의 자체를 가져오니까 되나?

// TODO: 예외처리 진행. 두 입력이 모두 빈 문자열이면 뭘 해야 할까?
// 그럼 freeable size 1 을 보내줘야 할까?

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*pa_str;
	char	*tmp;

	// TODO: Error log : 아래 예외처리만 넣어줬더니 테스트 통과함 ;;
	//
	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);

	/** if (total_len == 0)
	  *     return (NULL); */

	pa_str = malloc(sizeof(*pa_str) * (total_len + 1));
	if (!pa_str)
		return (NULL);
	tmp = pa_str;
	while (*s1)
		*tmp++ = *s1++; 
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (pa_str);
}
/** 
  * #include <stdio.h>
  * int main(int argc, char *argv[])
  * {
  *     if (argc != 3)
  *         return 0;
  *     char *s = ft_strjoin(argv[1], argv[2]);
  *     printf("join :%s\n", s);
  * } */
