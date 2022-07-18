/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_alive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:09:52 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/07/18 14:03:24 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

int	ft_minicheck(t_philo *philo)
{
	if (philo->data->alive == 0 || philo->data->nrounds == 0)
		return (0);
	return (1);
}

int	ft_isalive(t_philo *philo)
{
	long	isalive;

	isalive = 0;
	if (philo->data->alive == 0 || philo->data->nrounds == 0)
		return (0);
	isalive = ft_gettime(philo) - philo->time;
	if (isalive > philo->data->time_die)
	{
		if (pthread_mutex_lock(&philo->data->dying) == 0)
		{
			philo->finish_time = ft_gettime(philo);
			philo->data->alive = 0;
			pthread_mutex_unlock(&philo->data->dying);
			return (0);
		}
	}
	return (1);
}
