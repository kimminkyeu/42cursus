/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:23:44 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/21 10:44:24 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	size_t	size;
	int		*arr;
	size_t	i;

	if (min >= max)
		return (NULL);
	size = (size_t)max - (size_t)min;
	arr = malloc(sizeof(*arr) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = min;
		++i;
		++min;
	}
	return (arr);
}
