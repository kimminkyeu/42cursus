/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:20:10 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/20 18:57:44 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

char	*ft_open_read(void)
{
	int		fd;
	char	*buffer;
	int		rd_size;

	buffer = malloc(sizeof(char) * BUFF_SIZE);
	if (!buffer)
	{
		write(1, "Buffer Error\n", 14);
		return (0);
	}
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		write(1, "File Open Error\n", 17);
	else
	{
		rd_size = read(fd, buffer, BUFF_SIZE);
		if (rd_size == -1)
			write(1, "File Read Error\n", 17);
		else
			close(fd);
	}
	return (buffer);
}

char	*ft_open_read_argv(char *new_dict)
{
	int		fd;
	char	*buffer;
	int		rd_size;

	buffer = malloc(sizeof(char) * BUFF_SIZE);
	if (!buffer)
	{
		write(1, "Buffer Error\n", 14);
		return (0);
	}
	fd = open(new_dict, O_RDONLY);
	if (fd == -1)
		write(1, "File Open Error\n", 17);
	else
	{
		rd_size = read(fd, buffer, BUFF_SIZE);
		if (rd_size == -1)
			write(1, "File Read Error\n", 17);
		else
			close(fd);
	}
	return (buffer);
}
