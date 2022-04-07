/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:57:42 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/01 22:10:29 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

/* default BUFFER_SIZE is 5  */
/* TODO : add description to header file!!!  */

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	t_vector	*stage;
	ssize_t		rd_size;
	size_t		i;
	char		*final_product;

	rd_size = 1;
	// init dynamic array stage.
	stage = new_vector_malloc(BUFFER_SIZE);
	// while read finishes and stage's last element is \n
	while (rd_size > 0 && (stage->data)[stage->size - 1] != '\n')
	{
		/* if buffer is empty, read data to buffer */
		if (is_mem_empty(buffer, BUFFER_SIZE))
			rd_size = read(fd, buffer, BUFFER_SIZE);
		if (is_mem_empty(stage->data, stage->size) && rd_size <= 0)
		{
			delete_vector(stage);
			return (NULL);
		}
		/* copy to vector until vector's last element is \n. */
		i = 0;
		while (((stage->data)[stage->size - 1] != '\n') && (i < BUFFER_SIZE))
		{
			if (buffer[i] != '\0')
			{
				push_back_vector(stage, buffer[i]);
				buffer[i] = '\0';
			}
			++i;
		}
	}
	final_product = ft_substr(stage->data, 0, stage->size);
	delete_vector(stage);

	// (9) return final product. at it's size, add null character to end
	return (final_product);
}
