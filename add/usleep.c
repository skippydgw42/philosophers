/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:20:34 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/07/18 13:47:47 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

void	ft_usleep(t_philo *philo, long value)
{
	long	time;

	time = ft_gettime(philo);
	while (ft_gettime(philo) - time < value)
		usleep(100);
}
