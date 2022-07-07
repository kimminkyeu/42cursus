/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_array.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <yonghlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:12:13 by yonghlee          #+#    #+#             */
/*   Updated: 2022/02/23 18:35:48 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_array.h"

t_array	*init_array(void)
{
	int		i;
	t_array	*array;

	array = (t_array *)malloc(sizeof(t_array));
	array->len = 0;
	array->capacity = 10;
	array->data = (char *)malloc(sizeof(char) * (array->capacity + 1));
	if (array->data == 0)
		return (0);
	i = 0;
	while (i <= array->capacity)
		array->data[i++] = 0;
	return (array);
}

int	append_array(t_array *array, char val)
{
	int		i;
	char	*new_data;

	if (array->len == array->capacity)
	{
		new_data = (char *)malloc(sizeof(char) * (array->capacity * 2 + 1));
		if (new_data == 0)
			return (0);
		i = -1;
		while (++i < array->capacity)
			new_data[i] = array->data[i];
		while (i < array->capacity * 2 + 1)
			new_data[i++] = 0;
		free(array->data);
		array->data = new_data;
		array->capacity *= 2;
	}
	array->data[array->len++] = val;
	return (1);
}

void	clear_arrary(t_array	*array)
{
	int	i;

	i = 0;
	while (i < array->capacity)
	{
		array->data[i] = 0;
		i++;
	}
	array->len = 0;
}

void	free_array(t_array *array)
{
	if (array->data)
		free(array->data);
}
