/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:49:28 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/13 16:48:52 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/** static size_t	ft_strlen(const char *str)
  * {
  *     size_t	size;
  *
  *     size = 0;
  *     while (str[size])
  *         size++;
  *     return (size);
  * } */


// TODO: 예외처리 진행. 두 입력이 모두 빈 문자열이면 뭘 해야 할까?
// 그럼 freeable size 1 을 보내줘야 할까?


char *ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*pa_str;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	pa_str = malloc(sizeof(*pa_str) * (total_len + 1));
	if (!pa_str)
		return (NULL);
	while (*s1)
		*pa_str++ = *s1++; 
	while (*s2)
		*pa_str++ = *s2++;
	*pa_str = '\0';
	return (pa_str);
}
