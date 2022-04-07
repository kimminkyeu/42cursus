/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:58:37 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/02 17:06:33 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdbool.h>

extern char		*get_next_line(int fd);

typedef struct s_vector {
	size_t	size;
	size_t	capacity;
	char	*data;
}				t_vector;

extern bool		is_mem_empty(void *data, size_t len);
extern char		*ft_substr(char const *s, unsigned int start, size_t len);
extern void		*ft_memcpy(void *dst, const void *src, size_t n);
void			cpy_to_vec_until(t_vector *stage, char *buffer, char stopper);
extern t_vector	*vector_malloc_or_null(t_vector **vec, size_t init_capacity);
extern char		*data_malloc_or_null(size_t init_size);
extern void		push_back_vector(t_vector *vec, int c);
extern void		delete_vector(t_vector *vec);
extern void		reserve_vector(t_vector *vec, size_t new_capacity);

#endif
