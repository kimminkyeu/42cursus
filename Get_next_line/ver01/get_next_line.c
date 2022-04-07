/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:57:42 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/31 22:01:18 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"


/* TODO : delete below header!  */
#include "for_test.h"

/* default BUFFER_SIZE is 5  */
/* TODO : add description to header file!!!  */

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_char;

	b_char = (unsigned char *)b;
	while (len > 0)
	{
		*b_char = (unsigned char)c;
		++b_char;
		--len;
	}
	return (b);
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

bool	has_data(char *array, int data, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{

		if (array[i] == data)
			return (true);
		++i;
	}
	return (false);
}

void	cpy_to_vec_until(t_vector *vec, char *backup, int stopper)
{
	size_t	i;
	char	*tmp;

	i = 0;	
	tmp = vec->data;
	
	while (i < BUFFER_SIZE) /* [FIXME :error] tmp[vec->size - 1] != stopper */
	{
		if (backup[i] == '\0')
		{
			++i;
			continue ;
		}
		if (backup[i] != '\0')
		{
			push_back_vector(vec, backup[i]); // stop if vector has '\n'
			backup[i] = '\0';  // null terminate src's copied data.
			++i;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	backup[BUFFER_SIZE];
	t_vector	*stage;
	char		*final_product;

	stage = new_vector_malloc(BUFFER_SIZE);	

	/* FIXME : 반복문이 잘못되어 있음.  
	 *			(1) 첫 getnextline 함수가 끝나면(hello -> [! m y \n n], backup에는 다음 read 정보가 들어있음.
	 *				따라서 while문 안에서 read가 일어나버려서 backup에 덮어쓰기가 됨. 
	 * */

	print_backup(backup, BUFFER_SIZE);
	print_vector(stage);

	ssize_t rd_size;
	rd_size = 1;
	// 일단 먼저 버퍼에서 읽는다. 버퍼가 비어있다면
	while (rd_size != 0)
	{
		if (((char *)(stage->data))[(stage->size) - 1] == '\n')
			break ; 	

		if (backup[BUFFER_SIZE - 1] == '\0')  // if backup if empty
		{
			rd_size = read(fd, backup, BUFFER_SIZE);
			cpy_to_vec_until(stage, backup, '\n');
		}
	}


	printf("\n");
	print_backup(backup, BUFFER_SIZE);
	print_vector(stage);


	/** while (read(fd, backup, BUFFER_SIZE) != 0 \ */
	/**         && !has_data(backup, '\n', BUFFER_SIZE)) */
	/** { */
	/**     print_backup(backup, BUFFER_SIZE); */
	/**     print_vector(stage); */
    /**  */
    /**  */
	/**     cpy_to_vec_until(stage, backup, '\n'); */
    /**  */
    /**  */
	/**     printf("\n"); */
    /**  */
	/**     print_backup(backup, BUFFER_SIZE); */
	/**     print_vector(stage); */
    /**  */
	/**     printf("\n"); */
	/** } */
	final_product = new_data_malloc(stage->size);
	ft_memcpy(final_product, stage->data, stage->size);
	delete_vector(stage);
	return (final_product);
}
