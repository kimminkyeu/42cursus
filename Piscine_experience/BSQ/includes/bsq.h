/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:07:52 by yonghlee          #+#    #+#             */
/*   Updated: 2022/02/23 16:02:17 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include "t_map.h"

int		ft_min(int num1, int num2, int num3);
void	find_square(t_map *map);
void	fill_field(t_map *map);
void	final_square(t_map *map, char **field);
void	square_info(t_map *map);
void	free_field(t_map *map, char **field);

#endif
