/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_array.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <yonghlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:14:06 by yonghlee          #+#    #+#             */
/*   Updated: 2022/02/23 16:15:38 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ARRAY_H
# define T_ARRAY_H

typedef struct s_array
{
	char	*data;
	int		capacity;
	int		len;
}	t_array;

t_array	*init_array(void);
int		append_array(t_array *array, char val);
void	clear_arrary(t_array *array);
void	free_array(t_array *array);

#endif
