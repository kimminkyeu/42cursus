/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:17:07 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/21 09:27:14 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	size_t	size;
	char	*tmp;
	size_t	i;

	if (!src)
		return (NULL);
	size = 0;
	i = 0;
	while (src[i++])
		++size;
	tmp = malloc(sizeof(*tmp) * (size + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < size && src[i] != '\0')
	{
		tmp[i] = src[i];
		++i;
	}
	tmp[size] = '\0';
	return (tmp);
}
