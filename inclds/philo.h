/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:54:03 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/07/18 12:40:57 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# define INT_MAX 2147483647
typedef struct s_data
{
	pthread_mutex_t	dying;
	pthread_mutex_t	sating;
	int				nphilo;
	int				alive;
	long			time_eat;
	long			time_sleep;
	long			time_die;
	int				sated;
	int				nrounds;
}	t_data;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	struct timeval		c_time;
	pthread_t			p;
	int					name;
	long				time;
	long				start_time;
	long				finish_time;
	struct s_data		*data;
	struct s_fork		*fork;
	struct s_philo		*next;
	struct s_philo		*prev;
}	t_philo;

//===========ADD============//
int		ft_stderr(char *str);
int		ft_atoi(const char *str);
void	ft_destroy(t_philo *philo);
void	ft_free_all(t_philo *philo);
void	ft_usleep(t_philo *philo, long value);

//=========PARSING==========//
int		ft_parsing(int ac, char **av);

//===========INIT============//
t_data	*ft_initdata(char **av);
t_philo	*ft_initphilos(char **av);
void	ft_setprev(t_philo *philo);
int		ft_create(t_philo *philo);
void	ft_joindata(t_philo *philo, t_data *data);

//===========SRCS============//
void	*routine(void *philo);
void	ft_thinking(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
int		ft_isalive(t_philo *philo);
long	ft_gettime(t_philo *philo);

int		ft_take_fork(t_philo *philo);
//========spare function=========//
int		take_fork(t_philo *philo);

#endif