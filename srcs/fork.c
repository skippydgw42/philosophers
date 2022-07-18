/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:54:19 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/07/18 11:57:38 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

int	take_fork(t_philo *philo)
{
	while (ft_isalive(philo))
	{
		if (pthread_mutex_lock(&philo->fork->mutex) == 0)
		{
			if (ft_isalive(philo))
			{
				if (pthread_mutex_lock(&philo->next->fork->mutex) == 0)
						return (1);
				else
					pthread_mutex_unlock(&philo->fork->mutex);
			}
			else
			{
				pthread_mutex_unlock(&philo->fork->mutex);
				return (0);
			}
		}
	}
	return (0);
}