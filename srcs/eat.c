/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:10:27 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/07/18 13:59:49 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

void	ft_rounds(t_philo *philo)
{
	if (philo->data->sated == philo->data->nphilo)
	{
		philo->data->sated = 0;
		philo->data->nrounds--;
		if (philo->data->nrounds == 0)
			philo->finish_time = -1;
	}
	pthread_mutex_lock(&philo->data->sating);
	philo->data->sated++;
	pthread_mutex_unlock(&philo->data->sating);
}

void	ft_eat(t_philo *philo)
{
	if (take_fork(philo))
	{
		if (ft_isalive(philo))
		{
			philo->time = ft_gettime(philo);
			printf("%ld %d is eating\n", philo->time, philo->name);
			ft_usleep(philo, philo->data->time_eat);
		}
		if (philo->data->nrounds > 0)
			ft_rounds(philo);
		pthread_mutex_unlock(&philo->fork->mutex);
		pthread_mutex_unlock(&philo->next->fork->mutex);
	}
}
