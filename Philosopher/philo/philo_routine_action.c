/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_action.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:05:00 by minkyeki          #+#    #+#             */
/*   Updated: 2022/07/04 14:05:06 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_pickup_fork(t_philo *philo)
{
	if (philo->info->is_simualtion_over || philo->is_eat_finished)
		return ;
	if (philo->name % 2 == 0)
	{
		pthread_mutex_lock(&philo->info->forks[philo->name]);
		print_messege("has taken a fork", philo);
		pthread_mutex_lock(&philo->info->forks[(philo->name + 1) \
				% philo->info->number_of_philosophers]);
		print_messege("has taken a fork", philo);
	}
	else if (philo->name % 2 == 1)
	{
		pthread_mutex_lock(&philo->info->forks[(philo->name + 1) \
				% philo->info->number_of_philosophers]);
		print_messege("has taken a fork", philo);
		pthread_mutex_lock(&philo->info->forks[philo->name]);
		print_messege("has taken a fork", philo);
	}
}

void	philo_eat_done(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mutex_philo_safe);
	philo->info->finished_philoes++;
	pthread_mutex_unlock(&philo->info->mutex_philo_safe);
	philo->is_eat_finished = true;
	print_messege("has ate all", philo);
}

void	philo_eat(t_philo *philo)
{
	if (philo->info->is_simualtion_over || philo->is_eat_finished)
		return ;
	print_messege("is eating", philo);
	philo->last_meal_time = get_current_time();
	ft_sleep(philo->info->time_to_eat);
	philo->eat_count++;
	if (philo->eat_count == philo->info->number_of_must_eat)
		philo_eat_done(philo);
	if (philo->name % 2 == 0)
	{
		pthread_mutex_unlock(&philo->info->forks[philo->name]);
		pthread_mutex_unlock(&philo->info->forks[(philo->name + 1) \
				% philo->info->number_of_philosophers]);
	}
	else if (philo->name % 2 == 1)
	{
		pthread_mutex_unlock(&philo->info->forks[(philo->name + 1) \
				% philo->info->number_of_philosophers]);
		pthread_mutex_unlock(&philo->info->forks[philo->name]);
	}
}

void	philo_sleep(t_philo *philo)
{
	if (philo->info->is_simualtion_over || philo->is_eat_finished)
		return ;
	print_messege("is sleeping", philo);
	ft_sleep(philo->info->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	if (philo->info->is_simualtion_over || philo->is_eat_finished)
		return ;
	print_messege("is thinking", philo);
}
