/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_panel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:53:29 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 11:29:24 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/engine.h"

static void	draw_panel_1(t_mlx *fdf, int font_color, int top, int margin)
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
			"| Rotate X  : W S                    |");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 4 * margin, font_color, \
			"| Rotate Y  : A D                    |");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 5 * margin, font_color, \
			"| Rotate Z  : Q E                    |");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 6 * margin, font_color, \
			"| Zoom      : Scroll up / down       |");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 7 * margin, font_color, \
			"| Reset     : R                      |");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 8 * margin, font_color, \
			"--------------------------------------");
}

static void	draw_panel_2(t_mlx *fdf, int font_color, int top, int margin)
{
	int	left;

	left = 50;
	mlx_string_put(fdf->mlx, fdf->win, left, top + 10 * margin, font_color, \
			"Change View");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 11 * margin, font_color, \
			"-------------------------------------");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 12 * margin, font_color, \
			"| Isometric    : press (1)          |");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 13 * margin, font_color, \
			"| Pararell     : press (2)          |");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 14 * margin, font_color, \
			"| Perspective  : press (3)          |");
	mlx_string_put(fdf->mlx, fdf->win, left, top + 15 * margin, font_color, \
			"-------------------------------------");
}

static void	draw_panel_3(t_mlx *fdf, int font_color, int top, int margin)
{
	char	*str1;

	str1 = ft_itoa(fdf->map_info.max_x * fdf->map_info.max_y);
	mlx_string_put(fdf->mlx, fdf->win, 50, top + 16 * margin, font_color, \
			"Total number of points");
	mlx_string_put(fdf->mlx, fdf->win, 50, top + 17 * margin, GREEN, \
			str1);
	free(str1);
	mlx_string_put(fdf->mlx, fdf->win, 50, top + 19 * margin, font_color, \
			"View Mode");
	if (fdf->camera->projection_num == ISOMETRIC)
		mlx_string_put(fdf->mlx, fdf->win, 50, top + 20 * margin, GREEN, \
				"Isometric");
	else if (fdf->camera->projection_num == PARALLEL)
		mlx_string_put(fdf->mlx, fdf->win, 50, top + 20 * margin, GREEN, \
				"Parallel");
	else if (fdf->camera->projection_num == PERSPECTIVE)
		mlx_string_put(fdf->mlx, fdf->win, 50, top + 20 * margin, GREEN, \
				"Perspective");
}

static void	draw_panel_4(t_mlx *fdf, int font_color, int top, int margin)
{
	char	*str2;
	char	*str3;

	str2 = ft_itoa(fdf->camera->zoom_rate);
	str3 = ft_itoa((int)(fdf->camera->z_unit * 10));
	mlx_string_put(fdf->mlx, fdf->win, 50, top + 21 * margin, font_color, \
			"Camera zoom rate");
	mlx_string_put(fdf->mlx, fdf->win, 50, top + 22 * margin, GREEN, \
			str2);
	mlx_string_put(fdf->mlx, fdf->win, 70, top + 22 * margin, font_color, \
			"/50");
	mlx_string_put(fdf->mlx, fdf->win, 50, top + 23 * margin, font_color, \
			"Z-depth ratio");
	mlx_string_put(fdf->mlx, fdf->win, 50, top + 24 * margin, GREEN, \
			str3);
	mlx_string_put(fdf->mlx, fdf->win, 70, top + 24 * margin, font_color, \
			"/20");
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
	draw_panel_4(fdf, font_color, top, margin);
}
