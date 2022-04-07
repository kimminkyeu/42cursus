/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:03:00 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/02 17:04:13 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_vector	*vector_malloc_or_null(t_vector **vec, size_t init_capacity)
{
	*vec = malloc(sizeof(**vec));
	if (*vec)
	{
		(*vec)->size = 0;
		(*vec)->capacity = init_capacity;
		(*vec)->data = data_malloc_or_null((*vec)->capacity);
		if (!(*vec)->data)
		{
			delete_vector(*vec);
			*vec = NULL;
		}
	}
	return (*vec);
}

char	*data_malloc_or_null(size_t init_size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(*str) * (init_size));
	if (str)
	{
		while (i < init_size)
		{
			str[i] = '\0';
			++i;
		}
	}
	return (str);
}

void	push_back_vector(t_vector *vec, int c)
{
	unsigned char	*array;

	if (vec->size >= vec->capacity)
		reserve_vector(vec, (vec->capacity) * 2);
	array = (unsigned char *)vec->data;
	array[vec->size] = (unsigned char)c;
	(vec->size)++;
}

void	reserve_vector(t_vector *vec, size_t new_capacity)
{
	char	*tmp;

	if (new_capacity <= (vec->capacity))
		return ;
	tmp = data_malloc_or_null(new_capacity);
	if (tmp)
	{
		ft_memcpy(tmp, vec->data, vec->size);
		free(vec->data);
		vec->data = tmp;
		vec->capacity = new_capacity;
	}
}

void	delete_vector(t_vector *vec)
{
	if (!vec)
		return ;
	if (vec->data != NULL)
		free(vec->data);
	free(vec);
}
