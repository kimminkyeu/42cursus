/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:58:37 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/03 12:55:04 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <sys/types.h>

/* Return a line read from a file descriptor, NULL if there is 
 * nothing else to read, or an error occurred */
extern char		*get_next_line(int fd);

typedef struct s_array {
	size_t	size;
	size_t	capacity;
	char	*data;
	char	last_data;
}				t_array;

extern bool		is_mem_empty(void *data, size_t len);
extern char		*my_substr(char const *s, unsigned int start, size_t len);
extern void		*ft_memcpy(void *dst, const void *src, size_t n);
void			cpy_to_array_until(t_array *stage, char *buffer, char stopper);
extern t_array	*new_array_malloc(t_array **array, size_t init_capacity);
extern char		*new_str_malloc(size_t init_size);
extern void		push_back_array(t_array *array, int c);
extern void		delete_array(t_array *array);
extern void		reserve_array(t_array *array, size_t new_capacity);

#endif
