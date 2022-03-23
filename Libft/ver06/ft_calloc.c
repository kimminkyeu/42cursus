/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:26:04 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/16 17:41:05 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	unsigned char	*tmp;

	if (nmemb > SIZE_MAX / size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	total_size = nmemb * size;
	if (total_size == 0)
		return (NULL);
	tmp = (unsigned char *)malloc(total_size);
	if (!tmp)
		return (NULL);
	while (total_size > 0)
	{
		tmp[total_size - 1] = 0;
		--total_size;
	}
	return ((void *)tmp);
}
