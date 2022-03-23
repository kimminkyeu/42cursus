/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:00:25 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/16 18:00:38 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	cnt;
	char	*pa_str;

	if (!s)
		return (NULL);
	cnt = 0;
	while (s[start + cnt] && (cnt < len) && (start < ft_strlen(s)))
		++cnt;
	pa_str = malloc(sizeof(*pa_str) * (cnt + 1));
	if (!pa_str)
		return (NULL);
	ft_strlcpy(pa_str, s + start, cnt + 1);
	return (pa_str);
}
