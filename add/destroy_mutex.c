/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:08:32 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/27 19:29:16 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

void	ft_destroy(t_data *data)
{
	t_philo	*ptr;

	ptr = data->lst;
	while (ptr)
	{
		pthread_mutex_destroy(&ptr->fork->mutex);
		ptr = ptr->next;
	}
}
