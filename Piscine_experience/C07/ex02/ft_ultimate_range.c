/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:32:56 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/23 09:16:10 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	size_t	size;
	size_t	i;
	int		*arr;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = (size_t)max - (size_t)min;
	arr = malloc(sizeof(*arr) * size);
	if (!arr)
		return (-1);
	i = 0;
	while (i < size)
	{
		arr[i] = min + i;
		++i;
	}
	*range = arr;
	return ((int)size);
}
