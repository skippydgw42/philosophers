/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:10:41 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/07/12 17:13:23 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

void	ft_sleep(t_philo *philo)
{
	if (ft_isalive(philo) && philo->data->nrounds != 0)
	{
		printf("%ld %d is sleeping\n", ft_gettime(philo), philo->name);
		ft_usleep(philo, philo->data->time_sleep);
	}
}
