/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:11:50 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/19 15:52:38 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "push_swap.h"

static int	compare(int i, int j, int inc_or_dec)
{
	if (inc_or_dec == INC)
		return (i > j);
	else
		return (i < j);
}

void	bubble_sort(int *data, int start, int end, int inc_or_dec)
{
	int	j;
	int	tmp;
	int	i;

	i = 0;
	while (i < end - start)
	{
		j = i + 1;
		while (j < end - start + 1)
		{
			if (compare(data[i], data[j], inc_or_dec))
			{
				tmp = data[j];
				data[j] = data[i];
				data[i] = tmp;
			}
			j++;
		}
		i++;
	}
}
