/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:48:01 by minkyeki          #+#    #+#             */
/*   Updated: 2022/07/06 15:17:13 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fork_and_run_philo(t_info *info, pid_t *philo_list)
{
	int	i;

	i = -1;
	while (++i < info->number_of_philosophers)
	{
		info->philo.pid = fork();
		info->philo.info = info;
		info->philo.last_meal_time = info->start_time;
		if (info->philo.pid < 0)
			return (ERROR);
		if (info->philo.pid == 0)
		{
			info->philo.name = i;
			pthread_create(&info->philo.monitor, NULL, monitor_routine, info);
			pthread_detach(info->philo.monitor);
			philo_routine(&info->philo);
		}
		philo_list[i] = info->philo.pid;
	}
	return (SUCCESS);
}

int	init_philo(t_info *info, pid_t *philo_list)
{
	int	i;
	int	wstatus;

	sem_unlink(FORK);
	sem_unlink(PRINT_SAFE);
	info->forks = sem_open(FORK, O_CREAT, 0664, info->number_of_philosophers);
	info->sem_print_safe = sem_open(PRINT_SAFE, O_CREAT, 0664, 1);
	info->start_time = get_current_time();
	if (fork_and_run_philo(info, philo_list) != SUCCESS)
		return (ERROR);
	i = -1;
	while (++i < info->number_of_philosophers)
	{
		waitpid(-1, &wstatus, 0);
		if ((wstatus >> 8 & 0xff) == DIED)
		{
			i = -1;
			while (++i < info->number_of_philosophers)
				kill(philo_list[i], SIGTERM);
			return (SUCCESS);
		}
	}
	return (SUCCESS);
}

int	init_basic_info(t_info *info, int ac, char *av[])
{
	info->number_of_philosophers = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->number_of_must_eat = 0;
	if (ac == 6)
		info->number_of_must_eat = ft_atoi(av[5]);
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
	pid_t	*philo_list;

	memset(&info, 0, sizeof(info));
	if (!is_valid_input(ac, av))
		return (ERROR);
	if (init_basic_info(&info, ac, av) != SUCCESS)
		return (ERROR);
	philo_list = malloc(sizeof(*philo_list) * info.number_of_philosophers);
	memset(philo_list, 0, sizeof(*philo_list) * info.number_of_philosophers);
	if (init_philo(&info, philo_list) != SUCCESS)
		return (ERROR);
	sem_close((info.sem_print_safe));
	sem_close((info.forks));
	free(philo_list);
	return (0);
}
