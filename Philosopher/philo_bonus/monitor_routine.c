/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:00:56 by minkyeki          #+#    #+#             */
/*   Updated: 2022/07/06 14:59:30 by minkyeki         ###   ########.fr       */
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
		if (_info->number_of_must_eat != 0 \
		&& _info->philo.eat_count == _info->number_of_must_eat)
		{
			print_messege("has ate all", &_info->philo);
			exit(SUCCESS);
		}
		starving_time = get_current_time() - _info->philo.last_meal_time;
		if (starving_time > _info->time_to_die)
		{
			_info->philo.is_dead = true;
			print_messege("died", &_info->philo);
			sem_wait(_info->sem_print_safe);
			exit(DIED);
		}
	}
}
