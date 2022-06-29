#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_data
{
	struct timeval	c_time;
	int				nphilo;
	int				alive;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				nrounds;
}	t_data;

typedef struct	s_fork
{
	pthread_mutex_t	mutex;
	int				state;
}	t_fork;

typedef struct s_philo
{
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
int		ft_parsing(int ac, char **av);
void	ft_destroy(t_philo *philo);
void	ft_free_all(t_philo *philo);

//===========INIT============//
t_data	*ft_initdata(char **av);
t_philo	*ft_initphilos(char **av);
void	ft_setprev(t_philo *philo);
int		ft_create(t_philo *philo);
void	ft_joindata(t_philo *philo, t_data *data);

//===========SRCS============//
void	*routine(void *philo);

#endif