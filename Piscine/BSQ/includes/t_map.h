/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <yonghlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:16:48 by yonghlee          #+#    #+#             */
/*   Updated: 2022/02/23 16:17:37 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

# include "t_array.h"

typedef struct s_map {
	int		rows;
	int		cols;
	int		**data;
	char	c_empty;
	char	c_obstacle;
	char	c_full;
	int		max_len;
	int		square_x;
	int		square_y;
}	t_map;

t_map	*init_map(void);
int		set_map(t_map *map);
int		append_map(t_map *map, t_array *array, int	row_idx_to_append);
void	free_map(t_map *map);
void	print_map(t_map *map);

#endif
