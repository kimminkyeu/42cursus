/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_panel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:53:29 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/03 21:25:28 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/control_panel.h"

void	draw_panel_1(t_mlx *fdf, int font_color, int top, int margin)
{
	int	left;

	left = 50;
	mlx_string_put(fdf->mlx, fdf->win, left, top, font_color, \
			"Camera Control");
	mlx_string_put(fdf->mlx, fdf->win, left, top + margin, font_color, \
			"--------------------------------------");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 2 * margin, font_color, \
			"| Move      : UP DOWN LEFT RIGHT     |");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 3 * margin, font_color, \
			"| Rotate X  : A D                    |");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 4 * margin, font_color, \
			"| Rotate Y  : W S                    |");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 5 * margin, font_color, \
			"| Rotate Z  : Q E                    |");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 6 * margin, font_color, \
			"| Zoom      : Scroll up / down       |");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 7 * margin, font_color, \
			"| Reset     : R                      |");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 8 * margin, font_color, \
			"--------------------------------------");
}

void	draw_panel_2(t_mlx *fdf, int font_color, int top, int margin)
{
	int	left;

	left = 50;
	mlx_string_put(fdf->mlx, fdf->win, left, top + 10 * margin, font_color, \
			"Change View");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 11 * margin, font_color, \
			"--------------------------------------");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 12 * margin, font_color, \
			"| Pararell     : press 1             |");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 13 * margin, font_color, \
			"| Isometric    : press 2             |");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 14 * margin, font_color, \
			"--------------------------------------");
}

void	draw_panel_3(t_mlx *fdf, int font_color, int top, int margin)
{
	int		left;
	char	*str1;
	char	*str2;
	char	*str3;

	left = 50;
	str1 = ft_itoa(fdf->map_info.max_x * fdf->map_info.max_y);
	str2 = ft_itoa(fdf->camera.zoom_rate);
	str3 = ft_itoa((int)(fdf->camera.z_unit * 10));
	mlx_string_put(fdf->mlx, fdf->win, left, top + 15 * margin, font_color, \
			"Total number of points");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 16 * margin, GREEN, \
			str1);
	mlx_string_put(fdf->mlx, fdf->win, left, top + 18 * margin, font_color, \
			"Camera zoom rate");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 19 * margin, GREEN, \
			str2);
	mlx_string_put(fdf->mlx, fdf->win, left + margin, top + 19 * margin, font_color, \
			"/50");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 21 * margin, font_color, \
			"Z-depth ratio");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 22 * margin, GREEN, \
			str3);
	free(str1);
	free(str2);
	free(str3);
}

void	draw_control_panel(t_mlx *fdf, int font_color)
{
	int	margin;
	int	top;

	margin = 20;
	top = 50;
	draw_panel_1(fdf, font_color, top, margin);
	draw_panel_2(fdf, font_color, top, margin);
	draw_panel_3(fdf, font_color, top, margin);
}
