/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:07:06 by minkyeki          #+#    #+#             */
/*   Updated: 2022/07/03 23:07:55 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdbool.h>
# include <stddef.h>
# include <limits.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <memory.h>
# include <signal.h>

# define FORK ("/sem_forks")
# define PRINT_SAFE ("/sem_print_safe")

# define SUCCESS			(0)
# define ERROR				(1)

# define EAT_GOAL_DONE		(1)
# define EAT_GOAL_UNDONE	(0)

# define DIED				(0xff)

# define THREAD_NOT_STARTED (0)
# define THREAD_STARTED		(1)

# define C_NRML ("\033[0m")
# define C_BLCK ("\033[30m")
# define C_RED  ("\033[31m")
# define C_GREN ("\033[32m")
# define C_YLLW ("\033[33m")
# define C_BLUE ("\033[34m")
# define C_PRPL ("\033[35m")
# define C_AQUA ("\033[36m")

typedef struct s_info	t_info;

typedef struct s_philo {
	pthread_t		monitor;
	pid_t			pid;
	int				name;
	int				eat_count;
	long long		last_meal_time;
	int				is_eat_finished;
	int				is_dead;
	t_info			*info;
}	t_philo;

typedef struct s_info {
	t_philo			philo;
	sem_t			*forks;
	sem_t			*sem_print_safe;
	long long		start_time;
	long long		finish_time;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
}	t_info;

/* philo_routine */
extern void			philo_routine(void *arg);

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