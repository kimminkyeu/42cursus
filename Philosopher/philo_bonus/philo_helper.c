/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:26:13 by minkyeki          #+#    #+#             */
/*   Updated: 2022/07/06 14:59:48 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_current_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	if (time.tv_usec > 2)
		ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	else
		ms = (time.tv_sec * 1000);
	return (ms);
}

long long	get_timestamp(t_info *info)
{
	long long	ms;

	ms = get_current_time() - info->start_time;
	return (ms);
}

void	print_messege(const char *messege, t_philo *philo)
{
	long long	ms;

	ms = get_current_time() - philo->info->start_time;
	sem_wait(philo->info->sem_print_safe);
	if (philo->name % 2 == 0)
		printf("%s%10lld ms : %d %s\n", C_PRPL, ms, philo->name, messege);
	else
		printf("%s%10lld ms : %d %s\n", C_AQUA, ms, philo->name, messege);
	sem_post(philo->info->sem_print_safe);
}

void	ft_sleep(int time)
{
	long long	t1;

	t1 = get_current_time();
	while (get_current_time() - t1 < time)
		usleep(500);
}
