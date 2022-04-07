/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:58:37 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/31 17:22:32 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <stdbool.h>

# define BUFFER_SIZE (5)

/* std::vector */
typedef struct s_vector {
	size_t	size;
	size_t	capacity;
	void	*data;
}				t_vector;


extern void		*ft_memcpy(void *dst, const void *src, size_t n);
extern void		*ft_memset(void *b, int c, size_t len);
extern bool		has_data(char *array, int data, size_t len);
extern char		*get_next_line(int fd);
/* auto initializing data to 0 */
extern char		*new_data_malloc(size_t init_size);
extern void		cpy_to_vec_until(t_vector *vec, char *src, int stopper);
/* NOTE : t_vector does not handle null character by it self.
 *		  You must handle null character by yourself if vector is for string.
 *
 *		  AVOID USING (while (*str != '\0')) STATEMENT.
 *
 *		  */

extern t_vector	*new_vector_malloc(size_t init_capacity);

extern void		push_back_vector(t_vector *vec, int c);

extern void		delete_vector(t_vector *vec);

extern void		reserve_vector(t_vector *vec, size_t new_capacity);


#endif
