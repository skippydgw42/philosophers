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
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				nrounds;
	struct s_philo	*lst;
}	t_data;

typedef struct	s_fork
{
	pthread_mutex_t	mutex;
	int				state;
}	t_fork;

typedef struct s_philo
{
	pthread_t		p;
	int				name;
	struct s_fork	*fork;
	struct s_philo	*next;
}	t_philo;

//===========ADD============//
int		ft_stderr(char *str);
int		ft_atoi(const char *str);
int		ft_parsing(int ac, char **av);
void	ft_destroy(t_data *data);
void	ft_free_data(t_data *data);

//===========INIT============//
void	ft_initstruct(t_data *data, char **av);
int		ft_initphilos(t_data *data);

//===========SRCS============//
void	*routine(void *data);

#endif