/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:40:05 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/07/11 17:58:57 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

void	ft_thinking(t_philo *philo)
{
	if (ft_isalive(philo) && philo->data->nrounds != 0)
		printf("%ld %d is thinking\n", ft_gettime(philo), philo->name);
}