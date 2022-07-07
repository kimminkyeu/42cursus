/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:22:43 by minkyeki          #+#    #+#             */
/*   Updated: 2022/07/06 15:01:20 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_pickup_fork(t_philo *philo)
{
	if (philo->is_dead)
		return ;
	sem_wait(philo->info->forks);
	print_messege("has taken a fork", philo);
	sem_wait(philo->info->forks);
	print_messege("has taken a fork", philo);
}

static void	philo_eat(t_philo *philo)
{
	if (philo->is_dead)
		return ;
	print_messege("is eating", philo);
	philo->last_meal_time = get_current_time();
	ft_sleep(philo->info->time_to_eat);
	philo->eat_count++;
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
}

static void	philo_sleep(t_philo *philo)
{
	if (philo->is_dead)
		return ;
	print_messege("is sleeping", philo);
	ft_sleep(philo->info->time_to_sleep);
}

static void	philo_think(t_philo *philo)
{
	if (philo->is_dead)
		return ;
	print_messege("is thinking", philo);
}

void	philo_routine(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		philo_pickup_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}
