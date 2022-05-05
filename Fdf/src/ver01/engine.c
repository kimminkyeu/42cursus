/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:16:30 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/26 20:21:26 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/engine.h"
#include "../include/defines.h"

int	handle_exit(void)
{
	ft_putstr_fd("Exit button pressed", STDOUT);
	exit(EXIT_SUCCESS);

	return (0);
}

int	handle_exit_key(int key_code, const int *target_key)
{
	if (key_code == *target_key)
	{
		ft_putstr_fd("Exit key pressed", STDOUT);
		exit(EXIT_SUCCESS);
	}

	/** system("leaks fdf > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp"); */
	return (0);
}

void	engine_init(t_mlx *data, int win_width, int win_height, char *title)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		perror("Error :");
		exit(EXIT_FAILURE);
	}
	data->win = mlx_new_window(data->mlx, win_width, win_height, title);
	if (data->win == NULL)
	{
		free(data->mlx);
		perror("Error :");
		exit(EXIT_FAILURE);
	}
}

void	engine_run_until(int key_code, t_mlx *data)
{
	mlx_hook(data->win, ON_DESTROY, 0, handle_exit, 0);
	mlx_hook(data->win, ON_KEY_PRESS, 0, handle_exit_key, &key_code);
	mlx_loop(data->mlx);
}
