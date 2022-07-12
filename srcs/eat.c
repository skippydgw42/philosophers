/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:10:27 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/07/12 17:40:08 by mdegraeu         ###   ########.fr       */
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
	philo->data->sated++;
}

void	ft_eat(t_philo *philo)
{
	if (ft_isalive(philo))
		take_fork(philo);
	if (ft_isalive(philo))
	{
		philo->time = ft_gettime(philo);
		printf("%ld %d is eating\n", philo->time, philo->name);
		ft_usleep(philo, philo->data->time_eat);
		if (philo->data->nrounds > 0)
			ft_rounds(philo);
	}
	philo->fork->state = 1;
	pthread_mutex_unlock(&philo->fork->mutex);
	philo->next->fork->state = 1;
	pthread_mutex_unlock(&philo->next->fork->mutex);
}
