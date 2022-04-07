/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:03:00 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/01 22:03:06 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

bool	is_mem_empty(void *data, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (((unsigned char *)data)[i] != '\0')
			return (false);
		++i;
	}
	return (true);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_size;

	src_size = 0;
	while (src[src_size])
		++src_size;
	if (dstsize == 0)
		return (src_size);
	i = 0;
	while (src[i] && (i + 1 < dstsize))
	{
		dst[i] = src[i];
		++i;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (src_size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	cnt;
	char	*pa_str;

	cnt = 0;
	while (s[start + cnt] && (cnt < len) && (start < len))
		++cnt;
	pa_str = malloc(sizeof(*pa_str) * (cnt + 1));
	if (!pa_str)
		return (NULL);
	ft_strlcpy(pa_str, s + start, cnt + 1);
	return (pa_str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*u_dst;
	const unsigned char	*u_src;
	size_t				i;

	u_dst = (unsigned char *)dst;
	u_src = (const unsigned char *)src;
	if (dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		u_dst[i] = u_src[i];
		++i;
	}
	return (dst);
}

t_vector	*new_vector_malloc(size_t init_capacity)
{
	t_vector	*vec;

	vec = malloc(sizeof(*vec));
	if (vec)
	{
		vec->size = 0;
		vec->capacity = init_capacity;
		vec->data = new_data_malloc(vec->capacity);
		if (!(vec->data))
		{
			delete_vector(vec);
			vec = NULL;
		}
	}
	return (vec);
}

char	*new_data_malloc(size_t init_size)
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
	tmp = new_data_malloc(new_capacity);
	ft_memcpy(tmp, vec->data, vec->size);
	free(vec->data);
	vec->data = tmp;
	vec->capacity = new_capacity;
}

void	delete_vector(t_vector *vec)
{
	if (!vec)
		return ;
	if (vec->data != NULL)
		free(vec->data);
	free(vec);
}

