/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:00:25 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/16 10:48:47 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/** Error log :  
 *
 * (1) cnt이 0일 때는 빈 문자열 넣어줘라
 *
 * */

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	cnt;
	char	*pa_str;
	/** char	*pa_tmp; */

	if (!s)
		return (NULL);
	cnt = 0;
	while (s[start + cnt] && (cnt < len) && (start < ft_strlen(s)))
		++cnt;
	pa_str = malloc(sizeof(*pa_str) * (cnt + 1));
	if (!pa_str)
		return (NULL);
	ft_strlcpy(pa_str, s + start, cnt + 1);
	
	/** pa_tmp = pa_str; */
	/** while (cnt-- > 0) */
	/**     *(pa_tmp++) = s[start++]; */
	/** *pa_tmp = '\0'; */
	return (pa_str);
}
