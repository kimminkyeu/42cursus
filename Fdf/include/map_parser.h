/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:30:31 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/26 19:41:31 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

# include <unistd.h>
# include <fcntl.h>

# include "libft.h"
# include "vector4.h"

# include "defines.h"

# define OPEN_ERROR		(-1)
# define STDOUT			(1)

/* ----------------------------------------------
 * - map_parser.h
 * * Open single file and return filedescriptor */
extern int		mp_open_file(int ac, char **av);

/* ----------------------------------------------
 * - map_parser.h
 * * NOTE : It Does Not Validate map-format!
 * * Parse string from the given fd, returns D-Array.
 * * Each element in D-Array stores an pointer to t_vector4 data 
 * (x, y, z, color)*/
extern t_darray	*mp_parse_file_malloc(int fd, size_t arr_init_size);

#endif /* MAP_PARSER_H */
