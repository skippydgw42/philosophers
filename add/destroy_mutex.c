/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:08:32 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/29 16:41:23 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

void	ft_destroy(t_philo *philo)
{
	int		i;
	t_philo	*ptr;

	i = 0;
	ptr = philo;
	while (i < ptr->data->nphilo)
	{
		pthread_mutex_destroy(&ptr->fork->mutex);
		ptr = ptr->next;
		i++;
	}
}
