/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:58:25 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/07/12 17:39:30 by mdegraeu         ###   ########.fr       */
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
	if (philo->finish_time > 0)
	{
		ft_usleep(philo, 100);
		pthread_mutex_destroy(&philo->data->dying);
		printf("%ld %d is dead\n", philo->finish_time, philo->name);
	}
	else if (philo->finish_time == -1)
	{
		ft_usleep(philo, 100);
		printf("Rounds passed\n");
	}
	else
	{
		ft_usleep(philo, 200);
		exit (EXIT_SUCCESS);
	}
}

void	*routine(void *philo)
{
	t_philo	*ptr;

	ptr = philo;
	if (ptr->name % 2 == 0)
		usleep(100);
	ptr->start_time = ft_gettime(philo);
	while (ptr->data->alive == 1 && ptr->data->nrounds != 0)
	{
		ft_thinking(ptr);
		if (ptr->data->nrounds != 0 && ptr->data->alive == 1)
			ft_eat(ptr);
		if (ptr->data->nrounds != 0 && ptr->data->alive == 1)
			ft_sleep(ptr);
	}
	usleep(100);
	pthread_mutex_destroy(&ptr->fork->mutex);
	ft_end(ptr);
	return (NULL);
}
