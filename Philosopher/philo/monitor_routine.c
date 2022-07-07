/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:00:56 by minkyeki          #+#    #+#             */
/*   Updated: 2022/07/06 15:09:33 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_routine(void *arg)
{
	t_info		*_info;
	int			i;
	long long	starving_time;

	_info = (t_info *)arg;
	i = 0;
	while (true)
	{
		if (_info->finished_philoes == _info->number_of_philosophers)
			break ;
		if (i >= _info->number_of_philosophers)
			i = 0;
		starving_time = get_current_time() \
						- _info->philo_group[i].last_meal_time;
		if (!(_info->philo_group[i].is_eat_finished) \
				&& starving_time >= _info->time_to_die)
		{
			print_messege("died", &_info->philo_group[i]);
			pthread_mutex_lock(&_info->mutex_print_safe);
			_info->is_simualtion_over = true;
			break ;
		}
		i++;
	}
	return (SUCCESS);
}
