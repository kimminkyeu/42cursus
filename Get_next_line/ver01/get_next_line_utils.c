/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:03:00 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/31 13:21:08 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

/* ------------------------------------------------------ */
/* Below functions are for t_vector (Dynamic array) */
/* TODO : 초기 capacity를 size와 동일하게 처리. 버퍼가 10000일때 20000으로 시작할 필요 없음. */
t_vector	*new_vector_malloc(size_t init_capacity)
{
	t_vector	*vec;

	vec = malloc(sizeof(*vec));
	if (vec)
	{
		vec->size = 0;
		vec->capacity = init_capacity;
		vec->data = new_data_malloc(vec->capacity);
		/* NOTE : 벡터는 널 문자 고려할 필요 없음!   */
		if (!(vec->data))
		{
			delete_vector(vec);
			vec = NULL;
		}
	}
	return (vec);
}

void	delete_vector(t_vector *vec)
{
	if (!vec)
		return ;
	if (vec->data != NULL)
		free(vec->data);
	free(vec);
}

/* TODO : delete function for data free and vector free */
/* FIXME :  할당과 동시에 널캐릭터로 모두 채워줄 것 */
char	*new_data_malloc(size_t init_size)
{
	char	*str;

	str = malloc(sizeof(*str) * (init_size));
	if (str)
		ft_memset(str, 0, init_size); // NUll terminate every data
	return (str);
}


/* FIXME : is it okay to use unsigned char? */
void	push_back_vector(t_vector *vec, int c)
{
	unsigned char	*array;

	/* if size == capacity  */
	if (vec->size == vec->capacity) // if vector is full
		reserve_vector(vec, (vec->capacity) * 2); // make array bigger

	array = (unsigned char *)vec->data;
	array[vec->size] = (unsigned char)c;
	(vec->size)++;
}

void	reserve_vector(t_vector *vec, size_t new_capacity)
{
	char	*tmp;

	/* if new_capacity <= original capacity */
	if (new_capacity <= (vec->capacity))
		return ;

	/* else  */
	tmp = new_data_malloc(new_capacity);

	/* copy original data to tmp */
	// ft_strlcpy(tmp, vec->data, vec->size + 1);
	ft_memcpy(tmp, vec->data, vec->size);
	/* free original data, and change it's pointer to tmp */
	free(vec->data);
	vec->data = tmp;
	vec->capacity = new_capacity;
}


