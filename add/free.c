/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:10:05 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/07/08 21:53:18 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

void	ft_free_all(t_philo *philo)
{
	int		i;
	int		n;
	t_philo	*ptr;

	i = 0;
	n = philo->data->nphilo;
	free(philo->data);
	while (i < n)
	{
		ptr = philo;
		philo = philo->next;
		free(ptr->fork);
		free(ptr);
		i++;
	}
}
