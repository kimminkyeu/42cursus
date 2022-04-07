/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:57:42 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/02 17:05:41 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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
	ft_memcpy(pa_str, s + start, len);
	pa_str[len] = '\0';
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

void	cpy_to_vec_until(t_vector *stage, char *buffer, char stopper)
{
	size_t	i;

	i = 0;
	while (((stage->data)[stage->size - 1] != stopper) && (i < BUFFER_SIZE))
	{
		if (buffer[i] != '\0')
		{
			push_back_vector(stage, buffer[i]);
			buffer[i] = '\0';
		}
		++i;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	t_vector	*stage;
	ssize_t		rd_size;
	char		*final_product;

	rd_size = 1;
	if (vector_malloc_or_null(&stage, BUFFER_SIZE) == NULL)
		return (NULL);
	while (rd_size > 0 && (stage->data)[stage->size - 1] != '\n')
	{
		if (is_mem_empty(buffer, BUFFER_SIZE))
			rd_size = read(fd, buffer, BUFFER_SIZE);
		if (rd_size <= 0 && is_mem_empty(stage->data, stage->size))
		{
			delete_vector(stage);
			return (NULL);
		}
		cpy_to_vec_until(stage, buffer, '\n');
	}
	final_product = ft_substr(stage->data, 0, stage->size);
	delete_vector(stage);
	return (final_product);
}
