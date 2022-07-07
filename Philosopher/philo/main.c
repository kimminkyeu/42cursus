/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:48:01 by minkyeki          #+#    #+#             */
/*   Updated: 2022/07/04 14:00:22 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_info *_info)
{
	int						i;

	if (pthread_mutex_init(&_info->mutex_print_safe, NULL) != SUCCESS)
		return (ERROR);
	if (pthread_mutex_init(&_info->mutex_philo_safe, NULL) != SUCCESS)
		return (ERROR);
	i = -1;
	while (++i < _info->number_of_philosophers)
	{
		_info->philo_group[i].name = i;
		_info->philo_group[i].info = _info;
		_info->philo_group[i].last_meal_time = get_current_time();
		if (pthread_mutex_init(&(_info->forks[i]), \
					NULL) != SUCCESS)
			return (ERROR);
	}
	return (SUCCESS);
}

int	init_thread_and_mutex(t_info *_info)
{
	int						i;

	_info->start_time = get_current_time();
	if (init_mutex(_info) == ERROR)
		return (ERROR);
	if (pthread_create(&_info->monitor, NULL, monitor_routine, _info))
		return (ERROR);
	i = -1;
	while (++i < _info->number_of_philosophers)
	{
		if (pthread_create(&(_info->philo_group[i].thread), NULL, \
					philo_routine, &(_info->philo_group[i])) != SUCCESS)
			return (ERROR);
		pthread_detach(_info->philo_group[i].thread);
	}
	pthread_join(_info->monitor, NULL);
	return (SUCCESS);
}

int	init_basic_info(t_info *info, int ac, char *av[])
{
	info->number_of_philosophers = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->number_of_must_eat = 0;
	info->is_simualtion_over = false;
	if (ac == 6)
		info->number_of_must_eat = ft_atoi(av[5]);
	info->philo_group = malloc(sizeof(*(info->philo_group)) \
			* info->number_of_philosophers);
	info->forks = malloc(sizeof(*(info->forks)) * info->number_of_philosophers);
	if (info->forks == NULL || info->philo_group == NULL)
		return (ERROR);
	memset(info->philo_group, 0, sizeof(t_philo) \
			* info->number_of_philosophers);
	memset(info->forks, 0, sizeof(pthread_mutex_t) \
			* info->number_of_philosophers);
	return (SUCCESS);
}

int	is_valid_input(int ac, char *av[])
{
	if ((ac != 5 && ac != 6) \
			|| !ft_is_positive_integer(av[1]) \
			|| !ft_is_positive_integer(av[2]) \
			|| !ft_is_positive_integer(av[3]) \
			|| !ft_is_positive_integer(av[4]) \
			|| (ac == 6 && !ft_is_positive_integer(av[5])))
	{
		printf("Error\n");
		return (false);
	}
	return (true);
}

int	main(int ac, char *av[])
{
	t_info	info;
	int		i;

	memset(&info, 0, sizeof(info));
	if (!is_valid_input(ac, av))
		return (ERROR);
	if (init_basic_info(&info, ac, av) != SUCCESS)
		return (ERROR);
	if (init_thread_and_mutex(&info) != SUCCESS)
		return (ERROR);
	i = -1;
	while (++i < info.number_of_philosophers)
		pthread_mutex_destroy(&(info.forks[i]));
	pthread_mutex_destroy(&(info.mutex_print_safe));
	pthread_mutex_destroy(&(info.mutex_philo_safe));
	if (info.philo_group != NULL)
		free(info.philo_group);
	if (info.forks != NULL)
		free(info.forks);
	return (0);
}
