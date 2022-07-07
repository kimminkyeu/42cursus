/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:07:06 by minkyeki          #+#    #+#             */
/*   Updated: 2022/07/04 14:06:33 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <stddef.h>
# include <limits.h>
# include <memory.h>

# define SUCCESS			(0)
# define ERROR				(1)

# define EAT_GOAL_DONE		(1)
# define EAT_GOAL_UNDONE	(0)

# define DIED				(2)

# define THREAD_NOT_STARTED (0)
# define THREAD_STARTED		(1)

typedef struct s_info	t_info;

typedef struct s_philo {
	pthread_t		thread;
	int				name;
	int				eat_count;
	long long		last_meal_time;
	int				is_eat_finished;
	t_info			*info;
}	t_philo;

typedef struct s_info {
	t_philo			*philo_group;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_print_safe;
	pthread_mutex_t	mutex_philo_safe;
	pthread_t		monitor;
	long long		start_time;
	long long		finish_time;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
	int				is_simualtion_over;
	int				finished_philoes;
}	t_info;

/* philo_routine */
extern void			*philo_routine(void *arg);

/* philo_routine_action */
extern void			philo_pickup_fork(t_philo *philo);
extern void			philo_eat_done(t_philo *philo);
extern void			philo_eat(t_philo *philo);
extern void			philo_sleep(t_philo *philo);
extern void			philo_think(t_philo *philo);

/* monitor_routine */
extern void			*monitor_routine(void *arg);

/* philo_helper */
extern long long	get_current_time(void);
extern void			print_messege(const char *messege, t_philo *philo);
extern void			ft_sleep(int time);
extern long long	get_timestamp(t_info *info);

/* philo_utils */
extern int			error(char *messege);
extern int			ft_atoi(const char *str);
extern bool			ft_is_positive_integer(char *s);

#endif /* PHILO_H */
