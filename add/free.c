/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:10:05 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/28 14:05:33 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

void	ft_free_all(t_philo *philo)
{
	t_philo	*ptr;

	while (philo)
	{
		ptr = philo;
		philo = philo->next;
		free(ptr->data);
		free(ptr->fork);
		free(ptr);
	}
}