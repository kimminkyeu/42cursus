/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:22:43 by minkyeki          #+#    #+#             */
/*   Updated: 2022/07/04 14:05:12 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		if (philo->name % 2 == 0)
			ft_sleep(1);
		if (philo->info->is_simualtion_over || philo->is_eat_finished)
			break ;
		philo_pickup_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (SUCCESS);
}
