/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:08:32 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/28 13:47:17 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

void	ft_destroy(t_philo *philo)
{
	t_philo	*ptr;

	ptr = philo;
	while (ptr)
	{
		pthread_mutex_destroy(&ptr->fork->mutex);
		ptr = ptr->next;
	}
}
