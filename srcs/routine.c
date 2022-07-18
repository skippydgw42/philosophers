/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:58:25 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/07/18 14:03:47 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

long	ft_gettime(t_philo *philo)
{
	long			time;

	gettimeofday(&philo->c_time, NULL);
	time = philo->c_time.tv_sec * 1000;
	time += philo->c_time.tv_usec / 1000;
	return (time - philo->start_time);
}

void	ft_end(t_philo *philo)
{
	int	n;

	n = 100;
	if (philo->data->nphilo >= 150)
		n = 200;
	if (philo->finish_time > 0)
	{
		ft_usleep(philo, n);
		pthread_mutex_destroy(&philo->data->dying);
		printf("%ld %d is dead\n", philo->finish_time, philo->name);
	}
	else if (philo->finish_time == -1)
	{
		ft_usleep(philo, 100);
		printf("Rounds passed\n");
	}
}

	// if (ptr->name % 2 == 0)
	// 	ft_usleep(philo, 100);
void	*routine(void *philo)
{
	t_philo	*ptr;

	ptr = philo;
	ptr->start_time = ft_gettime(philo);
	while (ft_minicheck(ptr))
	{
		if (ft_isalive(ptr))
			ft_thinking(ptr);
		if (ft_isalive(ptr))
			ft_eat(ptr);
		if (ft_isalive(ptr))
			ft_sleep(ptr);
	}
	usleep(100);
	pthread_mutex_destroy(&ptr->fork->mutex);
	ft_end(ptr);
	return (NULL);
}
