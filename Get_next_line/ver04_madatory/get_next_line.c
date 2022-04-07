/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:57:42 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/03 11:40:25 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

char	*my_substr(char const *s, unsigned int start, size_t len)
{
	char	*pa_str;

	pa_str = malloc(sizeof(*pa_str) * (len + 1));
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

void	cpy_to_array_until(t_array *stage, char *buffer, char stopper)
{
	size_t	i;

	i = 0;
	while ((stage->last_data != stopper) && (i < BUFFER_SIZE))
	{
		if (buffer[i] != '\0')
		{
			push_back_array(stage, buffer[i]);
			buffer[i] = '\0';
		}
		++i;
	}
}

char	*get_next_line(int fd)
{
	static char	s_buffer[BUFFER_SIZE];
	t_array		*stage;
	ssize_t		rd_size;
	char		*single_line;

	rd_size = 1;
	if (new_array_malloc(&stage, BUFFER_SIZE) == NULL)
		return (NULL);
	while (rd_size > 0 && (stage->last_data != '\n'))
	{
		if (is_mem_empty(s_buffer, BUFFER_SIZE))
			rd_size = read(fd, s_buffer, BUFFER_SIZE);
		if (rd_size <= 0 && is_mem_empty(stage->data, stage->size))
		{
			delete_array(stage);
			stage = NULL;
			return (NULL);
		}
		cpy_to_array_until(stage, s_buffer, '\n');
	}
	single_line = my_substr(stage->data, 0, stage->size);
	delete_array(stage);
	stage = NULL;
	return (single_line);
}
