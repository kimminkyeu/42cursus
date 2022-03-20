/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:28:13 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/09 19:28:41 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*tmp;
	size_t	i;

	if (!s1)
		return (NULL);
	size = 0;
	i = 0;
	while (s1[i++])
		++size;
	tmp = malloc(sizeof(*tmp) * (size + 1));
	if (!tmp)
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	// s1에 널이 없으면 이미 위에서  걸림 ㅋ 
	while (i < size)
	{
		tmp[i] = s1[i];
		++i;
	}
	return (tmp);	
}
