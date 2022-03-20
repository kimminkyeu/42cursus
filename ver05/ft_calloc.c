/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:26:04 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/15 22:51:31 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>  // TODO : for SIZE_MAX
#include <errno.h>	// TODO : (공부 필요!) for errno setting (see menual of headers)

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	char	*tmp;

	if (nmemb > SIZE_MAX / size)
	{
		errno = ENOMEM;
		return (NULL); 
	}
	total_size = nmemb * size;
	if (total_size == 0)
		return (NULL);
	tmp = (char *)malloc(total_size);
	if (!tmp)
		return (NULL);
	while (total_size > 0)
	{
		tmp[total_size - 1] = 0;
		--total_size;
	}
	return ((void *)tmp);
}
